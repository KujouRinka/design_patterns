#ifndef DATA_STRUCTURES_AND_ALGORITHM_TCPSTATE_H
#define DATA_STRUCTURES_AND_ALGORITHM_TCPSTATE_H

#include <stdint.h>

class TCPState;
class TCPConnection;
enum CONN_TYPE {
    SERVER = 0,
    CLIENT,
};

class TCPConnection {
    friend class TCPState;

public:
    TCPConnection(TCPState *init_state, CONN_TYPE type);

    void listen(uint16_t port);

    void sendSyn();
    void synReceived();
    void synAndAckReceived();
    void activeOpen(const char *remote_addr);

    void ackReceived();

    void timeout();
    void rstReceived();
    void sendFin();
    void finReceived();

    void dataReceived(const char *data);
    void sendData(char *data);

    void appDone();

private:
    TCPState *_state;
    CONN_TYPE _type;

    void setState(TCPState *state);
};


class TCPState {
public:
    virtual void listen(TCPConnection *conn, uint16_t port) {};

    virtual void sendSyn(TCPConnection *conn) {};
    virtual void synReceived(TCPConnection *conn) {};
    virtual void synAndAckReceived(TCPConnection *conn) {};
    virtual void activeOpen(TCPConnection *conn, const char *remote_addr) {};

    virtual void ackReceived(TCPConnection *conn) {};

    virtual void timeout(TCPConnection *conn) {};
    virtual void rstReceived(TCPConnection *conn);
    virtual void sendFin(TCPConnection *conn) {};
    virtual void finReceived(TCPConnection *conn) {};

    virtual void dataReceived(TCPConnection *conn, const char *data) {};
    virtual void sendData(TCPConnection *conn, char *data) {};

    virtual void appDone(TCPConnection *conn) {};

protected:
    static void setState(TCPConnection *conn, TCPState *state);
};

class TCPClosed : public TCPState {
public:
    static TCPState *instance();

    void activeOpen(TCPConnection *conn, const char *remote_addr) override;
    void listen(TCPConnection *conn, uint16_t port) override;

private:
    static TCPClosed *_ins;
};

class TCPListen : public TCPState {
public:
    static TCPState *instance();

    void synReceived(TCPConnection *conn) override;

private:
    static TCPListen *_ins;
};

class TCPSynRevd : public TCPState {
public:
    static TCPState *instance();

    void rstReceived(TCPConnection *conn) override;
    void ackReceived(TCPConnection *conn) override;
    void appDone(TCPConnection *conn) override;
    void timeout(TCPConnection *conn) override;

private:
    static TCPSynRevd *_ins;
};

class TCPSynSent : public TCPState {
public:
    static TCPState *instance();

    void appDone(TCPConnection *conn) override;
    void timeout(TCPConnection *conn) override;
    void synReceived(TCPConnection *conn) override;
    void synAndAckReceived(TCPConnection *conn) override;

private:
    static TCPSynSent *_ins;
};

class TCPEstablished : public TCPState {
public:
    static TCPState *instance();

    void rstReceived(TCPConnection *conn) override;
    void dataReceived(TCPConnection *conn, const char *data) override;
    void sendData(TCPConnection *conn, char *data) override;
    void appDone(TCPConnection *conn) override;
    void finReceived(TCPConnection *conn) override;

private:
    static TCPEstablished *_ins;
};

class TCPFinWait1 : public TCPState {
public:
    static TCPState *instance();

    void finReceived(TCPConnection *conn) override;
    void ackReceived(TCPConnection *conn) override;

private:
    static TCPFinWait1 *_ins;
};

class TCPFinWait2 : public TCPState {
public:
    static TCPState *instance();

    void finReceived(TCPConnection *conn) override;

private:
    static TCPFinWait2 *_ins;
};

class TCPClosing : public TCPState {
public:
    static TCPState *instance();

    void ackReceived(TCPConnection *conn) override;

private:
    static TCPClosing *_ins;
};

class TCPTimeWait : public TCPState {
public:
    static TCPState *instance();

    void timeout(TCPConnection *conn) override;

private:
    static TCPTimeWait *_ins;
    // Timer *timer;

};

class TCPCloseWait : public TCPState {
public:
    static TCPState *instance();

    void appDone(TCPConnection *conn) override;

private:
    static TCPCloseWait *_ins;
};

class TCPLastAck : public TCPState {
public:
    static TCPState *instance();

    void ackReceived(TCPConnection *conn) override;

private:
    static TCPLastAck *_ins;
};

#endif //DATA_STRUCTURES_AND_ALGORITHM_TCPSTATE_H
