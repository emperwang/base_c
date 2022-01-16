#ifndef POINTCLOUDPROCESS_H
#define POINTCLOUDPROCESS_H
#include <vector>
#include <iostream>
#include <fstream>
#include <QVector3D>


class PointCloudProcess
{
public:
    PointCloudProcess();
    ~PointCloudProcess();

    QVector3D maxCoordinate;
    QVector3D minCoordinate;

    std::vector<QVector3D> pointData;
    float getFactor();

public:
    // 从文件中读取点数据,并按照比例映射到 -1.0 -- 1.0 范围内
    bool read(const char* path);
    // 规格化点数据, 映射到 -1.0--1.0范围
    void handlePointData(std::vector<QVector3D> data);
    // 分别计算出x,y,z的最大值组合成一个点
    void getMaxCoordinate();
    // 分别计算出x,y,z 的最小值,组合成一个点
    void getMinCoordinate();
    //获取中心点
    void getCenterPoint(QVector3D &vec);

};

#endif // POINTCLOUDPROCESS_H
