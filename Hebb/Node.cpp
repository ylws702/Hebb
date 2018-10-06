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
    double squareNorm = 0.0;
    for (unsigned i = 0; i < this->connectionCount; i++)
    {
        weights[i] += alpha*inputs[i]*output;
        squareNorm += weights[i] * weights[i];
    }
    squareNorm = std::sqrt(squareNorm);
    if (squareNorm == 0.0)
    {
        return;
    }
    for (unsigned i = 0; i < this->connectionCount; i++)
    {
        weights[i] /= squareNorm;
    }
}

double Node::GetOutput(double *inputs) const
{
    double sum = 0;
    for (unsigned i = 0; i < this->connectionCount; i++)
    {
        sum += inputs[i] * this->weights[i];
    }
    return sum ;
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
