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
typedef struct tagBITMAPFILEHEADER
{
    WORD  bfType;
    DWORD bfSize;
    WORD  bfReserved1;
    WORD  bfReserved2;
    DWORD bfOffBits;
} BITMAPFILEHEADER;
typedef struct tagBITMAPINFOHEADER
{
    DWORD biSize;
    LONG  biWidth;
    LONG  biHeight;
    WORD  biPlanes;
    WORD  biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG  biXPelsPerMeter;
    LONG  biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER;
typedef struct tagRGBQUAD
{
    BYTE    rgbBlue;
    BYTE    rgbGreen;
    BYTE    rgbRed;
    BYTE    rgbReserved;
} RGBQUAD;
typedef struct tagBITMAPHEADER
{
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    RGBQUAD rgbQuad;
} BITMAPHEADER;
