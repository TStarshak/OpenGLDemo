#include "Window.h"

Window::Window(GLint windowWidth, GLint windowHeight)
{
	width = windowWidth;
	height = windowHeight;

	prevX = prevX = deltaX = deltaY = 0;
	hasMouseMoved = false;

	for (size_t i = 0; i < 1024; i++) {
		keypresses[i] = 0;
	}
}

int Window::initialise()
{
	if (!glfwInit())
	{
		printf("Error Initialising GLFW");
		glfwTerminate();
		return 1;
	}

	// Setup GLFW Windows Properties
	// OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core Profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Allow forward compatiblity
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Create the window
	mainWindow = glfwCreateWindow(width, height, "Test Window", NULL, NULL);
	if (!mainWindow)
	{
		printf("Error creating GLFW window!");
		glfwTerminate();
		return 1;
	}

	// Get buffer size information
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set the current context
	glfwMakeContextCurrent(mainWindow);

	createCallbacks();
	glfwSetInputMode(mainWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	// Allow modern extension access
	glewExperimental = GL_TRUE;

	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		printf("Error: %s", glewGetErrorString(error));
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST);

	// Create Viewport
	glViewport(0, 0, bufferWidth, bufferHeight);

	glfwSetWindowUserPointer(mainWindow, this);
}

void Window::onKeyEvent(GLFWwindow* window, int key, int code, int action, int mode) {
	Window* userWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	//On user pressing ESC
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key >= 0 && key < 1024) {
		if (action == GLFW_PRESS) {
			userWindow->keypresses[key] = true;
		}
		else if (action == GLFW_RELEASE) {
			userWindow->keypresses[key] = false;
		}
	}

}

void Window::onMouseEvent(GLFWwindow* window, double posX, double posY) {
	Window* userWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
	
	//If this is the first time the mouse has moved, set previous positions to the current position
	if (userWindow->hasMouseMoved) {
		userWindow->prevX = posX;
		userWindow->prevY = posY;
		userWindow->hasMouseMoved = true;
	}

	//set change in mouse position
	userWindow->deltaX = posX - userWindow->prevX;
	userWindow->deltaY = userWindow->prevY- posY;

	userWindow->prevX = posX;
	userWindow->prevY = posY;


}

std::vector<GLfloat> Window::getMouseChange() {
	GLfloat xChange = deltaX;
	GLfloat yChange = deltaY;

	deltaX = deltaY = 0;

	std::vector<GLfloat> vec{ xChange, yChange };
	return vec;
}

void Window::createCallbacks() {
	glfwSetKeyCallback(mainWindow, onKeyEvent);
	glfwSetCursorPosCallback(mainWindow, onMouseEvent);
}

Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();
}
