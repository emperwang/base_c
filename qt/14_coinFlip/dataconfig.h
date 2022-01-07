#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QObject>
#include <QMap>
#include <QVector>

class dataConfig : public QObject
{
    Q_OBJECT
public:
    explicit dataConfig(QObject *parent = nullptr);

    //存放关卡所有数据
    QMap<int,QVector<QVector<int>>> mData;

signals:

};

#endif // DATACONFIG_H
