#pragma once

#include <string>

namespace SnakeGame
{


	struct Config
	{

	private:

		std::string _lostSoundPath;


		std::string _ateSoundPath;

	public:

		Config(const std::string& lostSoundPath, const std::string& ateSoundPath) :
				_lostSoundPath(lostSoundPath), _ateSoundPath(ateSoundPath)
		{
		}


		const std::string& GetLostSoundPath() const
		{
			return _lostSoundPath;
		}

		const std::string& GetAteSoundPath() const
		{
			return _ateSoundPath;
		}

	};

}