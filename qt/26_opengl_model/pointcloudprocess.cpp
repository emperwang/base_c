#include "pointcloudprocess.h"
#include <QDebug>

PointCloudProcess::PointCloudProcess()
{

}

PointCloudProcess::~PointCloudProcess()
{

}

float PointCloudProcess::getFactor()
{
    float max = 0;
    if(max <= maxCoordinate.x()){
        max = maxCoordinate.x();
    }

    if(max <= maxCoordinate.y()){
        max = maxCoordinate.y();
    }

    if(max <= maxCoordinate.z()){
        max = maxCoordinate.z();
    }
    return 0.5 / max;
}

bool PointCloudProcess::read(const char *path)
{
    std::fstream readTextData(path);
    if(!readTextData){
        QString str = QString("read %1 failed.").arg(path);
        qDebug() << str;
        return false;
    }

    QVector3D data;
    float x, y,z;
    while(readTextData >> x >> y >> z){
        data.setX(x);
        data.setY(y);
        data.setZ(z);
        pointData.push_back(data);
    }
    readTextData.close();

    getMaxCoordinate();
    getMinCoordinate();
    // 将所有点向 0,0,0点移动
    QVector3D centerPoint;
    getCenterPoint(centerPoint);

    for(int i = 0; i < pointData.size(); i++){
        pointData[i].setX(pointData[i].x() - centerPoint.x());
        pointData[i].setY(pointData[i].y() - centerPoint.y());
        pointData[i].setZ(pointData[i].z() - centerPoint.z());
    }
    // update max and min
    getMaxCoordinate();
    getMinCoordinate();

    float factor = getFactor();
    for(int i = 0; i< pointData.size(); i++){
        pointData[i].setX(pointData[i].x() * factor);
        pointData[i].setY(pointData[i].y() * factor);
        pointData[i].setZ(pointData[i].z() * factor);
    }

    // update max and min again
    getMaxCoordinate();
    getMinCoordinate();
    return true;
}

void PointCloudProcess::handlePointData(std::vector<QVector3D> data)
{
    pointData = data;

    getMaxCoordinate();
    getMinCoordinate();

    QVector3D centerPoint;
    getCenterPoint(centerPoint);

    for(int i= 0; i < pointData.size(); i++){
        pointData[i].setX(pointData[i].x() - centerPoint.x());
        pointData[i].setY(pointData[i].y() - centerPoint.y());
        pointData[i].setZ(pointData[i].z() - centerPoint.z());
    }
    //更新最大 最小值点 坐标s
    getMaxCoordinate();
    getMinCoordinate();

    //建立一个 以可以容纳所有点的 正方体 然后 让顶点映射到 0.5（所有点都进行映射）
    float factor = getFactor();//获取变换因子
    for (int i = 0; i < pointData.size(); i++)
    {
        pointData[i].setX(pointData[i].x() * factor);
        pointData[i].setY(pointData[i].y() * factor);
        pointData[i].setZ(pointData[i].z() * factor);
    }

    //更新最大 最小值点 坐标s
    getMaxCoordinate();
    getMinCoordinate();
}

void PointCloudProcess::getMaxCoordinate()
{
    if( 0 == pointData.size()){
        return;
    }

    QVector3D vec;
    vec.setX(pointData[0].x());
    vec.setY(pointData[0].y());
    vec.setZ(pointData[0].z());

    for(int i = 0; i < pointData.size(); i++){
        if(vec.x() < pointData[i].x()){
            vec.setX(pointData[i].x());
        }

        if(vec.y() < pointData[i].y()){
            vec.setY(pointData[i].y());
        }

        if(vec.z() < pointData[i].z()){
            vec.setZ(pointData[i].z());
        }
    }
    maxCoordinate = vec;
}

void PointCloudProcess::getMinCoordinate()
{
    if( 0 == pointData.size()){
        return;
    }

    QVector3D vec;
    vec.setX(pointData[0].x());
    vec.setY(pointData[0].y());
    vec.setZ(pointData[0].z());

    for(int i = 0; i < pointData.size(); i++){
        if(vec.x() > pointData[i].x()){
            vec.setX(pointData[i].x());
        }

        if(vec.y() > pointData[i].y()){
            vec.setY(pointData[i].y());
        }

        if(vec.z() > pointData[i].z()){
            vec.setZ(pointData[i].z());
        }
    }
    minCoordinate = vec;
}

void PointCloudProcess::getCenterPoint(QVector3D &vec)
{
    if( 0 == pointData.size()){
        return;
    }

    // 重心
    /*float xSum = 0;
    float ySum = 0;
    float zSum = 0;
    for(int i = 0; i < pointData.size(); i++){
        xSum += pointData[i].x();
        ySum += pointData[i].y();
        zSum += pointData[i].z();
    }
    vec.setX(xSum / pointData.size());
    vec.setY(ySum / pointData.size());
    vec.setZ(zSum / pointData.size());*/

    vec.setX((maxCoordinate.x() + minCoordinate.x()) / 2);
    vec.setY((maxCoordinate.y() + minCoordinate.y()) / 2);
    vec.setZ((maxCoordinate.z() + minCoordinate.z()) / 2);
}
