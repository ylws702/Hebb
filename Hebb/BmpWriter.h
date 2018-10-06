#pragma once
#include <fstream>
#include "BitmapHeader.h"

class BmpWriter
{
public:
    BmpWriter(unsigned count, double *blocks, const BITMAPHEADER& header, char *headerRest, unsigned headerRestCount);
    ~BmpWriter();
    void Write(const char *bmpPath)const;
private:
    unsigned headerRestCount;
    char *headerRest;
    BITMAPHEADER header;
    char *byteContent;
    unsigned byteCount;
};

