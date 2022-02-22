#ifndef DATA_STRUCTURES_AND_ALGORITHM_SINGLETON_H
#define DATA_STRUCTURES_AND_ALGORITHM_SINGLETON_H

class Singleton {
public:
    static Singleton *Instance();

protected:
    Singleton() = default;

private:
    static Singleton *_instance;
};

#endif //DATA_STRUCTURES_AND_ALGORITHM_SINGLETON_H
