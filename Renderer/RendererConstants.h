#pragma once

#ifndef RENDERERCONSTANTS_H
#define RENDERERCONSTANTS_H

#include <GL\glew.h>

/**
This class contains constants used within the Renderer project.
*/
namespace constants
{
	inline constexpr double pi { 3.1415926 };
	inline constexpr float toRadians { 3.1415926 / 180.0f };
	inline constexpr GLint DEFAULT_WINDOW_WIDTH { 800 };
	inline constexpr GLint DEFAULT_WINDOW_HEIGHT { 600 };

	inline constexpr int MAX_POINT_LIGHTS = 3;
	inline constexpr int MAX_SPOT_LIGHTS = 3;
}

#endif