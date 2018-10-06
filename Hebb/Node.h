#pragma once
#include <cmath>
class Node
{
public:
    Node(unsigned connectionCount, float alpha);
    ~Node();
    void Train(float* inputs, float output, float alpha);
    float GetOutput(float *inputs)const;
private:
    float *weights;
    unsigned connectionCount;
    float alpha;
};

