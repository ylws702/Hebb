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
//λͼ�ļ�ͷ
typedef struct tagBITMAPFILEHEADER
{
    //�ļ���ʶ
    WORD  bfType;
    //�����ļ��Ĵ�С
    DWORD bfSize;
    //��������������Ϊ0
    WORD  bfReserved1;
    //��������������Ϊ0
    WORD  bfReserved2;
    //���ļ���ʼ��λͼ���ݿ�ʼ֮�������֮���ƫ����
    DWORD bfOffBits;
} BITMAPFILEHEADER;
//λͼ��Ϣͷ
typedef struct tagBITMAPINFOHEADER
{
    //λͼ��Ϣͷ�ĳ���
    DWORD biSize;
    //λͼ�Ŀ�ȣ�������Ϊ��λ
    LONG  biWidth;
    //λͼ�ĸ߶ȣ�������Ϊ��λ
    LONG  biHeight;
    //λͼ��λ��������ֵ����1
    WORD  biPlanes;
    //ÿ�����ص�λ����
    WORD  biBitCount;
    //ѹ��˵��
    DWORD biCompression;
    //���ֽ�����ʾ��λͼ���ݵĴ�С������������4 �ı���
    DWORD biSizeImage;
    //������/�ױ�ʾ��ˮƽ�ֱ���
    LONG  biXPelsPerMeter;
    //������/�ױ�ʾ�Ĵ�ֱ�ֱ���
    LONG  biYPelsPerMeter;
    //λͼʹ�õ���ɫ����
    DWORD biClrUsed;
    //ָ����Ҫ����ɫ�����������ֵ������ɫ��ʱ�����ߵ���0ʱ������ʾ������ɫ��һ����Ҫ
    DWORD biClrImportant;
} BITMAPINFOHEADER;
//��ɫ��
typedef struct tagRGBQUAD
{
    //��ɫ����
    BYTE rgbBlue;
    //��ɫ����
    BYTE rgbGreen;
    //��ɫ����
    BYTE rgbRed;
    //����(����Ϊ0)
    BYTE rgbReserved;
} RGBQUAD;
typedef struct tagBITMAPHEADER
{
    //λͼ�ļ�ͷ
    BITMAPFILEHEADER fileHeader;
    //λͼ��Ϣͷ
    BITMAPINFOHEADER infoHeader;
    //��ɫ��
    RGBQUAD rgbQuad;
} BITMAPHEADER;
