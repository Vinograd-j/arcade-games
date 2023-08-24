#include "main-menu.h"

MainMenu::MainMenu(const sf::Font& textFont) : _textFont(textFont), _minesweeperMenu(new MinesweeperMenu(textFont, this)), _snakeMenu(new SnakeMenu(textFont, this))
{
	Initialize();
}

void MainMenu::Initialize()
{

	_textSize = 30;
	_windowSize = sf::VideoMode(450, 800);
	_buttonSize = sf::Vector2f(290, 70);

	_menu = new ArcadeGame::Menu(sf::Color(52, 13, 64), _windowSize, "Minesweeper", sf::Style::Titlebar | sf::Style::Close);

	CreateTexts();
	CreateButtons();
}

void MainMenu::Open()
{
	_menu->Open();
}

void MainMenu::Close()
{
	_menu->Close();
}

void MainMenu::OnSnakeGameChosen()
{
	Close();
	_snakeMenu->Open();
}

void MainMenu::OnMinesweeperChanged()
{
	Close();
	_minesweeperMenu->Open();
}

void MainMenu::CreateTexts()
{
	sf::Text title("ARCADE GAMES", _textFont, 50);

	_snakeButtonText = sf::Text("SNAKE GAME", _textFont, _textSize);
	_minesweeperButtonText = sf::Text("MINESWEEPER", _textFont, _textSize);

	_snakeButtonText.setFillColor(sf::Color(183, 0, 255));
	_minesweeperButtonText.setFillColor(sf::Color(222, 216, 40));


	title.setPosition(((float)_windowSize.width - title.getGlobalBounds().width) / 2, ((float)_windowSize.height - title.getGlobalBounds().height) / 2 - 320);
	title.setFillColor(sf::Color(219, 70, 70));

	_menu->AddText(title);
}

void MainMenu::CreateButtons()
{
	float centerX = (static_cast<float>(_windowSize.width) - _buttonSize.x) / 2.f;
	float centerY = (static_cast<float>(_windowSize.height) - _buttonSize.y) / 2.f;

	_menu->AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY - 100), _snakeButtonText, sf::Color(201, 209, 180), [this](){MainMenu::OnSnakeGameChosen();}));
	_menu->AddButton( new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY + 100), _minesweeperButtonText, sf::Color(23, 138, 50), [this](){MainMenu::OnMinesweeperChanged();}));
}

MainMenu::~MainMenu()
{
	delete _menu;
	delete _snakeMenu;
	delete _minesweeperMenu;
}