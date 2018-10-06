#include "pch.h"
#include "Net.h"

Net::Net() :nodeCount(1)
{
    this->nodes = new Node*[nodeCount];
    this->nodes[0] = new Node(nodeCount, 1);
}

Net::Net(unsigned nodeCount, float alpha)
    :nodeCount(nodeCount)
{
    this->nodes = new Node*[nodeCount];
    for (unsigned i = 0; i < this->nodeCount; i++)
    {
        this->nodes[i] = new Node(nodeCount, alpha);
    }
}

void Net::Train(float *inputs, float *outputs, float alpha)
{
    for (unsigned i = 0; i < this->nodeCount; i++)
    {
        this->nodes[i]->Train(inputs, outputs[i], alpha);
    }
}

void Net::GetOutputs(float *inputs, float *outputs) const
{
    for (unsigned i = 0; i < this->nodeCount; i++)
    {
        outputs[i] = this->nodes[i]->GetOutput(inputs);
    }
}

Net::~Net()
{
    for (unsigned i = 0; i < this->nodeCount; i++)
    {
        delete nodes[i];
    }
    delete[] nodes;
}
