//#include "GameObject.h"

#include "CSDL.h"
#include "Developer.h"

#ifndef HITBOX_H
#define HITBOX_H

class Developer;

class HitBox
{
	SDL_Renderer* game_renderer = NULL;
	SDL_Texture* hit_box_texture = NULL;
	SDL_Rect* hit_box_crop_rect = NULL; //if I want to animate after everything works

	Developer debug;
public:

	HitBox();
	HitBox(SDL_Renderer* passed_renderer);
	~HitBox();

	bool LoadTexture();

	void SetRenderer(SDL_Renderer* passed_renderer);
	void RenderGameObjectHitBox(SDL_Rect* passed_collision_rect);
};


#endif //HITBOX_H