#include "Builder.h"

typedef _someType someType;
typedef _someType2 someType2;

void creator(Builder &builder) {
    builder.buildComp1();
    builder.buildComp2();
    builder.buildComp3();
    // ...
}

void example() {
    ConcreteBuilder1 builder;
    creator(builder);
    someType *product = builder.getObj();

    ConcreteBuilder2 builder2;
    creator(builder2);
    someType2 *product2 = builder2.getObj();
    // ...
}
