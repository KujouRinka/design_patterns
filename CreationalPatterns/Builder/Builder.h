// Builder design pattern.
// Create product step by step.

#ifndef DATA_STRUCTURES_AND_ALGORITHM_BUILDER_H
#define DATA_STRUCTURES_AND_ALGORITHM_BUILDER_H

class Builder {
public:
    // note: all interfaces are not pure virtual
    virtual void buildComp1() {}
    virtual void buildComp2() {}
    virtual void buildComp3() {}
    // ...
};

class ConcreteBuilder1 : public Builder {
public:
    typedef someType product1_t;
    // just overwrite interface interested
    void buildComp1() override;
    void buildComp2() override;

    product1_t *getObj();

private:
    product1_t *_obj;
};

class ConcreteBuilder2 : public Builder {
public:
    typedef someType2 product2_t;
    void buildComp1() override;
    void buildComp2() override;
    void buildComp3() override;

    product2_t *getObj();

private:
    product2_t *_obj;
};


#endif //DATA_STRUCTURES_AND_ALGORITHM_BUILDER_H
