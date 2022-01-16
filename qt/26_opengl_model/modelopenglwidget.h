#ifndef MODELOPENGLWIDGET_H
#define MODELOPENGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QMatrix4x4>
#include <QMatrix2x2>
#include <QVector3D>
#include <QVector2D>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QTime>
#include <QTimer>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPoint>

#include "camera.h"

class ModelOpenglWidget : public QOpenGLWidget,QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
public:
    explicit ModelOpenglWidget(QWidget *parent = nullptr);
    ~ModelOpenglWidget();
protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

    virtual void keyPressEvent(QKeyEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void wheelEvent(QWheelEvent *event);
    virtual void mouseMoveEvent(QMouseEvent * event);

    void setPressPoint(QPoint &point);
    void updateSmapleUp();
    void updateSmapleDown();



private:
    void translatePoint(QPoint &point);

private:
    QOpenGLShaderProgram shaderProgram;
    GLuint VAO, VBO;
    QOpenGLTexture *textureWall;
    QOpenGLTexture *textureSmall;
    QOpenGLTexture *textureContainer;
    QTimer timer;
    QTime time;
    bool first = true;
    float deltaTime;
    float lastTime;
    QPoint deltaPos;
    QPoint lastPos;
    QPoint pressPoint;
    float sample = 0.2;
    Camera camera = Camera(QVector3D(0.0f, 0.0f, 3.0f));
    // 模式矩阵
    QMatrix4x4 mode;
    QMatrix4x4 modeUse;
    QMatrix4x4 modeSave;

signals:

public slots:
    void onTimeout();

};

#endif // MODELOPENGLWIDGET_H
