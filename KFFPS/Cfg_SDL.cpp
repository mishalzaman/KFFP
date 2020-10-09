#include "Cfg_SDL.h"

int Cfg_SDL::initSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return Cfg_SDL::ERROR_SDL_INIT;
	}

	return 0;
}

int Cfg_SDL::defaults(SDL_Window*& window, SDL_GLContext& context, unsigned int screenWidth, unsigned int screenHeight, unsigned int sMinor, unsigned int sMajor, bool hasAA)
{
	unsigned int engineError;

	if (engineError = Cfg_SDL::initSDL() > 0) return engineError;
	if (engineError = Cfg_SDL::setGlAttributes(sMinor, sMajor) > 0) return engineError;
	if (engineError = Cfg_SDL::initWindow(window, screenWidth, screenHeight) > 0) return engineError;
	if (engineError = Cfg_SDL::initContext(context, window) > 0) return engineError;
	if (engineError = Cfg_SDL::initGlew() > 0) return engineError;
	if (hasAA) bool hasAA = false; Cfg_SDL::initMultisampling(1,4);
}

int Cfg_SDL::setGlAttributes(unsigned int major, unsigned int minor)
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	return 0;
}

void Cfg_SDL::initMultisampling(int buffers, int sampleSize)
{
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, buffers);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, sampleSize);
}

int Cfg_SDL::initWindow(SDL_Window*& window, unsigned int width, unsigned int height)
{
	window = SDL_CreateWindow(
		"Thunderbolt",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
	);

	if (!window) {
		return Cfg_SDL::ERROR_CREATE_WINDOW;
	}
	return 0;
}

int Cfg_SDL::initContext(SDL_GLContext& context, SDL_Window*& window)
{
	context = SDL_GL_CreateContext(window);

	if (!context) {
		return Cfg_SDL::ERROR_CREATE_CONTEXT;
	}
	return 0;
}

int Cfg_SDL::initGlew()
{
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();

	if (err) {
		return Cfg_SDL::ERROR_GLEW_INIT;
	}

	return 0;
}

int Cfg_SDL::shutDown(SDL_Window*& window, SDL_GLContext& context)
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}