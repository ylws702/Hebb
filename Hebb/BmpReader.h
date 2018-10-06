#pragma once
#include <fstream>
#include "BitmapHeader.h"

class BmpReader
{
public:
    BmpReader(const char *bmppath);
    ~BmpReader();
    unsigned actualBitCount;
    unsigned byteCount;
    float Get(int i)const;
    BITMAPHEADER GetHeader()const;
    char* headerRest;
    unsigned headerRestCount;
private:
    char* bitContent;
    BITMAPHEADER header;
};

