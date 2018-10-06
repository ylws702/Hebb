#pragma once
#include "Node.h"
class Net
{
public:
    Net();
    Net(unsigned nodeCount,float alpha);
    void Train(float *inputs, float *outputs,float alpha);
    void GetOutputs(float *inputs,float *outputs)const;
    ~Net();
private:
    unsigned nodeCount;
    Node** nodes;
};

