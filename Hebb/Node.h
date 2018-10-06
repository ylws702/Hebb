#pragma once
#include <cmath>
class Node
{
public:
    //connectionCount: 节点输入连接数量
    //alpha: 学习速度
    Node(unsigned connectionCount, float alpha);
    ~Node();
    //训练节点
    //inputs: 输入数组,元素个数为节点输入连接数量(this->connectionCount)
    //output: 输出
    void Train(float* inputs, float output);
    //获取输出
    //inputs: 输入数组,元素个数为节点输入连接数量(this->connectionCount)
    //返回值: 输出值
    float GetOutput(float *inputs)const;
private:
    //连接权重数组指针
    float *weights;
    //节点输入连接数量
    unsigned connectionCount;
    //学习速度
    float alpha;
};

