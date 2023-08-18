#include "main-menu.h"
#include "button.h"

#include "easy_level.h"
#include "hard_level.h"
#include "normal_level.h"
#include "witch_level.h"
#include "../../arcade-games/include/main-menu.h"

SnakeGame::MainMenu::MainMenu(const sf::Font& textFont) : _textFont(textFont)
{
	Initialize();
}

void SnakeGame::MainMenu::Initialize()
{

	_textSize = 28;
	_windowSize = sf::VideoMode(450, 800);
	_buttonSize = sf::Vector2f(240, 50);

	_menu = new ArcadeGame::Menu(sf::Color(42, 51, 82), _windowSize, "Snake Game", sf::Style::Titlebar | sf::Style::Close);

	CreateTexts();
	CreateButtons();
}

void SnakeGame::MainMenu::Open()
{
	_menu->Open();
}

void SnakeGame::MainMenu::Close()
{
	_menu->Close();
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

void SnakeGame::MainMenu::OnReturnChosen()
{
	Close();
	Games::Menu(_textFont).Open();
}

void SnakeGame::MainMenu::CreateTexts()
{

	auto* title = new sf::Text("SNAKE GAME", _textFont, 42);

	_easyButtonText = sf::Text("Easy Level", _textFont, _textSize);
	_normalButtonText =  sf::Text("Normal Level", _textFont, _textSize);
	_hardButtonText =  sf::Text("Hard Level", _textFont, _textSize);
	_witchButtonText = sf::Text("Witch Level", _textFont, _textSize);
	_returnButtonText = sf::Text("Return Menu", _textFont, _textSize);

	_easyButtonText.setFillColor(sf::Color(235, 38, 176));
	_normalButtonText.setFillColor(sf::Color(235, 195, 87));
	_hardButtonText.setFillColor(sf::Color(120, 28, 117));
	_witchButtonText.setFillColor(sf::Color(33, 207, 111));
	_returnButtonText.setFillColor(sf::Color(191, 161, 40));

	title->setPosition(((float)_windowSize.width - title->getGlobalBounds().width) / 2, ((float)_windowSize.height - title->getGlobalBounds().height) / 2 - 320);
	title->setFillColor(sf::Color(34, 200, 230));

	_menu->AddText(title);

}

void SnakeGame::MainMenu::CreateButtons()
{
	float centerX = (static_cast<float>(_windowSize.width) - _buttonSize.x) / 2.f;
	float centerY = (static_cast<float>(_windowSize.height) - _buttonSize.y) / 2.f;

	_menu->AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY - 200), _easyButtonText, sf::Color(201, 209, 180), [this](){MainMenu::OnEasyLevelChosen();}));
	_menu->AddButton( new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY -100), _normalButtonText, sf::Color(23, 138, 50), [this](){OnNormalLevelChosen();}));
	_menu->AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY), _hardButtonText, sf::Color(194, 129, 25), [this](){MainMenu::OnHardLevelChosen();}));
	_menu->AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY + 100), _witchButtonText, sf::Color(142, 68, 227), [this]() {MainMenu::OnWitchLevelChosen();}));
	_menu->AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY + 250), _returnButtonText, sf::Color(171, 218, 222), [this]() {MainMenu::OnReturnChosen();}));
}

SnakeGame::MainMenu::~MainMenu()
{
	delete _menu;
}