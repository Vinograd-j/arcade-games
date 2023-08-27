#pragma once

#include "fstream"
#include "config.h"
#include "json.hpp"

namespace SnakeGame
{


	class JsonConfig
	{

	public:

		Config ParseFromConfigFile();

	};

}