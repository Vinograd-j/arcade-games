#pragma once

#include <random>

namespace ArcadeGame
{


	class Random
	{

	private:

		std::random_device _device;

		std::mt19937 _randomGenerator;

	public:

		Random() : _randomGenerator(_device())
		{
		}

		size_t GenerateRandomLong(size_t min, size_t max);

		double GenerateRandomDouble(double min, double max);

	};

}