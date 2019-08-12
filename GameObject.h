#include "cross_sdl.h"
#include "LoaderParams.h"
#include "Developer.h"
#include "Color.h"

#include <string>

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
struct Developer;
class GameObject
{

	//bool object_content_loaded = false;
public:
	virtual std::string GetGameObjectID() = 0;
	virtual bool LoadGameObjectContent(SDL_Renderer* passed_Renderer) = 0;
	virtual void Draw(SDL_Renderer* passed_Renderer) = 0;
	virtual void Update() = 0;
	virtual void CleanGameObjectContent() = 0;

	virtual bool GetContentLoadedStatus() = 0;
	virtual SDL_Texture* GetGameTexture() = 0;
	virtual void AlterTextureColor(Uint8 passed_r_value, Uint8 passed_g_value, Uint8 passed_b_value) = 0;
	virtual void RevertAlteredTextureColor() = 0;
	virtual void SetOriginalColors() = 0;
	virtual Color GetOringinalColors() = 0;

	GameObject(){}
protected:

	GameObject(LoaderParams* pParams){}
	virtual ~GameObject(){}

};

#endif //GAMEOBJECT_H