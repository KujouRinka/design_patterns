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

void TCPConnection::sendData(char *data) {
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
    setState(conn, TCPSynRevd::instance());
}

TCPState *TCPSynRevd::instance() {
    if (_ins == nullptr)
        _ins = new TCPSynRevd;
    return _ins;
}

void TCPSynRevd::rstReceived(TCPConnection *conn) {
    setState(conn, TCPListen::instance());
}

void TCPSynRevd::ackReceived(TCPConnection *conn) {
    setState(conn, TCPEstablished::instance());
}

void TCPSynRevd::appDone(TCPConnection *conn) {
    // send package with FIN set
    setState(conn, TCPFinWait1::instance());
}

void TCPSynRevd::timeout(TCPConnection *conn) {
    setState(conn, TCPListen::instance());
}

TCPState *TCPSynSent::instance() {
    if (_ins == nullptr)
        _ins = new TCPSynSent;
    return _ins;
}

void TCPSynSent::appDone(TCPConnection *conn) {
    // send package with FIN set
    setState(conn, TCPClosed::instance());
}

void TCPSynSent::timeout(TCPConnection *conn) {
    setState(conn, TCPClosed::instance());
}

void TCPSynSent::synReceived(TCPConnection *conn) {
    // resend back SYN and ACK
    setState(conn, TCPSynRevd::instance());
}

void TCPSynSent::synAndAckReceived(TCPConnection *conn) {
    setState(conn, TCPEstablished::instance());
}

TCPState *TCPEstablished::instance() {
    if (_ins == nullptr)
        _ins = new TCPEstablished;
    return _ins;
}

void TCPEstablished::rstReceived(TCPConnection *conn) {
    setState(conn, TCPClosed::instance());
}

void TCPEstablished::dataReceived(TCPConnection *conn, const char *data) {
    // send ACK
    // setState(conn, TCPEstablished::instance());
}

void TCPEstablished::sendData(TCPConnection *conn, char *data) {
    // send data
    // wait for ACK
    // if timeout, resend data for some times, if still not received, close connection
    // if ACK received, setState(TCPEstablished::instance());
    setState(conn, TCPEstablished::instance());
}

void TCPEstablished::appDone(TCPConnection *conn) {
    // send package with FIN set
    setState(conn, TCPFinWait1::instance());
}

void TCPEstablished::finReceived(TCPConnection *conn) {
    // send package with FIN set
    setState(conn, TCPCloseWait::instance());
}

TCPState *TCPFinWait1::instance() {
    if (_ins == nullptr)
        _ins = new TCPFinWait1;
    return _ins;
}

void TCPFinWait1::finReceived(TCPConnection *conn) {
    setState(conn, TCPClosing::instance());
}

void TCPFinWait1::ackReceived(TCPConnection *conn) {
    setState(conn, TCPFinWait2::instance());
}

TCPState *TCPFinWait2::instance() {
    if (_ins == nullptr)
        _ins = new TCPFinWait2;
    return _ins;
}

void TCPFinWait2::finReceived(TCPConnection *conn) {
    setState(conn, TCPTimeWait::instance());
}

TCPState *TCPClosing::instance() {
    if (_ins == nullptr)
        _ins = new TCPClosing;
    return _ins;
}

void TCPClosing::ackReceived(TCPConnection *conn) {
    // send FIN
    setState(conn, TCPTimeWait::instance());
}

TCPState *TCPTimeWait::instance() {
    if (_ins == nullptr) {
        _ins = new TCPTimeWait;
        // start a timer
    }
    return _ins;
}

void TCPTimeWait::timeout(TCPConnection *conn) {
    // if timeout, close connection
    setState(conn, TCPClosed::instance());
}

TCPState *TCPCloseWait::instance() {
    if (_ins == nullptr)
        _ins = new TCPCloseWait;
    return _ins;
}

void TCPCloseWait::appDone(TCPConnection *conn) {
    // send FIN
    setState(conn, TCPLastAck::instance());
}

TCPState *TCPLastAck::instance() {
    if (_ins == nullptr)
        _ins = new TCPLastAck;
    return _ins;
}

void TCPLastAck::ackReceived(TCPConnection *conn) {
    // close connection
    setState(conn, TCPClosed::instance());
}