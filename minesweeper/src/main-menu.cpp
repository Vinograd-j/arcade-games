#include "main-menu.h"
#include "../../arcade-games/include/main-menu.h"

Minesweeper::MainMenu::MainMenu(const sf::Font& textFont) : _textFont(textFont)
{
	Initialize();
}

void Minesweeper::MainMenu::Initialize()
{

	_textSize = 28;
	_windowSize = sf::VideoMode(450, 800);
	_buttonSize = sf::Vector2f(240, 50);

	_menu = new ArcadeGame::Menu(sf::Color(42, 51, 82), _windowSize, "Minesweeper", sf::Style::Titlebar | sf::Style::Close);

	CreateTexts();
	CreateButtons();
}

void Minesweeper::MainMenu::Open()
{
	_menu->Open();
}

void Minesweeper::MainMenu::Close()
{
	_menu->Close();
}

void Minesweeper::MainMenu::OnEasyLevelChosen() const
{

}

void Minesweeper::MainMenu::OnNormalLevelChosen() const
{

}

void Minesweeper::MainMenu::OnHardLevelChosen() const
{

}

void Minesweeper::MainMenu::OnReturnChosen()
{
	Close();
	Games::Menu(_textFont).Open();
}

void Minesweeper::MainMenu::CreateTexts()
{
	auto* title = new sf::Text("MINESWEEPER", _textFont, 42);

	_easyButtonText = sf::Text("Easy Level", _textFont, _textSize);
	_normalButtonText =  sf::Text("Normal Level", _textFont, _textSize);
	_hardButtonText = sf::Text("Hard Level", _textFont, _textSize);
	_returnButtonText =  sf::Text("Return Menu", _textFont, _textSize);

	_easyButtonText.setFillColor(sf::Color(235, 38, 176));
	_normalButtonText.setFillColor(sf::Color(235, 195, 87));
	_hardButtonText.setFillColor(sf::Color(120, 28, 117));
	_returnButtonText.setFillColor(sf::Color(191, 161, 40));

	title->setPosition(((float)_windowSize.width - title->getGlobalBounds().width) / 2, ((float)_windowSize.height - title->getGlobalBounds().height) / 2 - 250);
	title->setFillColor(sf::Color(87, 227, 59));

	_menu->AddText(title);
}

void Minesweeper::MainMenu::CreateButtons()
{

	float centerX = (static_cast<float>(_windowSize.width) - _buttonSize.x) / 2.f;
	float centerY = (static_cast<float>(_windowSize.height) - _buttonSize.y) / 2.f;

	_menu->AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY - 100), _easyButtonText, sf::Color(201, 209, 180), [this](){MainMenu::OnEasyLevelChosen();}));
	_menu->AddButton( new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY), _normalButtonText, sf::Color(23, 138, 50), [this](){OnNormalLevelChosen();}));
	_menu->AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY + 100), _hardButtonText, sf::Color(194, 129, 25), [this](){MainMenu::OnHardLevelChosen();}));
	_menu->AddButton(new ArcadeGame::Button(_buttonSize, sf::Vector2f(centerX, centerY + 250), _returnButtonText, sf::Color(171, 218, 222), [this]() {MainMenu::OnReturnChosen();}));
}

Minesweeper::MainMenu::~MainMenu()
{
	delete _menu;
}
