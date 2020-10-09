#include "Cfg_OpenGL.h"

void Cfg_OpenGL::depthTest(bool enable)
{
	enable ? glEnable(GL_DEPTH_TEST) : glDisable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}

void Cfg_OpenGL::culling(bool enable)
{
	if (enable)
	{
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glFrontFace(GL_CCW);

		return;
	}

	glDisable(GL_CULL_FACE);
}

void Cfg_OpenGL::wireframe(bool enable)
{
	enable ? glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Cfg_OpenGL::mouseCapture(bool enable)
{
	enable ? SDL_CaptureMouse(SDL_TRUE) : SDL_CaptureMouse(SDL_FALSE);
}

void Cfg_OpenGL::mouseCursor(bool enable)
{
	enable ? SDL_ShowCursor(1) : SDL_ShowCursor(0);
}

void Cfg_OpenGL::mouseCenter(SDL_Window* window, unsigned int width, unsigned int height)
{
	SDL_WarpMouseInWindow(window, width / 2.0f, height / 2.0f);
}

void Cfg_OpenGL::swapBuffers(SDL_Window* window, unsigned int width, unsigned int height)
{
	SDL_GL_SwapWindow(window);

	glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, (int)width, (int)height);
}

void Cfg_OpenGL::viewPort(unsigned int screenWidth, unsigned int screenHeight)
{
	glViewport(0, 0, screenWidth, screenHeight);
}

void Cfg_OpenGL::glBlend()
{
	glEnable(GL_BLEND);
}

void Cfg_OpenGL::glBlendFunAlpha()
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
