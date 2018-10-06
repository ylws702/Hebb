#pragma once
#include <cmath>
class Node
{
public:
    //connectionCount: �ڵ�������������
    //alpha: ѧϰ�ٶ�
    Node(unsigned connectionCount, float alpha);
    ~Node();
    //ѵ���ڵ�
    //inputs: ��������,Ԫ�ظ���Ϊ�ڵ�������������(this->connectionCount)
    //output: ���
    void Train(float* inputs, float output);
    //��ȡ���
    //inputs: ��������,Ԫ�ظ���Ϊ�ڵ�������������(this->connectionCount)
    //����ֵ: ���ֵ
    float GetOutput(float *inputs)const;
private:
    //����Ȩ������ָ��
    float *weights;
    //�ڵ�������������
    unsigned connectionCount;
    //ѧϰ�ٶ�
    float alpha;
};

