#include "main-menu.h"
#include "button.h"

#include "easy_level.h"
#include "hard_level.h"
#include "normal_level.h"
#include "witch_level.h"


Menu::Menu(size_t textSize, const sf::Vector2f& buttonSize, const sf::VideoMode& windowSize, const sf::Font& textFont) :
		  _menu(sf::Color(42, 51, 82), windowSize, "SnakeGame", sf::Style::Titlebar | sf::Style::Close)
{
	Initialize(textSize, buttonSize, windowSize, textFont);
}


void Menu::Initialize(size_t textSize, const sf::Vector2f& buttonSize, const sf::VideoMode& windowSize, const sf::Font& textFont)
{

	sf::Text easyButtonText("Easy Level", textFont, textSize);
	sf::Text normalButtonText("Normal Level", textFont, textSize);
	sf::Text witchButtonText("Witch Level", textFont, textSize);
	sf::Text hardButtonText("Hard Level", textFont, textSize);

	easyButtonText.setFillColor(sf::Color(235, 38, 176));
	normalButtonText.setFillColor(sf::Color(235, 195, 87));
	hardButtonText.setFillColor(sf::Color(120, 28, 117));
	witchButtonText.setFillColor(sf::Color(33, 207, 111));

	float centerX = (static_cast<float>(windowSize.width) - buttonSize.x) / 2.f;
	float centerY = (static_cast<float>(windowSize.height) - buttonSize.y) / 2.f;


	_menu.AddButton(new ArcadeGame::Button(buttonSize, sf::Vector2f(centerX, centerY - 200), easyButtonText, sf::Color(201, 209, 180), [this](){Menu::OnEasyLevelChosen();}));
	_menu.AddButton( new ArcadeGame::Button(buttonSize, sf::Vector2f(centerX, centerY -100), normalButtonText, sf::Color(23, 138, 50), [this](){OnNormalLevelChosen();}));
	_menu.AddButton(new ArcadeGame::Button(buttonSize, sf::Vector2f(centerX, centerY), hardButtonText, sf::Color(194, 129, 25), [this](){Menu::OnHardLevelChosen();}));
	_menu.AddButton(new ArcadeGame::Button(buttonSize, sf::Vector2f(centerX, centerY + 100), witchButtonText, sf::Color(142, 68, 227), [this]() {Menu::OnWitchLevelChosen();}));

}

void Menu::Open() 
{
	_menu.Open();
}


void Menu::OnEasyLevelChosen() const
{
	EasyLevel(sf::Color::Black).StartGame();
}

void Menu::OnNormalLevelChosen() const 
{
	NormalLevel(sf::Color(4, 14, 64)).StartGame();
}

void Menu::OnHardLevelChosen() const
{
	HardLevel(sf::Color(20, 56, 29)).StartGame();
}

void Menu::OnWitchLevelChosen() const
{
	WitchLevel(sf::Color(57, 7, 79)).StartGame();
}
