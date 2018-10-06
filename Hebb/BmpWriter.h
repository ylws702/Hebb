#pragma once
#include <fstream>
#include "BitmapHeader.h"

class BmpWriter
{
public:
    //blocks: 保存每个像素的值
    //count: blocks元素个数
    //header: bmp头
    //headerRest: bmp头与图像信息间的数据
    //headerRestCount: headerRest元素个数
    BmpWriter( float *blocks, unsigned count, const BITMAPHEADER& header, char *headerRest, unsigned headerRestCount);
    ~BmpWriter();
    //写入bmp
    //bmpPath: 文件路径
    void Write(const char *bmpPath)const;
private:
    //headerRest元素个数
    unsigned headerRestCount;
    //bmp头与图像信息间的数据
    char *headerRest;
    //bmp头
    BITMAPHEADER header;
    //字节存储的图像信息
    char *byteContent;
    //byteContent元素个数
    unsigned byteCount;
};

