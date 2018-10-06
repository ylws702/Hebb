#include "pch.h"
#include "BmpWriter.h"

BmpWriter::BmpWriter(float *bits, unsigned actualBitCount, const BITMAPHEADER& header, char *headerRest, unsigned headerRestCount)
{
    this->header = header;
    this->headerRestCount = headerRestCount;
    this->headerRest = new char[this->headerRestCount];
    std::memcpy(this->headerRest, headerRest, this->headerRestCount);
    unsigned size = this->header.fileHeader.bfSize;
    unsigned offset = this->header.fileHeader.bfOffBits;
    this->byteCount = size - offset;
    if (actualBitCount > this->byteCount * 8)
    {
        throw std::exception("Too many bits.");
    }
    this->byteContent = new char[this->byteCount];
    std::memset(this->byteContent, 0, this->byteCount);
    //每行实际存储图像数据的比特数
    unsigned actualRowBitCount = (int)header.infoHeader.biWidth*(unsigned)header.infoHeader.biBitCount;
    //填0对齐4字节后每行图像数据的比特数
    unsigned rowBitCount = (actualRowBitCount + 31) >> 5 << 5;
    //写入计数变量
    unsigned readCount = 0;
    //填0对齐4字节后图像数据的比特数
    unsigned bitCount = rowBitCount * (int)header.infoHeader.biHeight;
    for (unsigned i = 0; i < bitCount; i++)
    {
        if (i%rowBitCount == actualRowBitCount)
        {
            //不小于i的最小rowBits的倍数再-1
            i = (i + rowBitCount - 1) / rowBitCount * rowBitCount - 1;
            continue;
        }
        this->byteContent[i >> 3] ^= (bits[readCount++] > 0.0f ? 1 : 0) << (7 - i % 8);
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
        throw std::exception("open file failed.");
    }
    ofs.write((char*)&this->header, sizeof(this->header));
    ofs.write(this->headerRest, this->headerRestCount);
    ofs.write(this->byteContent, this->byteCount);
    ofs.close();
}
