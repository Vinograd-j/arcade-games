#include "json_config.h"


Minesweeper::Config Minesweeper::JsonConfig::ParseFromConfigFile()
{

	std::ifstream inputFile("minesweeperConfig.json");

	if(!inputFile.is_open())
		throw std::logic_error("Can`t open snakeConfig.json");

	nlohmann::json jsonData;

	inputFile >> jsonData;
	inputFile.close();

	return Config(jsonData["openSoundPath"], jsonData["lostSoundPath"], jsonData["wonSoundPath"], jsonData["fontPath"]);

}
