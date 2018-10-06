#pragma once
#include <cmath>
class Node
{
public:
    Node(unsigned connectionCount, double alpha);
    ~Node();
    void Train(double* inputs, double output);
    double GetOutput(double *inputs)const;
private:
    double *weights;
    unsigned connectionCount;
    double alpha;
};

