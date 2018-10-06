#pragma once
#include <fstream>
#include "BitmapHeader.h"

class BmpReader
{
public:
    BmpReader(const char *bmppath);
    ~BmpReader();
    unsigned bitCount;
    unsigned byteCount;
    double Get(int i)const;
    BITMAPHEADER GetHeader()const;
    char* headerRest;
    unsigned headerRestCount;
private:
    char* bitContent;
    BITMAPHEADER header;
};

