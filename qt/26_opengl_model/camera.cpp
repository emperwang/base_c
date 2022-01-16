#include "camera.h"


void Camera::updateCaneraVectors() {
    // calcate the new vector
    float PI = 3.1415926;
    float radious = PI/180.0f;
    QVector3D front;

    front.setX(cos(Yaw*radious) * cos((Pitch*radious)));
    front.setY(sin(Pitch * radious));
    front.setZ(sin(Yaw * radious) * cos(Pitch * radious));
    front.normalize();
    Front = front;
    // alse re-calcate the right and up vector
    Right = QVector3D::crossProduct(Front, WorldUp);
    Right.normalize();
    Up = QVector3D::crossProduct(Right, Front);
    Up.normalize();
}


void Camera::ProcessKeyBoard(Camera_Movement direction, float deltaTime) {
    float velocity = MovementSpeed * deltaTime;

    if (direction == FORWARD) {
        Position += Front * velocity;
    }
    if (direction == BACKWARD) {
        Position -= Front * velocity;
    }
    if (direction == LEFT) {
        Position -= Right * velocity;
    }
    if (direction == RIGHT) {
        Position += Right * velocity;
    }
    //updateCaneraVectors();
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constraintPitch) {
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw += xoffset;
    Pitch += yoffset;

    if (constraintPitch) {
        if (Pitch > 89.0f) {
            Pitch = 89.0f;
        }
        if (Pitch < -89.0f) {
            Pitch = -89.0f;
        }
    }

    updateCaneraVectors();
}

void Camera::ProcessMouseScroll(float yoffset) {
    Zoom -= static_cast<float>(yoffset);

    if (Zoom < 1.0f) {
        Zoom = 1.0f;
    }

    if (Zoom > 45.0f) {
        Zoom = 45.0f;
    }
}


