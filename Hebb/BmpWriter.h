#pragma once
#include <fstream>
#include "BitmapHeader.h"

class BmpWriter
{
public:
    //blocks: ����ÿ�����ص�ֵ
    //count: blocksԪ�ظ���
    //header: bmpͷ
    //headerRest: bmpͷ��ͼ����Ϣ�������
    //headerRestCount: headerRestԪ�ظ���
    BmpWriter( float *blocks, unsigned count, const BITMAPHEADER& header, char *headerRest, unsigned headerRestCount);
    ~BmpWriter();
    //д��bmp
    //bmpPath: �ļ�·��
    void Write(const char *bmpPath)const;
private:
    //headerRestԪ�ظ���
    unsigned headerRestCount;
    //bmpͷ��ͼ����Ϣ�������
    char *headerRest;
    //bmpͷ
    BITMAPHEADER header;
    //�ֽڴ洢��ͼ����Ϣ
    char *byteContent;
    //byteContentԪ�ظ���
    unsigned byteCount;
};

