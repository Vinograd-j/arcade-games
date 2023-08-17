#pragma once
#include "level.h"

class NormalLevel final : public Level
{

public:

	explicit NormalLevel(const sf::Color& backgroundColor) : Level(backgroundColor, 25) {}

};

