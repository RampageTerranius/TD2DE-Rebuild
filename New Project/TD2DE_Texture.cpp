#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "TD2DE_Texture.h"
#include "TD2DE_Main.h"


//set all values to default and destroy the texture if it exists
void TD2DE::TextureNode::Clear()
{
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
	}

	renderRectangle.h = 0;
	renderRectangle.w = 0;
	renderRectangle.x = 0;
	renderRectangle.y = 0;
	width = 0;
	height = 0;
	texture = NULL;
}

SDL_Texture* TD2DE::TextureNode::GetTexture()
{
	return texture;
}

int TD2DE::TextureNode::GetWidth()
{
	return width;
}

void TD2DE::TextureNode::SetWidth(int newWidth)
{
	width = newWidth;
}

int TD2DE::TextureNode::GetHeight()
{
	return height;
}

void TD2DE::TextureNode::SetHeight(int newHeight)
{
	height = newHeight;
}

SDL_Rect TD2DE::TextureNode::GetRenderRectange()
{
	return renderRectangle;
}

bool TD2DE::TextureNode::SetTexture(SDL_Texture* newTexture)
{
	bool val = false;

	if (newTexture != NULL)
	{
		texture = newTexture;
		val = true;
	}
	else
	{
		//TODO: log error here
	}

	return val;
}

int TD2DE::Texture::GetTextureLocation(std::string textureName)
{
	int val = -1;

	for (int i = 0; i < int(texture.size()); i++)
	{
		if (texture[i].textureName == textureName)
			val = i;
	}

	return val;
}

TD2DE::TextureNode TD2DE::Texture::GetTextureAt(int location)
{
	return texture.at(location);
}

void TD2DE::Texture::RemoveTextureAt(int location)
{
	if (location <= texture.size())
	{
		texture.at(location).Clear();
		texture.erase(texture.begin() + location);
	}
}

void TD2DE::Texture::RemoveAllTextures()
{
	for (int i = 0; i < texture.size(); i++)
		RemoveTextureAt(i);
}

//returns -1 if failure
int TD2DE::Texture::LoadFile(std::string location)
{
	SDL_Surface* surface;
	surface = IMG_Load(location.c_str());

	if (surface == NULL)
	{
		//TODO: add error logging here
		return -1;
	}
	
	SDL_SetColorKey(surface, true, SDL_MapRGB(surface->format, 255, 0, 255));

	TextureNode tex;
	tex.SetTexture(SDL_CreateTextureFromSurface(TD2DE_MAIN.renderer, surface));

	if (tex.GetTexture() == NULL)
	{
		//TODO: add error logging here
		return -1;
	}
	

	//prepare the actual width and height of the image
	tex.SetWidth(surface->h);
	tex.SetHeight(surface->w);

	//prepare default render rectangle
	SDL_Rect rect;

	rect.h = surface->h;
	rect.w = surface->w;
	rect.x = 0;
	rect.y = 0;

	tex.SetRenderRectange(rect);

	TD2DE_TEXTURE.texture.push_back(tex);
	int val = TD2DE_TEXTURE.texture.size();

	return val;
}

int TD2DE::Texture::TotalLoadedTextures()
{
	return texture.size();
}
