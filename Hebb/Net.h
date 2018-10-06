#pragma once
#include "Node.h"
class Net
{
public:
    Net();
    //nodeCount: �ڵ���
    //alpha: ѧϰ�ٶ�
    Net(unsigned nodeCount,float alpha);
    //ѵ��
    //inputs: ��������,Ԫ�ظ���Ϊ�ڵ����(this->nodeCount)
    //outputs: �������,Ԫ�ظ���Ϊ�ڵ����(this->nodeCount)
    void Train(float *inputs, float *outputs);
    //��ȡ���
    //inputs: ��������,Ԫ�ظ���Ϊ�ڵ����(this->nodeCount)
    //outputs: ������,Ԫ�ظ���Ϊ�ڵ����(this->nodeCount)
    void GetOutputs(float *inputs,float *outputs)const;
    ~Net();
private:
    //�ڵ���
    unsigned nodeCount;
    //ָ��ڵ�ָ�������ָ��
    Node** nodes;
};

