#ifndef DATA_STRUCTURES_AND_ALGORITHM_ADAPTERCOMP_H
#define DATA_STRUCTURES_AND_ALGORITHM_ADAPTERCOMP_H

#include "../Target.h"
#include "../Adaptee.h"

class AdapterComp : public Target {
public:
    AdapterComp(Adaptee *a) : _a(a) {}
    void request1() override;
    void request2() override;

private:
    Adaptee *_a;
};


#endif //DATA_STRUCTURES_AND_ALGORITHM_ADAPTERCOMP_H
