#ifndef HANDLER_H
#define HANDLER_H

class Handler {
public:
    virtual void handleRequest();
    virtual void setHandler(Handler *h);

protected:
    Handler(Handler *h);

    Handler *_successor;
};

class Background : public Handler {
public:
    Background();

    void handleRequest() override;
};

class ConcreteHandler : public Handler {
public:
    ConcreteHandler(Handler *h);

    void handleRequest() override;
    void concreteHandle();
};

class ConcreteHandler2 : public Handler {
public:
    ConcreteHandler2(Handler *h);

    void handleRequest() override;
    void concreteHandle();
};

#endif
