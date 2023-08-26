#include "tetris-game-menu.h"

TetrisMenu::TetrisMenu(const sf::Font& textFont, class MainMenu* mainMenu) : _textFont(textFont), _mainMenu(mainMenu)
{
	Initialize();
}

void TetrisMenu::Initialize()
{

	_textSize = 28;
	_windowSize = sf::VideoMode(450, 800);
	_buttonSize = sf::Vector2f(270, 70);

	_menu = new ArcadeGame::Menu(sf::Color(42, 51, 82), _windowSize, "Tetris", sf::Style::Titlebar | sf::Style::Close);

	CreateTexts();
	CreateButtons();
}

void TetrisMenu::Open()
{
	_menu->Open();
}

void TetrisMenu::Close()
{
	_menu->Close();
}

void TetrisMenu::OnEasyLevelChosen() const
{

}

void TetrisMenu::OnNormalLevelChosen() const
{

}

void TetrisMenu::OnHardLevelChosen() const
{

}

void TetrisMenu::OnReturnChosen()
{
	Close();
	_mainMenu->Open();
}

void TetrisMenu::CreateTexts()
{
	sf::Text title("TETRIS", _textFont, 62);

	_playButtonText = sf::Text("PLAY", _textFont, _textSize);
	_returnButtonText = sf::Text("Return to Menu", _textFont, _textSize);

	_playButtonText.setFillColor(sf::Color(136, 46, 232));
	_returnButtonText.setFillColor(sf::Color(191, 161, 40));


	title.setPosition(((float)_windowSize.width - title.getGlobalBounds().width) / 2, ((float)_windowSize.height - title.getGlobalBounds().height) / 2 - 250);
	title.setFillColor(sf::Color(242, 155, 5));

	_menu->AddText(title);
}

void TetrisMenu::CreateButtons()
{

	float centerX = (static_cast<float>(_windowSize.width) - _buttonSize.x) / 2.f;
	float centerY = (static_cast<float>(_windowSize.height) - _buttonSize.y) / 2.f;

	_menu->AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY), _playButtonText, sf::Color(132, 173, 139), [this](){OnEasyLevelChosen();}));
	_menu->AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY + 250), _returnButtonText, sf::Color(171, 218, 222), [this]() {OnReturnChosen();}));
}

TetrisMenu::~TetrisMenu()
{
	delete _menu;
}
