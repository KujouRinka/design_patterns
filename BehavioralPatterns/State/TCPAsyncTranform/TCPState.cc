#include "TCPState.h"

TCPClosed *TCPClosed::_ins;
TCPListen *TCPListen::_ins;
TCPSynRevd *TCPSynRevd::_ins;
TCPSynSent *TCPSynSent::_ins;
TCPEstablished *TCPEstablished::_ins;
TCPFinWait1 *TCPFinWait1::_ins;
TCPFinWait2 *TCPFinWait2::_ins;
TCPClosing *TCPClosing::_ins;
TCPTimeWait *TCPTimeWait::_ins;
TCPCloseWait *TCPCloseWait::_ins;
TCPLastAck *TCPLastAck::_ins;

TCPConnection::TCPConnection(TCPState *init_state, CONN_TYPE type) {
    _state = init_state;
    _type = type;
}

void TCPConnection::listen(uint16_t port) {
    _state->listen(this, port);
}

void TCPConnection::sendSyn() {
    _state->sendSyn(this);
}

void TCPConnection::synReceived() {
    _state->synReceived(this);
}

void TCPConnection::synAndAckReceived() {
    _state->synAndAckReceived(this);
}

void TCPConnection::ackReceived() {
    _state->ackReceived(this);
}

void TCPConnection::rstReceived() {
    _state->rstReceived(this);
}

void TCPConnection::dataReceived(const char *data) {
    _state->dataReceived(this, data);
}

void TCPConnection::sendData(const char *data) {
    _state->sendData(this, data);
}

void TCPConnection::appDone() {
    _state->appDone(this);
}

void TCPConnection::finReceived() {
    _state->finReceived(this);
}

void TCPConnection::activeOpen(const char *remote_addr) {
    _state->activeOpen(this, remote_addr);
}

void TCPConnection::timeout() {
    _state->timeout(this);
}

void TCPConnection::sendFin() {
    _state->sendFin(this);
}

void TCPConnection::setState(TCPState *state) {
    _state = state;
}

void TCPState::rstReceived(TCPConnection *conn) {
    conn->setState(TCPClosed::instance());
}

void TCPState::setState(TCPConnection *conn, TCPState *state) {
    conn->setState(state);
}

TCPState *TCPClosed::instance() {
    if (_ins == nullptr)
        _ins = new TCPClosed;
    return _ins;
}

void TCPClosed::activeOpen(TCPConnection *conn, const char *remote_addr) {
    // connect to remote addr
    setState(conn, TCPSynSent::instance());
    // waiting from server
    // if timeout, async call conn->timeout()
    // if app close, async call conn->appDone()
    // if SYN, async call conn->synReceived()
    // if SYN + ACK, async call conn->synAndAckReceived()
}

void TCPClosed::listen(TCPConnection *conn, uint16_t port) {
    // open port
    setState(conn, TCPListen::instance());
}

TCPState *TCPListen::instance() {
    if (_ins == nullptr)
        _ins = new TCPListen;
    return _ins;
}

void TCPListen::synReceived(TCPConnection *conn) {
    // send back SYN and ACK
    setState(conn, TCPListen::instance());
    TCPConnection *new_conn = new TCPConnection(TCPSynRevd::instance(), SERVER);
    // waiting for client data
    // if RST, async call new_conn->rstReceived()
    // if ACK, async call new_conn->ackReceived()
    // if app close connection, async new_call conn->appDone()
}

TCPState *TCPSynRevd::instance() {
    if (_ins == nullptr)
        _ins = new TCPSynRevd;
    return _ins;
}

void TCPSynRevd::rstReceived(TCPConnection *conn) {
    setState(conn, TCPClosed::instance());
    delete conn;
}

void TCPSynRevd::ackReceived(TCPConnection *conn) {
    setState(conn, TCPEstablished::instance());
    // async call conn->sendData()
    // async call conn->dataReceived()
}

void TCPSynRevd::appDone(TCPConnection *conn) {
    // send package with FIN set
    setState(conn, TCPFinWait1::instance());
    // if FIN received, async call conn->finReceived()
}

void TCPSynRevd::timeout(TCPConnection *conn) {
    setState(conn, TCPListen::instance());
    // do something
}

TCPState *TCPSynSent::instance() {
    if (_ins == nullptr)
        _ins = new TCPSynSent;
    return _ins;
}

void TCPSynSent::appDone(TCPConnection *conn) {
    // send package with FIN set
    setState(conn, TCPClosed::instance());
    delete conn;
}

void TCPSynSent::timeout(TCPConnection *conn) {
    setState(conn, TCPClosed::instance());
    // do something
}

void TCPSynSent::synReceived(TCPConnection *conn) {
    // resend back SYN and ACK
    setState(conn, TCPSynRevd::instance());
    // waiting for client data
    // if RST, async call new_conn->rstReceived()
    // if ACK, async call new_conn->ackReceived()
    // if app close connection, async new_call conn->appDone()
}

void TCPSynSent::synAndAckReceived(TCPConnection *conn) {
    setState(conn, TCPEstablished::instance());
    // async call conn->sendData()
    // async call conn->dataReceived()
}

TCPState *TCPEstablished::instance() {
    if (_ins == nullptr)
        _ins = new TCPEstablished;
    return _ins;
}

void TCPEstablished::rstReceived(TCPConnection *conn) {
    setState(conn, TCPClosed::instance());
    delete conn;
}

void TCPEstablished::dataReceived(TCPConnection *conn, const char *data) {
    // check data from lower layer
    // if RST, async conn->rstReceived()
    // if normal data, async call conn->dateReceived()
    // if FIN, async call conn->finReceived()
}

void TCPEstablished::sendData(TCPConnection *conn, const char *data) {
    // check data from upper layer
    // if normal data, async call conn->sendData()
    // if app close, async call conn->appDone()
}

void TCPEstablished::appDone(TCPConnection *conn) {
    // send package to lower layer with FIN set
    setState(conn, TCPFinWait1::instance());
    // waiting for data
    // if FIN, async call conn->finReceived()
    // if ACK, async call conn->ackReceived()
}

void TCPEstablished::finReceived(TCPConnection *conn) {
    // send package to lower with ACK
    // notify upper
    setState(conn, TCPCloseWait::instance());
    // waiting data from upper
    // if app close, async call conn->appDone()
}

TCPState *TCPFinWait1::instance() {
    if (_ins == nullptr)
        _ins = new TCPFinWait1;
    return _ins;
}

void TCPFinWait1::finReceived(TCPConnection *conn) {
    setState(conn, TCPClosing::instance());
    // waiting for ACK, async call conn->ackReceived()
}

void TCPFinWait1::ackReceived(TCPConnection *conn) {
    setState(conn, TCPFinWait2::instance());
    // waiting for FIN, async call conn->finReceived()
}

TCPState *TCPFinWait2::instance() {
    if (_ins == nullptr)
        _ins = new TCPFinWait2;
    return _ins;
}

void TCPFinWait2::finReceived(TCPConnection *conn) {
    setState(conn, TCPTimeWait::instance());
    // set a timer for RTT * 2
    // if time triggered, async call conn->timeout()
}

TCPState *TCPClosing::instance() {
    if (_ins == nullptr)
        _ins = new TCPClosing;
    return _ins;
}

void TCPClosing::ackReceived(TCPConnection *conn) {
    setState(conn, TCPTimeWait::instance());
    // set a timer for RTT * 2
    // if timer triggered, async call conn->timeout()
}

TCPState *TCPTimeWait::instance() {
    if (_ins == nullptr) {
        _ins = new TCPTimeWait;
    }
    return _ins;
}

void TCPTimeWait::timeout(TCPConnection *conn) {
    setState(conn, TCPClosed::instance());
    delete conn;
}

TCPState *TCPCloseWait::instance() {
    if (_ins == nullptr)
        _ins = new TCPCloseWait;
    return _ins;
}

void TCPCloseWait::appDone(TCPConnection *conn) {
    // send FIN to lower
    setState(conn, TCPLastAck::instance());
    // waiting for ACK, async call conn->ackReceived()
}

TCPState *TCPLastAck::instance() {
    if (_ins == nullptr)
        _ins = new TCPLastAck;
    return _ins;
}

void TCPLastAck::ackReceived(TCPConnection *conn) {
    // close connection
    setState(conn, TCPClosed::instance());
    delete conn;
}