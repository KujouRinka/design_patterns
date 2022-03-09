#include "Impl.h"

void ConcreteImpl::implInterface() {

}
Impl *ConcreteImpl::Instance() {
    return new ConcreteImpl;
}
