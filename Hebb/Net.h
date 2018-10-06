#pragma once
#include "Node.h"
class Net
{
public:
    Net();
    //nodeCount: 节点数
    //alpha: 学习速度
    Net(unsigned nodeCount,float alpha);
    //训练
    //inputs: 输入数组,元素个数为节点个数(this->nodeCount)
    //outputs: 输出数组,元素个数为节点个数(this->nodeCount)
    void Train(float *inputs, float *outputs);
    //获取输出
    //inputs: 输入数组,元素个数为节点个数(this->nodeCount)
    //outputs: 存放输出,元素个数为节点个数(this->nodeCount)
    void GetOutputs(float *inputs,float *outputs)const;
    ~Net();
private:
    //节点数
    unsigned nodeCount;
    //指向节点指针数组的指针
    Node** nodes;
};

