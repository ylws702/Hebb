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
    unsigned count = bmp1->count;
    double *inputs = new double[count];
    for (unsigned i = 0; i < count; i++)
    {
        inputs[i] = bmp1->Get(i);
    }
    Net net(bmp1->count, 0.05);
    net.Train(inputs, inputs);
    delete bmp1;
    bmp1 = nullptr;
    BmpReader *bmp2 = new BmpReader("2.bmp");
    if (count != bmp2->count)
    {
        return -1;
    }
    for (unsigned i = 0; i < count; i++)
    {
        inputs[i] = bmp2->Get(i);
    }
    net.Train(inputs, inputs);
    delete bmp2;
    bmp2 = nullptr;
    BmpReader *bmp3 = new BmpReader("3.bmp");
    if (count!=bmp3->count)
    {
        return -1;
    }
    for (unsigned i = 0; i < count; i++)
    {
        inputs[i] = bmp3->Get(i);
    }
    net.Train(inputs, inputs);
    delete bmp3;
    bmp3 = nullptr;
    BmpReader *test1 = new BmpReader("1.bmp");
    if (count!=test1->count)
    {
        return -1;
    }
    for (unsigned i = 0; i < count; i++)
    {
        inputs[i] = test1->Get(i);
    }
    delete test1;
    test1 = nullptr;
    double *outputs = new double[count];
    net.GetOutputs(inputs, outputs);
    BmpWriter *output1 = new BmpWriter(count, outputs, header);
    output1->Write("output1.bmp");
    std::cout << "Hello World!\n";
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
