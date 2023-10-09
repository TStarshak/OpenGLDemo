#pragma once
#include <vector>
#include <GL\glew.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include <GLFW\glfw3.h>

class Camera
{
public:
	//public constructor
	Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed);

	//public constructor
	Camera() : Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 1.0f, 1.0f) {};

	//moves the camera according to the keys pressed and the time delta
	void keyControl(bool* keys, GLfloat deltaTime);

	//moves the camera according to the mouse movement
	void mouseControl(std::vector<GLfloat> mouseDelta);

	//Returns the position of the camera
	glm::vec3 getCameraPosition();

	//Returns the direction of the camer
	glm::vec3 getCameraDirection();
	
	//Returns the camera's view matrix
	glm::mat4 calculateViewMatrix();

	//public deconstructor
	~Camera();

private:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;

	GLfloat yaw;
	GLfloat pitch;

	GLfloat moveSpeed;
	GLfloat turnSpeed;

	void update();
};

