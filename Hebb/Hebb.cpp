// Hebb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "BmpReader.h"
#include "BmpWriter.h"
#include "Net.h"
#include <iostream>

int main()
{
    //读取1.bmp
    BmpReader *bmp1 = new BmpReader("1.bmp");
    //bmp头
    BITMAPHEADER header = bmp1->GetHeader();
    //headerRest元素个数
    unsigned headerRestCount = bmp1->headerRestCount;
    //bmp头与图像信息间的数据
    char *headerRest = new char[headerRestCount];
    //读取bmp1的bmp头与图像信息间的数据
    std::memcpy(headerRest, bmp1->headerRest, headerRestCount);
    //bmp1的实际像素
    unsigned count = bmp1->actualBitCount;
    //bmp1的像素数组
    float *inputs1 = new float[count];
    //读取bmp1的像素到数组
    for (unsigned i = 0; i < count; i++)
    {
        inputs1[i] = bmp1->Get(i);
    }
    //Hebb规则的神经网络,alpha=0.05
    Net net(count, 0.05f);
    //使用bmp1训练
    net.Train(inputs1, inputs1);
    //释放空间
    delete bmp1;
    bmp1 = nullptr;

    //bmp2的像素数组
    float *inputs2 = new float[count];
    //bmp3的像素数组
    float *inputs3 = new float[count];

    {
        //读取2.bmp
        BmpReader *bmp2 = new BmpReader("2.bmp");
        //验证bmp2格式与bmp1相同
        if (count != bmp2->actualBitCount || std::memcmp(headerRest, bmp2->headerRest, headerRestCount) != 0)
        {
            return -1;
        }
        //读取bmp2的像素到数组
        for (unsigned i = 0; i < count; i++)
        {
            inputs2[i] = bmp2->Get(i);
        }
        //使用bmp2训练
        net.Train(inputs2, inputs2);
        //释放空间
        delete bmp2;
    }
    {
        //读取3.bmp
        BmpReader *bmp3 = new BmpReader("3.bmp");
        //验证bmp3格式与bmp1相同
        if (count != bmp3->actualBitCount || std::memcmp(headerRest, bmp3->headerRest, headerRestCount) != 0)
        {
            return -1;
        }
        //读取bmp3的像素到数组
        for (unsigned i = 0; i < count; i++)
        {
            inputs3[i] = bmp3->Get(i);
        }
        //使用bmp3训练
        net.Train(inputs3, inputs3);
        //释放空间
        delete bmp3;
    }
    //输入1.bmp输出图像至output1.bmp
    {
        float *outputs1 = new float[count];
        net.GetOutputs(inputs1, outputs1);
        BmpWriter *output1 = new BmpWriter(outputs1, count, header, headerRest, headerRestCount);
        delete outputs1;
        output1->Write("output1.bmp");
        delete output1;
    }
    //输入2.bmp输出图像至output2.bmp
    {
        float *outputs2 = new float[count];
        net.GetOutputs(inputs2, outputs2);
        BmpWriter *output2 = new BmpWriter(outputs2, count, header, headerRest, headerRestCount);
        delete outputs2;
        output2->Write("output2.bmp");
        delete output2;
    }
    //输入3.bmp输出图像至output3.bmp
    {
        float *outputs3 = new float[count];
        net.GetOutputs(inputs3, outputs3);
        BmpWriter *output3 = new BmpWriter(outputs3, count, header, headerRest, headerRestCount);
        delete outputs3;
        output3->Write("output3.bmp");
        delete output3;
    }
    //读取test.bmp
    BmpReader *test1 = new BmpReader("test1.bmp");
    if (count != test1->actualBitCount || std::memcmp(headerRest, test1->headerRest, headerRestCount) != 0)
    {
        return -1;
    }
    float *inputs4 = new float[count];
    for (unsigned i = 0; i < count; i++)
    {
        inputs4[i] = test1->Get(i);
    }
    delete test1;
    test1 = nullptr;
    //输入test.bmp输出图像至output4.bmp
    float *outputs4 = new float[count];
    net.GetOutputs(inputs4, outputs4);
    BmpWriter *output4 = new BmpWriter(outputs4, count, header, headerRest, headerRestCount);
    delete outputs4;
    outputs4 = nullptr;
    output4->Write("output4.bmp");
    delete output4;
    output4 = nullptr;
    //释放空间
    delete[] headerRest;
    headerRest = nullptr;
    std::cout << "Completed!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
