#pragma once

#include "level.h"

namespace Minesweeper
{

	class HardLevel : public Level
	{

	public:

		explicit HardLevel() : Level(25, 25, 25) {}

	};

}
