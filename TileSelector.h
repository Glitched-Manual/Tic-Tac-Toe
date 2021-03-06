#include "HashTable.h"
#include "Grid.h"
#include "CSDL.h"
#include "Developer.h"
#include "CCollisionRectangle.h"

#include <vector>

#ifndef TILESELECTOR_H
#define TILESELECTOR_H 

class TileSelector: public GameObject
{
	SDL_Texture* tile_selector_texture = NULL;

	SDL_Rect* tile_selector_texture_rect = NULL;

	SDL_Rect* hash_table_rect = NULL;

	Grid* game_grid = NULL;

	CSDL* csdl_obj;

	Color tile_selector_base_color;

	std::vector<SDL_Color*> tile_selector_vector;

	std::string tile_selector_id;

	CCollisionRectangle* tile_selector_collision_Rect;

	bool tile_selector_texture_texture_colors_altered = false;

	bool tile_selector_content_loaded = false;

	

	 int *mouse_pos_x;

	 int *mouse_pos_y;

	 bool left_direction = false;
	 bool right_direction = false;
	 bool up_direction = false;
	 bool down_direction = false;

	 
	 Position* selector_position;

	//for switching controls
	enum ControlsType {keyboard_controls,mouse_controls,game_controller_controls};

	ControlsType current_game_controls = mouse_controls;

	int time_Check;

public:
	TileSelector(LoaderParams* pParams, Grid* passed_grid, SDL_Rect* passed_hash_table_rect, CSDL* passed_csdl_obj, std::string passed_id_name);

	std::string GetGameObjectID() { return tile_selector_id; }
	 bool LoadGameObjectContent(SDL_Renderer* passed_Renderer);
	 void Draw(SDL_Renderer* passed_Renderer);
	 void Update();
	 void CleanGameObjectContent();

	 bool GetContentLoadedStatus() { return tile_selector_content_loaded; }
	 SDL_Texture* GetGameTexture() { return tile_selector_texture;	 }

	//if case switches colors for original to other colors and back when recalled
	 void ToggleTextureColor(Uint8 passed_r_value, Uint8 passed_g_value, Uint8 passed_b_value);

	 void AlterTextureColor(Uint8 passed_r_value, Uint8 passed_g_value, Uint8 passed_b_value);
	 void RevertAlteredTextureColor();
	 void SetOriginalColors(); 
	 Color GetOringinalColors() {	 return tile_selector_base_color;	 } //leave empty return white
	 bool GetAreColorsAltered() { return tile_selector_texture_texture_colors_altered; }
	 SDL_Rect* GetTextureRect() { return tile_selector_texture_rect; }

	 CCollisionRectangle* GetCollisionRectangle() { return tile_selector_collision_Rect; }
	 void MoveSelector(int x, int y);



	 int GetX(){ return *mouse_pos_x;}
	 int GetY() { return *mouse_pos_y; }
	 //load colors

	// void LoadSelectorColors();

	void LoadSelectorColors();
	 //SetSelectorScreenPosition();
	void SetSelectorScreenPosition();

	//Controller and Arrow keys change direction
	void ButtonControls();

	void SetDirectionTrue(std::string passed_direction);

	void SetDirectionFalse(std::string passed_direction);

	void ButtonPressed();

	void ButtonReleased();
};


#endif //TILESELECTOR_H


