#include "HashTable.h"


HashTable::HashTable(const LoaderParams* pParams)
{
	//set everything from params
	hash_table_rect = new SDL_Rect;

	hash_table_rect->x = pParams->GetX() - ( pParams->GetWidth() /2 );
	hash_table_rect->y = pParams->GetY() - ( pParams->GetHeight() / 2 );
	hash_table_rect->w = pParams->GetWidth();
	hash_table_rect->h = pParams->GetHeight();

	hash_table_collision_rect = new CCollisionRectangle();
}


bool HashTable::LoadGameObjectContent(SDL_Renderer* passed_Renderer)
{
	hash_table_texture = IMG_LoadTexture(passed_Renderer,"resources/images/table_image_2.png");

	if (hash_table_texture == NULL)
	{
		if (debug.is_debug_mode())
		{
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		}
		return false;
	}

	if (debug.is_debug_mode())
	{
		printf("HashTable was successfully loaded\n");
	}
	hash_table_content_loaded = true;
	return true;
}

void HashTable::Draw(SDL_Renderer* passed_Renderer)
{
	
	SDL_RenderCopyEx(passed_Renderer, hash_table_texture,NULL, hash_table_rect,0,NULL,SDL_FLIP_NONE);

}
void HashTable::Update()
{

}
void HashTable::CleanGameObjectContent()
{

}

void HashTable::SetOriginalColors()
{

}

void HashTable::RevertAlteredTextureColor()
{


}

void HashTable::AlterTextureColor(Uint8 passed_r_value, Uint8 passed_g_value, Uint8 passed_b_value)
{


}

void HashTable::ToggleTextureColor(Uint8 passed_r_value, Uint8 passed_g_value, Uint8 passed_b_value)
{

}