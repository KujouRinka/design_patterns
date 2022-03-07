#ifndef DATA_STRUCTURES_AND_ALGORITHM_ADAPTERINHER_H
#define DATA_STRUCTURES_AND_ALGORITHM_ADAPTERINHER_H

#include "../Target.h"
#include "../Adaptee.h"

class AdapterInher : public Target, private ConcreteAdaptee {
public:
    AdapterInher();

    void request1() override;
    void request2() override;
};


#endif //DATA_STRUCTURES_AND_ALGORITHM_ADAPTERINHER_H
