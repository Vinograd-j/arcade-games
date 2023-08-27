#pragma once

#include "config.h"
#include "json.hpp"

#include <fstream>

namespace Minesweeper
{

	class JsonConfig
	{

	public:

		Config ParseFromConfigFile();

	};

}