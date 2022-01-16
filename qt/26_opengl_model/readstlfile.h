#ifndef READSTLFILE_H
#define READSTLFILE_H
#include <vector>
#include <QVector3D>

class ReadStlFile
{
public:
    ReadStlFile();

    bool ReadFile(const char* cfilename);
    bool ReadResourceFile(const char* cfilename);
    int NumTrangle();
    std::vector<QVector3D> getPointList();
    std::vector<QVector3D> getVectorList();


private:
    std::vector<QVector3D> pointList;
    std::vector<QVector3D> vectorList;

    unsigned int numTrangles;
    char* memWriter;

    bool ReadBinary(const char* buffer);
    bool ReadASCII(const char* buffer);
    int cpyint(const char* &p);
    float cpyfloat(const char* &p);
};

#endif // READSTLFILE_H
