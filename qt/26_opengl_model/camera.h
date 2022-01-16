#ifndef CAMERA_H
#define CAMERA_H

#include <QVector3D>
#include <QMatrix4x4>
#include <QtMath>

enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.01f;
const float ZOOM = 45.0f;

class Camera
{
public:
    QVector3D Position;
    QVector3D Front;
    QVector3D Up;
    QVector3D Right;
    QVector3D WorldUp;

    // euler angles
    float Yaw;
    float Pitch;

    // camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    // with default value
    Camera(QVector3D position = QVector3D(0.0f, 0.0f, 3.0f), QVector3D up = QVector3D(0.0f, 1.0f, 0.0f), float yaw = YAW,
        float pitch = PITCH) : Front(QVector3D(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY),
        Zoom(ZOOM) {
        Position = position;
        WorldUp = up;
        Yaw = yaw;
        Pitch = pitch;
        updateCaneraVectors();
    }

    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) :
        Front(QVector3D(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
        Position = QVector3D(posX, posY, posZ);
        WorldUp = QVector3D(upX, upY, upZ);
        Yaw = yaw;
        Pitch = pitch;
        updateCaneraVectors();
    }

    QMatrix4x4 GetViewMatrix() {
        QMatrix4x4 view  = QMatrix4x4();
        view.lookAt(Position, Position + Front, Up);
        return view;
    }

    void ProcessKeyBoard(Camera_Movement direction, float deltaTime);

    void ProcessMouseMovement(float xoffset, float yoffset, bool constraintPitch = true);

    void ProcessMouseScroll(float yoffset);

private:
    void updateCaneraVectors();
};

#endif // CAMERA_H
