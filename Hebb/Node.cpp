#include "pch.h"
#include "Node.h"


Node::Node(unsigned connectionCount, double alpha)
    :connectionCount(connectionCount), alpha(alpha)
{
    this->weights = new double[connectionCount];
    for (unsigned i = 0; i < connectionCount; i++)
    {
        this->weights[i] = 0.0;
    }
}


Node::~Node()
{
    delete[] this->weights;
}


void Node::Train(double* inputs, double output)
{
    for (unsigned i = 0; i < this->connectionCount; i++)
    {
        weights[i] += alpha * inputs[i] * output;
    }
}

double Node::GetOutput(double *inputs) const
{
    double sum = 0.0;
    for (unsigned i = 0; i < this->connectionCount; i++)
    {
        sum += inputs[i] * this->weights[i];
    }
    return sum > 0.0 ? 1.0 : -1.0;
}
