#pragma once

#include "level.h"

namespace Minesweeper
{

	class NormalLevel : public Level
	{

	public:

		explicit NormalLevel() : Level(20, 20, 25) {}

	};

}