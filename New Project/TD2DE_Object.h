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

void TD2DE::TD2DE_Object::AddToRender()
{
	
}

void TD2DE::TD2DE_Object::RemoveFromRender()
{

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