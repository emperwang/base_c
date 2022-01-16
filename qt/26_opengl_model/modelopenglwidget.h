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

    void updateSmapleUp();
    void updateSmapleDown();

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
    float sample = 0.2;
    Camera camera = Camera(QVector3D(0.0f, 0.0f, 3.0f));

signals:

public slots:
    void onTimeout();

};

#endif // MODELOPENGLWIDGET_H
