#include "pch.h"
#include "BmpWriter.h"

BmpWriter::BmpWriter(unsigned bitCount, double *bits, const BITMAPHEADER& header, char *headerRest ,unsigned headerRestCount)
{
    this->header = header;
    this->headerRestCount = headerRestCount;
    this->headerRest = new char[this->headerRestCount];
    std::memcpy(this->headerRest, headerRest, this->headerRestCount);
    unsigned size = this->header.fileHeader.bfSize;
    unsigned offset = this->header.fileHeader.bfOffBits;
    this->byteCount = size - offset;
    this->byteContent = new char[this->byteCount];
    for (unsigned i = 0; i < this->byteCount; i++)
    {
        unsigned char byte = 0;
        int startBit = i << 3;
        for (unsigned j = 7; j > 0; j--)
        {
            byte ^= (bits[startBit + j] > 0.0 ? 1 : 0);
            byte <<= 1;
        }
        byte ^= (bits[startBit] > 0.0 ? 1 : 0);
        this->byteContent[i] = byte;
    }
}

BmpWriter::~BmpWriter()
{
    delete[] this->byteContent;
    delete[] this->headerRest;
}

void BmpWriter::Write(const char * bmpPath) const
{
    std::ofstream ofs(bmpPath, std::ofstream::binary);
    if (ofs.fail())
    {
        return;
    }
    ofs.write((char*)&this->header, sizeof(this->header));
    ofs.write(this->headerRest, this->headerRestCount);
    ofs.write(this->byteContent, this->byteCount);
    ofs.close();
}
