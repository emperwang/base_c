#include "modelopenglwidget.h"
#include <ModelPoint.h>
#include <QDebug>

ModelOpenglWidget::ModelOpenglWidget(QWidget *parent) : QOpenGLWidget(parent)
{

}

ModelOpenglWidget::~ModelOpenglWidget()
{
    makeCurrent();
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    doneCurrent();
}

void ModelOpenglWidget::initializeGL()
{
    initializeOpenGLFunctions();
    setFocusPolicy(Qt::FocusPolicy::StrongFocus);

    GLint attributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &attributes);
    qDebug() << "attributes: " << attributes;

    bool success = true;
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shade/shade/shader_3d.vert");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shade/shade/shader.frag");
    success = shaderProgram.link();
    if(!success){
        qDebug() << "link shader program error.\n";
    }

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_3d), vertices_3d, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, 5*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(float),(void*)(3 * sizeof (float)));
    glEnableVertexAttribArray(1);

    textureWall = new QOpenGLTexture(QImage(":/img/image/wall.jpg").mirrored());
    textureWall->generateMipMaps();
    textureSmall =new QOpenGLTexture(QImage(":/img/image/awesomeface.png").mirrored());
    textureSmall->generateMipMaps();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    shaderProgram.bind();
    shaderProgram.setUniformValue("textureWall", 0);
    shaderProgram.setUniformValue("textureFace", 1);
    glBindVertexArray(0);
}

void ModelOpenglWidget::resizeGL(int w, int h)
{
    Q_UNUSED(w); Q_UNUSED(h);
}

QVector3D cameraPos = QVector3D(0.0f,0.0f, 3.0f);
QVector3D cameraFront = QVector3D(0.0f, 0.0f, -1.0f);
QVector3D cameraUp = QVector3D(0.0f, 1.0f, 0.0f);

void ModelOpenglWidget::paintGL()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 view = QMatrix4x4();
    view.lookAt(cameraPos, cameraPos+cameraFront, cameraUp);

    QMatrix4x4 projection = QMatrix4x4();
    projection.perspective(45.0f,static_cast<float>(width()/height()), 0.1f, 100.0f);

    QMatrix4x4 mode = QMatrix4x4();
    mode.setToIdentity();
    //mode.translate(QVector3D(0.5f, -0.5f, 0.0f));
    mode.rotate(-45, QVector3D(1.0f, 0.0f,0.0f));

    shaderProgram.bind();
    shaderProgram.setUniformValue("sample",sample);
    shaderProgram.setUniformValue("model",mode);
    shaderProgram.setUniformValue("view",view);
    shaderProgram.setUniformValue("projection",projection);

    glBindVertexArray(VAO);
    textureWall->bind(0);
    textureSmall->bind(1);

    glDrawArrays(GL_TRIANGLES,0, 36);
}

void ModelOpenglWidget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "keyPress Event \n";
    switch(event->key()){
        case Qt::Key_Up:
            updateSmapleUp();
            break;
         case Qt::Key_Down:
            updateSmapleDown();
            break;
    }
    update();
}

void ModelOpenglWidget::updateSmapleUp(){
    this->sample += 0.1;
    if (this->sample > 1.0){
        this->sample = 1.0;
    }
}

void ModelOpenglWidget::updateSmapleDown()
{
    this->sample -= 0.1;
    if (this->sample < 0.0){
        this->sample = 0.0;
    }
}

void ModelOpenglWidget::mousePressEvent(QMouseEvent *event)
{

}

void ModelOpenglWidget::wheelEvent(QWheelEvent *event)
{

}
