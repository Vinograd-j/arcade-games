#pragma once

#include "level.h"

namespace Minesweeper
{

	class EasyLevel : public Level
	{

	public:

		explicit EasyLevel() : Level(17, 17, 15) {}

	};

}