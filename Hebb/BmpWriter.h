#pragma once
#include <fstream>
#include "BitmapHeader.h"

class BmpWriter
{
public:
    BmpWriter(unsigned count,double *blocks,const BITMAPHEADER& header);
    ~BmpWriter();
    void Write(const char *bmpPath)const;
private:
    BITMAPHEADER header;
    char *content;
    unsigned length;
};

