#ifndef _TD2DE_TEXTURE_
#define _TD2DE_TEXTURE_


#include <string>
#include <vector>

namespace TD2DE
{
	//primary class handling texture storage
	class TextureNode
	{
	public:
		TextureNode()
		{
			Clear();
		};

		~TextureNode()
		{
			SDL_DestroyTexture(texture);
			if (texture != NULL)
				texture = NULL;			
		}

		void Clear();

		SDL_Texture* GetTexture();

		int GetWidth();
		void SetWidth(int newWidth);
		int GetHeight();
		void SetHeight(int newHeight);
		SDL_Rect GetRenderRectange();
		bool SetRenderRectange(SDL_Rect rect);
		bool SetTexture(SDL_Texture* newTexture);

		std::string textureName;

	private:
		SDL_Rect renderRectangle;
		SDL_Texture* texture = NULL;
		int width,
			height;
	};


	class Texture
	{
	public:
		int GetTextureLocation(std::string textureName);
		TextureNode GetTextureAt(int location);
		void RemoveTextureAt(int location);
		void RemoveAllTextures();
		int LoadFile(std::string location);
		int TotalLoadedTextures();

	private:
		std::vector<TextureNode> texture;

	} TD2DE_TEXTURE;	
}



#endif