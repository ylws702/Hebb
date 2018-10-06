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

void Net::Train(float *inputs, float *outputs)
{
    //依次训练每个节点
    for (unsigned i = 0; i < this->nodeCount; i++)
    {
        this->nodes[i]->Train(inputs, outputs[i]);
    }
}

void Net::GetOutputs(float *inputs, float *outputs) const
{
    //获取每个节点的输出
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
