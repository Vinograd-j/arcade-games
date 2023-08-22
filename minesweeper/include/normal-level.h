#pragma once

#include "level.h"

namespace Minesweeper
{

	class NormalLevel : public Level
	{

	public:

		explicit NormalLevel() : Level(10, 10, 25) {}

	};

}