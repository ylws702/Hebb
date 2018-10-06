#include "pch.h"
#include "Node.h"


Node::Node(unsigned connectionCount, double alpha)
    :connectionCount(connectionCount), alpha(alpha)
{
    this->weights = new double[connectionCount];
    for (unsigned i = 0; i < connectionCount; i++)
    {
        this->weights[i] = 1/connectionCount;
    }
}


Node::~Node()
{
    delete[] this->weights;
}


void Node::Train(double* inputs, double output)
{
    double net = 0.0;
    for (unsigned i = 0; i < this->connectionCount; i++)
    {
        net += weights[i] * inputs[i];
    }
    net *= alpha;
    double delta = alpha * this->F(net);
    for (unsigned i = 0; i < this->connectionCount; i++)
    {
        weights[i] += delta * inputs[i];
    }
}

double Node::GetOutput(double *inputs) const
{
    double sum = 0;
    for (unsigned i = 0; i < this->connectionCount; i++)
    {
        sum += inputs[i] * this->weights[i];
    }
    return sum / connectionCount / alpha;
}

int Node::F(double alpha) const
{
    if (alpha > 0)
    {
        return 1;
    }
    if (alpha < 0)
    {
        return -1;
    }
    return 0;
}
