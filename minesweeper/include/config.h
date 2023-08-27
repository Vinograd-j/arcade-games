#pragma once

#include <string>

namespace Minesweeper
{


	struct Config
	{

	private:

		std::string _openSoundPath;

		std::string _lostSoundPath;

		std::string _wonSoundPath;

		std::string _fontPath;

	public:

		explicit Config(const std::string& openSoundPath, const std::string& lostSoundPath, const std::string& wonSoundPath, const std::string& fontPath) :
						_openSoundPath(openSoundPath), _lostSoundPath(lostSoundPath), _wonSoundPath(wonSoundPath), _fontPath(fontPath) {}


		const std::string& GetOpenSoundPath() const { return _openSoundPath; }

		const std::string& GetLostSoundPath() const { return _lostSoundPath; }

		const std::string& GetWonSoundPath() const { return _wonSoundPath; }

		const std::string& GetFontPath() const { return _fontPath; }


	};

}