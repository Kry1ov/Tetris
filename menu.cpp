#include "menu.h"

using namespace sf;

namespace GameSpace
{
	Menu::Menu(const std::string& fontPath) :selSize(FieldSize::STANDART)
	{
		if (!menuFont.loadFromFile(fontPath))
			throw std::runtime_error("GameSpace::Menu::Menu !menuFont.loadFromFile(\"resource\\gamefont.ttf\")");

		

		menuItemSizeStd.setFont(menuFont);
		menuItemSizeStd.setString("Standart size");
		menuItemSizeStd.setCharacterSize(32);
		menuItemSizeStd.setFillColor(Color(0xCC, 0x00, 0x33));
		menuItemSizeStd.setStyle(Text::Bold);

		menuItemSizeMax.setFont(menuFont);
		menuItemSizeMax.setString("Maximal size");
		menuItemSizeMax.setCharacterSize(32);
		menuItemSizeMax.setFillColor(Color(0xCC, 0x00, 0x33));
		menuItemSizeMax.setStyle(Text::Bold);

		menuItemStartGame.setFont(menuFont);
		menuItemStartGame.setString("Start Game");
		menuItemStartGame.setCharacterSize(32);
		menuItemStartGame.setFillColor(Color(0xCC, 0x00, 0x33));
		menuItemStartGame.setStyle(Text::Bold);

		menuItemExitGame.setFont(menuFont);
		menuItemExitGame.setString("Exit Game");
		menuItemExitGame.setCharacterSize(32);
		menuItemExitGame.setFillColor(Color(0xCC, 0x00, 0x33));
		menuItemExitGame.setStyle(Text::Bold);

		description.setFont(menuFont);
		description.setString("Key for game:\nX,C - rotate block\nLeft, Right - move block\nDown - speed up\nP - pause\nEsc - menu");
		description.setCharacterSize(24);
		description.setFillColor(Color(0xCC, 0x00, 0x33));
		description.setStyle(Text::Bold);
	}

	void Menu::doDraw(sf::RenderWindow& render)
	{
		Vector2u windowSize = render.getSize();
		Vector2f centerPosition = render.mapPixelToCoords(Vector2i(static_cast<int>(windowSize.x / 2.0), 10));

		RectangleShape selSizeButton;

		

		menuItemSizeMin.setPosition(Vector2f(centerPosition.x - menuItemSizeMin.getLocalBounds().width / 2.f, centerPosition.y));
		render.draw(menuItemSizeMin);

		

		centerPosition.y += menuItemSizeMin.getLocalBounds().height + 10;

		

		menuItemSizeStd.setPosition(Vector2f(centerPosition.x - menuItemSizeStd.getLocalBounds().width / 2.f, centerPosition.y));
		render.draw(menuItemSizeStd);

		if (selSize == FieldSize::STANDART)
		{
			selSizeButton.setSize(Vector2f(menuItemSizeStd.getLocalBounds().width + 4.f, menuItemSizeStd.getLocalBounds().height + 4.f));
			selSizeButton.setPosition(Vector2f(menuItemSizeStd.getPosition().x - 2.f, menuItemSizeStd.getPosition().y - 2.f));
			selSizeButton.setFillColor(Color::Transparent);
			selSizeButton.setOutlineColor(Color(0xCC, 0x00, 0x33));
			selSizeButton.setOutlineThickness(2.f);
			render.draw(selSizeButton);
		}

		centerPosition.y += menuItemSizeStd.getLocalBounds().height + 10;

		

		menuItemSizeMax.setPosition(Vector2f(centerPosition.x - menuItemSizeMax.getLocalBounds().width / 2.f, centerPosition.y));
		render.draw(menuItemSizeMax);

		if (selSize == FieldSize::MAXIMAL)
		{
			selSizeButton.setSize(Vector2f(menuItemSizeMax.getLocalBounds().width + 4.f, menuItemSizeMax.getLocalBounds().height + 4.f));
			selSizeButton.setPosition(Vector2f(menuItemSizeMax.getPosition().x - 2.f, menuItemSizeMax.getPosition().y - 2.f));
			selSizeButton.setFillColor(Color::Transparent);
			selSizeButton.setOutlineColor(Color(0xCC, 0x00, 0x33));
			selSizeButton.setOutlineThickness(2.f);
			render.draw(selSizeButton);
		}

		centerPosition.y += menuItemSizeMax.getLocalBounds().height + 10;

		
		menuItemStartGame.setPosition(Vector2f(centerPosition.x - menuItemStartGame.getLocalBounds().width / 2.f, centerPosition.y));
		render.draw(menuItemStartGame);

		RectangleShape startGameButton(Vector2f(menuItemStartGame.getLocalBounds().width + 4.f, menuItemStartGame.getLocalBounds().height + 4.f));
		startGameButton.setPosition(Vector2f(menuItemStartGame.getPosition().x - 2.f, menuItemStartGame.getPosition().y - 2.f));
		startGameButton.setFillColor(Color::Transparent);
		startGameButton.setOutlineColor(Color(0xCC, 0x00, 0x33));
		startGameButton.setOutlineThickness(2.f);
		render.draw(startGameButton);

		centerPosition.y += menuItemStartGame.getLocalBounds().height + 10;
		

		menuItemExitGame.setPosition(Vector2f(centerPosition.x - menuItemExitGame.getLocalBounds().width / 2.f, centerPosition.y));
		render.draw(menuItemExitGame);

		RectangleShape exitGameButton(Vector2f(menuItemExitGame.getLocalBounds().width + 4.f, menuItemExitGame.getLocalBounds().height + 4.f));
		exitGameButton.setPosition(Vector2f(menuItemExitGame.getPosition().x - 2.f, menuItemExitGame.getPosition().y - 2.f));
		exitGameButton.setFillColor(Color::Transparent);
		exitGameButton.setOutlineColor(Color(0xCC, 0x00, 0x33));
		exitGameButton.setOutlineThickness(2.f);
		render.draw(exitGameButton);

		centerPosition.y += menuItemExitGame.getLocalBounds().height + 50;
		

		description.setPosition(Vector2f(centerPosition.x, centerPosition.y));
		render.draw(description);
	}

	bool Menu::doEvent(const Event& evItem, sf::RenderWindow& render)
	{
		if (evItem.type == Event::MouseButtonPressed)
		{
			Vector2f point = render.mapPixelToCoords(Vector2i(evItem.mouseButton.x, evItem.mouseButton.y));
			 if (menuItemSizeStd.getGlobalBounds().contains(point))
				selSize = FieldSize::STANDART;
			else if (menuItemSizeMax.getGlobalBounds().contains(point))
				selSize = FieldSize::MAXIMAL;
			else if (menuItemExitGame.getGlobalBounds().contains(point))
				render.close();
			else if (menuItemStartGame.getGlobalBounds().contains(point))
				return true;
		}
		return false;
	}
}