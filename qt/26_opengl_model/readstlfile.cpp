#include "readstlfile.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <QDebug>
#include <QFile>

ReadStlFile::ReadStlFile()
{
}

bool ReadStlFile::ReadFile(const char *cfilename)
{
    std::FILE *pFile;
    long lSize;
    char* buffer;
    size_t result;

    fopen_s(&pFile, cfilename, "rb");
    if(pFile == NULL){

        qDebug() << "open file failed.";
        return false;
    }

    // get file size
    fseek(pFile, 0, SEEK_END);
    lSize = ftell(pFile);
    rewind(pFile);

    buffer = (char*)malloc(sizeof(char) * lSize);
    if(buffer == NULL){
        qDebug() << "malloc memory failed.";
        return -2;
    }
    result = fread(buffer,1,lSize,pFile);
    if(result != lSize){
        qDebug() << "Read file failed.\n";
        return -3;
    }
    fclose(pFile);

    std::ios::sync_with_stdio(false);

    if(buffer[0] == 's'){
        ReadASCII(buffer);
    }else {
        ReadBinary(buffer);
    }

    std::ios::sync_with_stdio(true);
    free(buffer);
    return true;
}

bool ReadStlFile::ReadResourceFile(const char *cfilename)
{
    QFile file(cfilename);
    file.open(QIODevice::ReadOnly);
    QByteArray t = file.readAll();
    char* buffer = t.data();


    std::ios::sync_with_stdio(false);
    if(buffer[0] == 's'){
        qDebug() << "ASCII format stl.\n";
        ReadASCII(buffer);
    }else {
        qDebug() << "Binary format stl.\n";
        ReadBinary(buffer);
    }
    std::ios::sync_with_stdio(true);
    file.close();

    return true;
}

int ReadStlFile::NumTrangle()
{
    return numTrangles;
}


std::vector<QVector3D> ReadStlFile::getPointList()
{
    return pointList;
}

std::vector<QVector3D> ReadStlFile::getVectorList()
{
    return  vectorList;
}

bool ReadStlFile::ReadBinary(const char *buffer)
{
    const char* p = buffer;
    char name[80];
    memcpy(name, p, 80);
    p += 80;
    numTrangles = cpyint(p);
    for (int i=0; i < numTrangles; i++){
        // normal vectors
        vectorList.push_back(QVector3D(cpyfloat(p), cpyfloat(p), cpyfloat(p)));
        for(int j =0 ;j < 3; j++){
            pointList.push_back(QVector3D(cpyfloat(p),cpyfloat(p),cpyfloat(p)));
        }
        p += 2;
    }
    return true;
}

bool ReadStlFile::ReadASCII(const char *buffer)
{
    Q_UNUSED(buffer);
}

int ReadStlFile::cpyint(const char *&p)
{
    int cpy;
    char byte[4];
    for(int i=0; i<4; i++){
        byte[i] = *p;
        p++;
    }
    cpy= *(int*)byte;
    return cpy;
}

float ReadStlFile::cpyfloat(const char *&p)
{
    float cpy;
    char byte[4];

    for (int i=0; i<4; i++){
        byte[i] = *p;
        p++;
    }
    cpy = *(float*)byte;
    return cpy;
}


