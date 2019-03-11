#ifndef _TD2DE_RENDER_
#define _TD2DE_RENDER_

namespace TD2DE
{
	class TD2DE_Render
	{
	private:
		std::string renderScaleQuality;

		int screenWidth,
			screenHeight,
			frameRateLimit;

		bool fullScreen;

		std::string windowName = "TD2DE Default Window Name";

	public:
		//sdl window and renderer build
		SDL_Window * window = NULL;
		SDL_Renderer* renderer = NULL;

		std::string GetRenderScaleQuality();
		void SetRenderScaleQuality(std::string newRenderScaleQuality);
		bool GetFullScreen();
		void SetFullScreen(bool newFullScreen);
		std::string GetWindowName();
		void SetWindowName(std::string newWindowName);
		int GetScreenWidth();
		void SetScreenWidth(int newScreenWidth);
		int GetScreenHeight();
		void SetScreenHeight(int newScreenHeight);
		int GetFrameRateLimit();
		void SetFrameRateLimit(int newFrameRateLimit);

		void RenderClear();
		void RenderPresent();
		void Render();

		bool Start();
	}TD2DE_RENDER;
}

std::string TD2DE::TD2DE_Render::GetRenderScaleQuality()
{
	return renderScaleQuality;
}

void TD2DE::TD2DE_Render::SetRenderScaleQuality(std::string newRenderScaleQuality)
{
	renderScaleQuality = newRenderScaleQuality;
}

bool TD2DE::TD2DE_Render::GetFullScreen()
{
	return fullScreen;
}

void TD2DE::TD2DE_Render::SetFullScreen(bool newFullScreen)
{
	fullScreen = newFullScreen;
}

std::string TD2DE::TD2DE_Render::GetWindowName()
{
	return windowName;
}

void TD2DE::TD2DE_Render::SetWindowName(std::string newWindowName)
{
	windowName = newWindowName;
}

int TD2DE::TD2DE_Render::GetScreenWidth()
{
	return screenWidth;
}

void TD2DE::TD2DE_Render::SetScreenWidth(int newScreenWidth)
{
	screenWidth = newScreenWidth;
}

int TD2DE::TD2DE_Render::GetScreenHeight()
{
	return screenHeight;
}

void TD2DE::TD2DE_Render::SetScreenHeight(int newScreenHeight)
{
	screenHeight = newScreenHeight;
}

int TD2DE::TD2DE_Render::GetFrameRateLimit()
{
	return frameRateLimit;
}

void TD2DE::TD2DE_Render::SetFrameRateLimit(int newFrameRateLimit)
{
	frameRateLimit = newFrameRateLimit;
}

void TD2DE::TD2DE_Render::RenderClear()
{
	SDL_RenderClear(renderer);
}

void TD2DE::TD2DE_Render::RenderPresent()
{
	SDL_RenderPresent(renderer);
}

void TD2DE::TD2DE_Render::Render()
{
	TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Timer]Render begin", TD2DE::DEBUG_HIGH);

	SDL_RenderClear(renderer);

	//go thorugh render list and render all textures as needed

	//foreach()


	SDL_RenderPresent(renderer);

	TD2DE::TD2DE_DEBUG.LogMessage("[TD2DE_Timer]Render end", TD2DE::DEBUG_HIGH);
}

bool TD2DE::TD2DE_Render::Start()
{

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, TD2DE_RENDER.GetRenderScaleQuality().c_str());

	int flags = 0;

	if (GetFullScreen() == 1)
		flags = SDL_WINDOW_OPENGL && SDL_WINDOW_FULLSCREEN;
	else
		flags = SDL_WINDOW_OPENGL;
	//create the base window for the program
	TD2DE_RENDER.window = SDL_CreateWindow
	(
		GetWindowName().c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		GetScreenWidth(),
		GetScreenHeight(),
		flags
	);

	if (TD2DE_RENDER.window == NULL)
	{
		TD2DE_DEBUG.LogMessage("[TD2DE_Render]Error: Initialize-SDL_Init-Initialize_Renderer: Unable to initialize primary window", DEBUG_LOW);
		return false;
	}
	else
		TD2DE_DEBUG.LogMessage("[TD2DE_Render]Primary Window creation success!", DEBUG_LOW);

	//create primary renderer (using hardware)
	if ((TD2DE_RENDER.renderer = SDL_CreateRenderer(TD2DE_RENDER.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)) == NULL)//TODO: remove vsync once engine handles own fps again
	{
		TD2DE_DEBUG.LogMessage("[TD2DE_Render]Error: Initialize-SDL_Init-Initialize_Renderer: Unable to initialize renderer", DEBUG_LOW);
		return false;
	}
	else
		TD2DE_DEBUG.LogMessage("[TD2DE_Render]Primary Renderer creation success!", DEBUG_LOW);

	SDL_SetRenderDrawBlendMode(TD2DE_RENDER.renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(TD2DE_RENDER.renderer, 0x00, 0x00, 0x00, 0xFF);

	return true;
}

#endif