#ifndef _TD2DE_OBJECT_
#define _TD2DE_OBJECT_

#include <string>

namespace TD2DE
{
	class TD2DE_Object
	{
	protected:
		//variables		
		int objectID;

		TD2DE::TextureNode* texture;
		std::string textureID;//name of the texture used in map<string, cTexture> TD2DE_TEXTURE			

		double x,//left right
			y,//up down
			dirPointing;

		//functions
	public:
		//constructor
		TD2DE_Object();
		void Delete();//deletes the entire objects stored variables setting them back to default

		std::string GetTextureID();
		void SetTextureID(std::string New);
		TD2DE::TextureNode* GetTexture();
		void SetTexture(TD2DE::TextureNode* texture);
		int GetObjectID();
		void SetObjectID(int NewObjectID);
		void Render();
		double GetX();
		void SetX(double New);
		double GetY();
		void SetY(double New);
		double GetDirPointing();
		void SetDirPointing(double New);
	};
}

TD2DE::TD2DE_Object::TD2DE_Object()
{
	Delete();
}

void TD2DE::TD2DE_Object::Delete()
{
	textureID = "";
	objectID = -1;//loops to create new objects etc will look for a -1 id
	x = y = 0.0;
	dirPointing = 0.0;
}

void TD2DE::TD2DE_Object::Render()
{
	TD2DE::TextureNode* lTEX = GetTexture();
	SDL_Rect sRenderRect = lTEX->GetRenderRectange();
	SDL_Rect tRenderRect;

	if (sRenderRect.h == 0 && sRenderRect.w == 0 && sRenderRect.x == 0 && sRenderRect.y == 0)
	{
		sRenderRect.h = lTEX->GetHeight();
		sRenderRect.w = lTEX->GetWidth();
		sRenderRect.x = 0;
		sRenderRect.y = 0;
		tRenderRect.h = lTEX->GetHeight();
		tRenderRect.w = lTEX->GetWidth();
	}
	else
	{
		tRenderRect.h = sRenderRect.h;
		tRenderRect.w = sRenderRect.w;
	}
	tRenderRect.x = x;
	tRenderRect.y = y;

	SDL_RenderCopyEx(TD2DE_RENDER.renderer, lTEX->GetTexture(), &sRenderRect, &tRenderRect, dirPointing, NULL, SDL_FLIP_NONE);
}

std::string TD2DE::TD2DE_Object::GetTextureID()
{
	return textureID;
}

void TD2DE::TD2DE_Object::SetTextureID(std::string New)
{
	textureID = New;
}

TD2DE::TextureNode* TD2DE::TD2DE_Object::GetTexture()
{
	return texture;
}

void TD2DE::TD2DE_Object::SetTexture(TD2DE::TextureNode* newTexture)
{
	texture = newTexture;
}

int TD2DE::TD2DE_Object::GetObjectID()
{
	return objectID;
}

void TD2DE::TD2DE_Object::SetObjectID(int NewObjectID)
{
	objectID = NewObjectID;
}

double TD2DE::TD2DE_Object::GetX()
{
	return x;
}

void TD2DE::TD2DE_Object::SetX(double New)
{
	y = New;
}

double TD2DE::TD2DE_Object::GetY()
{
	return y;
}

void TD2DE::TD2DE_Object::SetY(double New)
{
	y = New;
}

double TD2DE::TD2DE_Object::GetDirPointing()
{
	return dirPointing;
}

void TD2DE::TD2DE_Object::SetDirPointing(double New)
{
	dirPointing = New;
}


#endif