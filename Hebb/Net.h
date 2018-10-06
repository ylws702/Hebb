#pragma once
#include "Node.h"
class Net
{
public:
    Net();
    Net(unsigned nodeCount,double alpha);
    void Train(double *inputs, double *outputs);
    void GetOutputs(double *inputs,double *outputs)const;
    ~Net();
private:
    unsigned nodeCount;
    Node** nodes;
};

