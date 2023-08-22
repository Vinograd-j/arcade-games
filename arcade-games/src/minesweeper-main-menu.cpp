#include "minesweeper-game-menu.h"
#include "../../minesweeper/include/level.h"
#include "../../minesweeper/include/easy-level.h"
#include "../../minesweeper/include/normal-level.h"
#include "../../minesweeper/include/hard-level.h"


MinesweeperMenu::MinesweeperMenu(const sf::Font& textFont, class MainMenu* mainMenu) : _textFont(textFont), _mainMenu(mainMenu)
{
	Initialize();
}

void MinesweeperMenu::Initialize()
{

	_textSize = 28;
	_windowSize = sf::VideoMode(450, 800);
	_buttonSize = sf::Vector2f(240, 50);

	_menu = new ArcadeGame::Menu(sf::Color(42, 51, 82), _windowSize, "Minesweeper", sf::Style::Titlebar | sf::Style::Close);

	CreateTexts();
	CreateButtons();
}

void MinesweeperMenu::Open()
{
	_menu->Open();
}

void MinesweeperMenu::Close()
{
	_menu->Close();
}

void MinesweeperMenu::OnEasyLevelChosen() const
{
	Minesweeper::EasyLevel().StartGame();
}

void MinesweeperMenu::OnNormalLevelChosen() const
{
	Minesweeper::NormalLevel().StartGame();
}

void MinesweeperMenu::OnHardLevelChosen() const
{
	Minesweeper::HardLevel().StartGame();
}

void MinesweeperMenu::OnReturnChosen()
{
	Close();
	_mainMenu->Open();
}

void MinesweeperMenu::CreateTexts()
{
	sf::Text title("MINESWEEPER", _textFont, 42);

	_easyButtonText = sf::Text("Easy Level", _textFont, _textSize);
	_normalButtonText =  sf::Text("Normal Level", _textFont, _textSize);
	_hardButtonText = sf::Text("Hard Level", _textFont, _textSize);
	_returnButtonText =  sf::Text("Return to Menu", _textFont, _textSize);

	_easyButtonText.setFillColor(sf::Color(235, 38, 176));
	_normalButtonText.setFillColor(sf::Color(235, 195, 87));
	_hardButtonText.setFillColor(sf::Color(120, 28, 117));
	_returnButtonText.setFillColor(sf::Color(191, 161, 40));

	title.setPosition(((float)_windowSize.width - title.getGlobalBounds().width) / 2, ((float)_windowSize.height - title.getGlobalBounds().height) / 2 - 250);
	title.setFillColor(sf::Color(87, 227, 59));

	_menu->AddText(title);
}

void MinesweeperMenu::CreateButtons()
{

	float centerX = (static_cast<float>(_windowSize.width) - _buttonSize.x) / 2.f;
	float centerY = (static_cast<float>(_windowSize.height) - _buttonSize.y) / 2.f;

	_menu->AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY - 100), _easyButtonText, sf::Color(201, 209, 180), [this](){MinesweeperMenu::OnEasyLevelChosen();}));
	_menu->AddButton( new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY), _normalButtonText, sf::Color(23, 138, 50), [this](){OnNormalLevelChosen();}));
	_menu->AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY + 100), _hardButtonText, sf::Color(194, 129, 25), [this](){MinesweeperMenu::OnHardLevelChosen();}));
	_menu->AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY + 250), _returnButtonText, sf::Color(171, 218, 222), [this]() {MinesweeperMenu::OnReturnChosen();}));
}

MinesweeperMenu::~MinesweeperMenu()
{
	delete _menu;
}
