#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include <glad\glad.h>
#include <glm\glm.hpp>
#include <vector>

#include "game_object.h"
#include "sprite_renderer.h"
#include "resource_manager.h"


/// GameLevel holds all Tiles as part of a Breakout level and 
/// hosts functionality to Load/render levels from the harddisk.
class GameLevel
{
public:
	// level state
	std::vector<GameObject> Bricks;
	// constructor
	GameLevel() { }
	// loads level from file
	void Load(std::string file, uint32_t levelWidth, uint32_t levelHeight);
	// render level
	void Draw(SpriteRenderer& renderer);
	// check if the level is completed (all non-solid tiles are destroyed)
	bool IsCompleted();
private:
	// initialize level from tile data
	void init(std::vector<std::vector<uint32_t>> tileData, uint32_t levelWidth, uint32_t levelHeight);
};

#endif // !GAMELEVEL_H

