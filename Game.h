#include <memory>
#include <vector>
#include <map>

#include "Grid.h"
#include "Win_Case.h"
#include "Player.h"
#include "AI.h"
#include "CSDL.h"
#include "HashTable.h"
#include "GameText.h"
#include "TileMarker.h"
#include "PromptWindow.h"
#include "TileSelector.h"
#include "Developer.h"

#ifndef GAME_H
#define GAME_H
struct Developer;
class Win_case;
class Grid;
class Player;
class AI;
class Position;
class CSDL;
class PromptWindow;

//static enum ButtonValue { UP, DOWN, LEFT, RIGHT, START, SELECT, A_ACTION, B_ACTION };

class Game{

//Player* pos_1
Player* player_pos_1;
//Player pos_2;
Player* player_pos_2;
unsigned int total_turns;
bool win_cases_loaded;
bool Game_Over;
bool quit_game_from_input;
Grid* game_grid = NULL;
//changed to vector
//std::vector<Win_case*> win_cases;
Win_Case win_cases[8];
CSDL* csdl_obj;
unsigned int turn_phase;

unsigned int players_turn_order = 0; // if 1 player at pos_2 has the first turn

enum CurrentPlayerTurn {not_in_match,Player_1_turn,Player_2_turn};

//gameobjects
std::vector<GameObject*> allGameObjects;

std::map<std::string, GameObject* > game_object_map;

//in game selector
TileSelector* game_tile_selector = NULL;
//game hashTable - the graphic grid

HashTable* game_hash_table = NULL;

//Input Position

Position* game_input_position_ptr;

// game mode enum

enum current_game_state {main_menu,game_options,opponent_selection, match_gameplay,Settings_Menu,Credits_Menu,pause,quit};

enum current_gameplay_mode {human_vs_human,human_vs_computer};


enum current_highlighted_option_menu_text { none_of_the_options_highlighted,play_option_highlighted,options_option_highlighted,credits_option_highlighted };

// changeable variable 0-2 for options open highlighted option

unsigned int game_option_select_value = 0;

CurrentPlayerTurn x_o_current_player_turn = not_in_match;
current_game_state x_o_game_state;
current_gameplay_mode x_o_gameplay_mode;
current_highlighted_option_menu_text x_o_highlighted_option = none_of_the_options_highlighted;
//screen dimensions
unsigned int SCREEN_WIDTH;

unsigned int SCREEN_HEIGHT;
bool sdl_button_released;

std::string* sdl_player_input_string;

enum GameResult {no_result,player1_wins,player2_wins,match_draw};
GameResult current_game_result = no_result;

bool menu_activated = false;

//Prompts map menus and such

std::map<std::string, PromptWindow*> prompt_window_map;

// InputButtonValue;



int time_Check;
public:
Game(unsigned int passed_screen_width, unsigned int passed_screen_height);
~Game();


//filter check then mark
bool FilterUserInput(std::string raw_input_string,Position* passed_position);
bool CheckIfTileIsAvailable(Position* passed_position_to_check);
Grid* GetGameGrid(){ return game_grid;}
int GetTurnPhase(){ return turn_phase; }
bool PlayerWin(Player* passed_player);

void LoadWinCases();
Win_Case GetWinCase(int win_case_index);

void GameLoop();
void SetGameTileMark(Position* position_to_mark,std::string player_mark);
int PlayerTurn(Player* current_player);
void TurnPhaseEvent();

//void LoadAIPlayer();
//Load nomal Player
//AI V AI?
bool LoadGameObjectContent();

bool LoadGameOpeningMenu();
//switch method calls other methods depending on scene
bool LoadGameOptionsMenu();
bool LoadGameplayObjects();

bool LoadOpponentOptions();

bool loadPlayerTextureMarks();

bool LoadPlayAgainPrompt();

bool LoadTileSelector();

bool LoadSettingsMenu();

bool LoadCreditsMenu();

void GameEventManager();

void RenderGameTextures();

void UpdateGameTextures();

void GameRematchReset();

void SetupSecondPlayerValue();

void SetCurrentPlayerTurn();



// texture modding 

/*
RevertGameObjectColorList();

variadic template member method to change color altered textures of the texture map to there original colors

strings passed are used as keys


- For GameText obj - text changes to white

*/

//base function 
void RevertGameObjectColorList();

template<typename... String_args>
void RevertGameObjectColorList(std::string passed_string_arg, String_args... other_passed_string_args);

template<typename... Basic_string_args>
void RevertGameObjectColorList( char* passed_string_arg, Basic_string_args... other_passed_string_args);

//AI turn

void AITurnEvent();

//Update for event
void PostEventUpdate();
//match methods

bool SelectorHoveringOverHashTable();

};
#endif //GAME_H
