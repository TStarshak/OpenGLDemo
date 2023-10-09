#pragma once

#include "stdio.h"
#include <vector>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "RendererConstants.h"

class Window
{
public:
	//Creates a new window with specified dimensions
	Window(GLint windowWidth, GLint windowHeight);

	//Creates a 800x600 window
	Window() : Window(constants::DEFAULT_WINDOW_WIDTH, constants::DEFAULT_WINDOW_HEIGHT) {};

	//Initializes the window for use with GLFW
	int initialise();

	//
	GLint getBufferWidth() { return bufferWidth; }
	GLint getBufferHeight() { return bufferHeight; }

	//returns a flag for if the window should be closed
	bool getShouldClose() { return glfwWindowShouldClose(mainWindow); }

	//returns a point to an array of bools representing pressed keys
	bool* getKeypresses() { return keypresses; }

	//returns a list of 2 items representing the change in mouse position
	std::vector<GLfloat> getMouseChange();

	//swaps glfw buffer to use this window
	void swapBuffers() { glfwSwapBuffers(mainWindow); }

	~Window();

private:
	//a pointer to a GLFWwindow
	GLFWwindow* mainWindow;

	//the width and height of this window
	GLint width, height;
	GLint bufferWidth, bufferHeight;

	//an array representing keys that are pressed down
	bool keypresses[1024];

	//The previous mouse positions and the change in mouse pos
	GLfloat prevX, prevY, deltaX, deltaY;
	
	//a flag representing if the mouse has moved
	bool hasMouseMoved;

	//Helper method to initialize GLFW callbacks
	void createCallbacks();
	
	//functions used for GLFW callbacks
	static void onKeyEvent(GLFWwindow* window, int key, int code, int action, int mode);
	static void onMouseEvent(GLFWwindow* window, double posX, double posY);
};