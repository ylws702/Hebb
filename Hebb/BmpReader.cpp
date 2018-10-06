#include "pch.h"
#include "BmpReader.h"


BmpReader::BmpReader(const char *bmppath)
{
    std::ifstream ifs(bmppath, std::ifstream::binary);
    if (ifs.fail())
    {
        this->count = 1;
        this->length = 1;
        this->content = new char[1];
        return;
    }
    ifs.read((char*)&this->header, sizeof(this->header));
    unsigned size = this->header.fileHeader.bfSize;
    this->count = size / 4;
    unsigned offset = this->header.fileHeader.bfOffBits;
    this->length = size - offset;
    this->content = new char[this->length];
    ifs.seekg(offset, std::ifstream::beg);
    ifs.read(this->content, this->length);
    ifs.close();
}


BmpReader::~BmpReader()
{
    delete[] this->content;
}

double BmpReader::Get(int i)const
{
    if ((i + 1) * 4 > (int)this->length)
    {
        return 0.0;
    }
    unsigned char* bytes = (unsigned char*)(this->content + 4 * i);
    double value = ((((((bytes[3] << 8) ^ bytes[2]) << 8) ^ bytes[1]) << 8) ^ bytes[0]);
    return value/0xFFFFFFFFU;
}

BITMAPHEADER BmpReader::GetHeader() const
{
    return this->header;
}