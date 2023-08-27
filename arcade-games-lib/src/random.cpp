#include "random.h"

size_t ArcadeGame::Random::GenerateRandomLong(size_t min, size_t max)
{
	std::uniform_int_distribution distribution(min, max);

	return distribution(_randomGenerator);
}

double ArcadeGame::Random::GenerateRandomDouble(double min, double max)
{

	std::uniform_real_distribution distribution(min, max);

	return distribution(_randomGenerator);
}
