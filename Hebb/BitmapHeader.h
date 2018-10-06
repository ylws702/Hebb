#pragma once
struct WORD
{
    unsigned char bytes[2];
    WORD() {}
    WORD(unsigned n)
    {
        bytes[0] = n % 0x100;
        n >>= 8;
        bytes[1] = n % 0x100;
    }
    operator unsigned()const
    {
        return (bytes[1] << 8) ^ bytes[0];
    }
};
struct DWORD
{
    unsigned char bytes[4];
    DWORD() {}
    DWORD(unsigned n)
    {
        bytes[0] = n % 0x100;
        n >>= 8;
        bytes[1] = n % 0x100;
        n >>= 8;
        bytes[2] = n % 0x100;
        n >>= 8;
        bytes[3] = n % 0x100;
    }
    operator unsigned()const
    {
        return (((((bytes[3] << 8) ^ bytes[2]) << 8) ^ bytes[1]) << 8) ^ bytes[0];
    }
};
struct LONG
{
    unsigned char bytes[4];
    LONG() {}
    LONG(int n)
    {
        bytes[0] = n % 0x100;
        n >>= 8;
        bytes[1] = n % 0x100;
        n >>= 8;
        bytes[2] = n % 0x100;
        n >>= 8;
        bytes[3] = n % 0x100;
    }
    operator  int()const
    {
        return (((((bytes[3] << 8) ^ bytes[2]) << 8) ^ bytes[1]) << 8) ^ bytes[0];
    }
};
typedef unsigned char BYTE;
//位图文件头
typedef struct tagBITMAPFILEHEADER
{
    //文件标识
    WORD  bfType;
    //整个文件的大小
    DWORD bfSize;
    //保留，必须设置为0
    WORD  bfReserved1;
    //保留，必须设置为0
    WORD  bfReserved2;
    //从文件开始到位图数据开始之间的数据之间的偏移量
    DWORD bfOffBits;
} BITMAPFILEHEADER;
//位图信息头
typedef struct tagBITMAPINFOHEADER
{
    //位图信息头的长度
    DWORD biSize;
    //位图的宽度，以像素为单位
    LONG  biWidth;
    //位图的高度，以像素为单位
    LONG  biHeight;
    //位图的位面数，该值总是1
    WORD  biPlanes;
    //每个像素的位数。
    WORD  biBitCount;
    //压缩说明
    DWORD biCompression;
    //用字节数表示的位图数据的大小。该数必须是4 的倍数
    DWORD biSizeImage;
    //用像素/米表示的水平分辨率
    LONG  biXPelsPerMeter;
    //用像素/米表示的垂直分辨率
    LONG  biYPelsPerMeter;
    //位图使用的颜色数。
    DWORD biClrUsed;
    //指定重要的颜色数。当该域的值等于颜色数时（或者等于0时），表示所有颜色都一样重要
    DWORD biClrImportant;
} BITMAPINFOHEADER;
//彩色表
typedef struct tagRGBQUAD
{
    //蓝色分量
    BYTE rgbBlue;
    //绿色分量
    BYTE rgbGreen;
    //红色分量
    BYTE rgbRed;
    //填充符(设置为0)
    BYTE rgbReserved;
} RGBQUAD;
typedef struct tagBITMAPHEADER
{
    //位图文件头
    BITMAPFILEHEADER fileHeader;
    //位图信息头
    BITMAPINFOHEADER infoHeader;
    //彩色表
    RGBQUAD rgbQuad;
} BITMAPHEADER;
