#include "pch.h"
#include "Node.h"


Node::Node(unsigned connectionCount, float alpha)
    :connectionCount(connectionCount), alpha(alpha)
{
    this->weights = new float[connectionCount];
    for (unsigned i = 0; i < connectionCount; i++)
    {
        this->weights[i] = 0.0;
    }
}


Node::~Node()
{
    delete[] this->weights;
}


void Node::Train(float* inputs, float output,float alpha)
{
    for (unsigned i = 0; i < this->connectionCount; i++)
    {
        weights[i] += alpha * inputs[i] * output;
    }
}

float Node::GetOutput(float *inputs) const
{
    float sum = 0.0f;
    for (unsigned i = 0; i < this->connectionCount; i++)
    {
        sum += inputs[i] * this->weights[i];
    }
    return sum > 0.0f ? 1.0f : -1.0f;
}
