#pragma once
#include "level.h"

class EasyLevel final : public Level
{

public:

	explicit EasyLevel(const sf::Color& backgroundColor) : Level(backgroundColor, 15) { }
	
};

