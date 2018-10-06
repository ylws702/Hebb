#include "pch.h"
#include "BmpWriter.h"

BmpWriter::BmpWriter(unsigned count, double *blocks, const BITMAPHEADER& header)
{
    this->header = header;
    unsigned size = this->header.fileHeader.bfSize;
    unsigned offset = this->header.fileHeader.bfOffBits;
    this->length = size - offset;
    this->content = new char[this->length];
    if (count * 4 > this->length)
    {
        count = this->length / 4;
    }
    double value;
    unsigned char *bytes;
    int n;
    for (unsigned i = 0; i < count; i++)
    {
        value = blocks[i] * 0xFFFFFFFFU;
        bytes = (unsigned char*)(this->content + 4 * i);
        if (value >= 0xFFFFFFFFU)
        {
            bytes[0] = bytes[1] = bytes[2] = bytes[3] = 0xFFU;
            continue;
        }
        n = (int)value;
        bytes[0] = n % 0x100;
        n >>= 8;
        bytes[1] = n % 0x100;
        n >>= 8;
        bytes[2] = n % 0x100;
        n >>= 8;
        bytes[3] = n % 0x100;
    }
}

BmpWriter::~BmpWriter()
{
    delete[] this->content;
}

void BmpWriter::Write(const char * bmpPath) const
{
    std::ofstream ofs(bmpPath, std::ofstream::binary);
    if (ofs.fail())
    {
        return;
    }
    ofs.write((char*)&this->header, sizeof(this->header));
    unsigned offset = this->header.fileHeader.bfOffBits;
    ofs.seekp(offset, std::ofstream::beg);
    ofs.write(this->content, this->length);
    ofs.close();
}
