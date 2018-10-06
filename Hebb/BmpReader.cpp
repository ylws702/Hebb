#include "pch.h"
#include "BmpReader.h"


BmpReader::BmpReader(const char *bmppath)
{
    std::ifstream ifs(bmppath, std::ifstream::binary);
    if (ifs.fail())
    {
        this->byteCount = 1;
        this->bitCount = 1;
        this->bitContent = new char[1];
        this->headerRestCount = 1;
        this->headerRest = new char[1];
        return;
    }
    ifs.read((char*)&this->header, sizeof(this->header));
    unsigned size = this->header.fileHeader.bfSize;
    unsigned offset = this->header.fileHeader.bfOffBits;

    this->headerRestCount = offset - sizeof(this->header);
    this->headerRest = new char[this->headerRestCount];
    ifs.read(this->headerRest, this->headerRestCount);

    this->byteCount = size - offset;
    this->bitCount = this->byteCount * 8;
    char* byteContent = new char[this->byteCount];
    ifs.read(byteContent, this->byteCount);
    ifs.close();
    this->bitContent = new char[this->bitCount];
    for (unsigned i = 0; i < this->bitCount; i++)
    {
        unsigned char byte = byteContent[i >> 3];
        this->bitContent[i++] = byte & 1;
        this->bitContent[i++] = (byte >> 1) & 1;
        this->bitContent[i++] = (byte >> 1) & 1;
        this->bitContent[i++] = (byte >> 1) & 1;
        this->bitContent[i++] = (byte >> 1) & 1;
        this->bitContent[i++] = (byte >> 1) & 1;
        this->bitContent[i++] = (byte >> 1) & 1;
        this->bitContent[i] = (byte >> 1) & 1;
    }
    delete[] byteContent;
}


BmpReader::~BmpReader()
{
    delete[] this->bitContent;
    delete[] this->headerRest;
}

double BmpReader::Get(int i)const
{
    return this->bitContent[i] == 1 ? 1.0 : -1.0;
}

BITMAPHEADER BmpReader::GetHeader() const
{
    return this->header;
}