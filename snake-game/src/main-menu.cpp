#include "main-menu.h"
#include "button.h"

#include "easy_level.h"
#include "hard_level.h"
#include "normal_level.h"
#include "witch_level.h"

SnakeGame::MainMenu::MainMenu(size_t textSize, const sf::Vector2f& buttonSize, const sf::VideoMode& windowSize, const sf::Font& textFont) :
		_menu(sf::Color(42, 51, 82), windowSize, "Minesweeper", sf::Style::Titlebar | sf::Style::Close),
		_textSize(textSize), _windowSize(windowSize), _textFont(textFont), _buttonSize(buttonSize)
{
	Initialize();
}


void SnakeGame::MainMenu::Initialize()
{
	CreateTexts();
	CreateButtons();
}

void SnakeGame::MainMenu::Open()
{
	_menu.Open();
}


void SnakeGame::MainMenu::OnEasyLevelChosen() const
{
	EasyLevel(sf::Color::Black).StartGame();
}

void SnakeGame::MainMenu::OnNormalLevelChosen() const
{
	NormalLevel(sf::Color(4, 14, 64)).StartGame();
}

void SnakeGame::MainMenu::OnHardLevelChosen() const
{
	HardLevel(sf::Color(20, 56, 29)).StartGame();
}

void SnakeGame::MainMenu::OnWitchLevelChosen() const
{
	WitchLevel(sf::Color(57, 7, 79)).StartGame();
}

void SnakeGame::MainMenu::CreateTexts()
{

	auto* title = new sf::Text("SNAKE GAME", _textFont, 42);

	_easyButtonText = new sf::Text("Easy Level", _textFont, _textSize);
	_normalButtonText = new sf::Text("Normal Level", _textFont, _textSize);
	_hardButtonText = new sf::Text("Hard Level", _textFont, _textSize);
	_witchButtonText = new sf::Text("Witch Level", _textFont, _textSize);

	_easyButtonText->setFillColor(sf::Color(235, 38, 176));
	_normalButtonText->setFillColor(sf::Color(235, 195, 87));
	_hardButtonText->setFillColor(sf::Color(120, 28, 117));
	_witchButtonText->setFillColor(sf::Color(33, 207, 111));

	title->setPosition(((float)_windowSize.width - title->getGlobalBounds().width) / 2, ((float)_windowSize.height - title->getGlobalBounds().height) / 2 - 320);
	title->setFillColor(sf::Color(34, 200, 230));

	_menu.AddText(title);

}

void SnakeGame::MainMenu::CreateButtons()
{
	float centerX = (static_cast<float>(_windowSize.width) - _buttonSize.x) / 2.f;
	float centerY = (static_cast<float>(_windowSize.height) - _buttonSize.y) / 2.f;

	_menu.AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY - 200), *_easyButtonText, sf::Color(201, 209, 180), [this](){MainMenu::OnEasyLevelChosen();}));
	_menu.AddButton( new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY -100), *_normalButtonText, sf::Color(23, 138, 50), [this](){OnNormalLevelChosen();}));
	_menu.AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY), *_hardButtonText, sf::Color(194, 129, 25), [this](){MainMenu::OnHardLevelChosen();}));
	_menu.AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY + 100), *_witchButtonText, sf::Color(142, 68, 227), [this]() {MainMenu::OnWitchLevelChosen();}));

}

SnakeGame::MainMenu::~MainMenu()
{
	delete _easyButtonText;
	delete _normalButtonText;
	delete _hardButtonText;
	delete _witchButtonText;
}
