#include "random.h"

size_t Random::GenerateRandomLong(size_t min, size_t max)
{
	std::uniform_int_distribution distribution(min, max);

	return distribution(_randomGenerator);
}

double Random::GenerateRandomDouble(double min, double max)
{

	std::uniform_real_distribution distribution(min, max);

	return distribution(_randomGenerator);
}
