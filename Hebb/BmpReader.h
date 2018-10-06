#pragma once
#include <fstream>
#include "BitmapHeader.h"

class BmpReader
{
public:
    BmpReader(const char *bmppath);
    ~BmpReader();
    unsigned count;
    double Get(int i)const;
    BITMAPHEADER GetHeader()const;
private:
    unsigned length;
    char* content;
    BITMAPHEADER header;
};

