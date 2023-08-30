#include "json_config.h"

SnakeGame::Config SnakeGame::JsonConfig::ParseFromConfigFile()
{

	std::ifstream inputFile("configs/snakeConfig.json");

	if(!inputFile.is_open())
		throw std::logic_error("Can`t open snakeConfig.json");

	nlohmann::json jsonData;

	inputFile >> jsonData;
	inputFile.close();

	return Config(jsonData["lostSoundPath"], jsonData["ateSoundPath"]);
}