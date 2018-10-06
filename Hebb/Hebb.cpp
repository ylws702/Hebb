// Hebb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "BmpReader.h"
#include "BmpWriter.h"
#include "Net.h"
#include <iostream>

int main()
{
    BmpReader *bmp1 = new BmpReader("1.bmp");
    BITMAPHEADER header = bmp1->GetHeader();
    unsigned headerRestCount=bmp1->headerRestCount;
    char *headerRest = new char[headerRestCount];
    std::memcpy(headerRest, bmp1->headerRest, headerRestCount);
    unsigned count = bmp1->actualBitCount;
    float *inputs1 = new float[count];
    for (unsigned i = 0; i < count; i++)
    {
        inputs1[i] = bmp1->Get(i);
    }
    Net net(count, 0.05f);
    net.Train(inputs1, inputs1,0.05f);
    delete bmp1;
    bmp1 = nullptr;

    BmpReader *bmp2 = new BmpReader("2.bmp");
    if (count != bmp2->actualBitCount||std::memcmp(headerRest,bmp2->headerRest,headerRestCount)!=0)
    {
        return -1;
    }
    float *inputs2 = new float[count];
    for (unsigned i = 0; i < count; i++)
    {
        inputs2[i] = bmp2->Get(i);
    }
    net.Train(inputs2, inputs2, 0.05f);
    delete bmp2;
    bmp2 = nullptr;

    BmpReader *bmp3 = new BmpReader("3.bmp");
    if (count!=bmp3->actualBitCount || std::memcmp(headerRest, bmp3->headerRest, headerRestCount) != 0)
    {
        return -1;
    }
    float *inputs3 = new float[count];
    for (unsigned i = 0; i < count; i++)
    {
        inputs3[i] = bmp3->Get(i);
    }
    net.Train(inputs3, inputs3, 0.05f);
    delete bmp3;
    bmp3 = nullptr;

    float *outputs1 = new float[count];
    net.GetOutputs(inputs1, outputs1);
    BmpWriter *output1 = new BmpWriter(count, outputs1, header, headerRest, headerRestCount);
    delete outputs1;
    outputs1 = nullptr;
    output1->Write("output1.bmp");
    delete output1;
    output1 = nullptr;

    float *outputs2 = new float[count];
    net.GetOutputs(inputs2, outputs2);
    BmpWriter *output2 = new BmpWriter(count, outputs2, header, headerRest, headerRestCount);
    delete outputs2;
    outputs2 = nullptr;
    output2->Write("output2.bmp");
    delete output2;
    output2 = nullptr;

    float *outputs3 = new float[count];
    net.GetOutputs(inputs3, outputs3);
    BmpWriter *output3 = new BmpWriter(count, outputs3, header, headerRest, headerRestCount);
    delete outputs3;
    outputs3 = nullptr;
    output3->Write("output3.bmp");
    delete output3;
    output3 = nullptr;


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

    float *outputs4 = new float[count];
    net.GetOutputs(inputs4, outputs4);
    BmpWriter *output4 = new BmpWriter(count, outputs4, header, headerRest, headerRestCount);
    delete outputs4;
    outputs4 = nullptr;
    output4->Write("output4.bmp");
    delete output4;
    output4 = nullptr;

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
