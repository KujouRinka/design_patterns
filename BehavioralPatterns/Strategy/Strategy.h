#ifndef DATA_STRUCTURES_AND_ALGORITHM_STRATEGY_H
#define DATA_STRUCTURES_AND_ALGORITHM_STRATEGY_H

class Strategy;

class Context {
public:
    Context(Strategy *strategy) : _strategy(strategy) {};

    void doSomething();
    void changeMethod(Strategy *strategy);

private:
    Strategy *_strategy;
};

class Strategy {
public:
    virtual void AlgorithmInterface(Context *ctx);
};

class ConcreteStrategy1 : public Strategy {
public:
    void AlgorithmInterface(Context *ctx) override;
};

class ConcreteStrategy2 : public Strategy {
public:
    void AlgorithmInterface(Context *ctx) override;
};


#endif //DATA_STRUCTURES_AND_ALGORITHM_STRATEGY_H
