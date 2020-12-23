#pragma once
#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include <vector>
#include <random>
#include <SFML/Graphics.hpp>

namespace GameSpace
{
	class Field;

	class Primitive
	{
		bool haveDownBorder(Field& field);
		void normalize();
	public:
		enum class BlockColor
		{
			EMPTY, RED, GREEN, BLUE, YELLOW,
			CFFFF66, CFFCC33, CFF6600, CFF0066, CFF0099,
			CCC00CC, C6600CC, C3300CC, C00CCFF, C33FFCC,
			C33FF66, C33FF00, CCCFF33, C999999
		};
		static const int blockSize = 20;
		static void drawBlock(sf::RenderWindow& render, int positionX, int positionY, BlockColor color);
		
		Primitive(const std::vector<std::vector<bool>>& tpl, std::default_random_engine& dre, int positionX, int positionY);
		void doDraw(sf::RenderWindow& render);
		bool doLogic(Field& field);
		void rotRight(Field& field);
		void rotLeft(Field& field);
		void moveRight(Field& field);
		void moveLeft(Field& field);
		void doDrawAt(sf::RenderWindow& render, int positionX, int positionY);
	protected:
		std::vector<std::vector<BlockColor>> scheme;
		int posX, posY, state;
	};

	class Field
	{
		std::vector<std::vector<Primitive::BlockColor>> field;
	public:
		Field() = default;
		Field(int width, int height);
		void doDraw(sf::RenderWindow& render);
		bool isEmpty(int x, int y);
		void setColor(int x, int y, Primitive::BlockColor color);
		bool isFinal();
		int erasing();
	};

	class J_Block :public Primitive
	{
	public:
		J_Block(std::default_random_engine& dre, int positionX, int positionY);
	};

	class L_Block :public Primitive
	{
	public:
		L_Block(std::default_random_engine& dre, int positionX, int positionY);
	};

	class T_Block :public Primitive
	{
	public:
		T_Block(std::default_random_engine& dre, int positionX, int positionY);
	};


	class O_Block :public Primitive
	{
	public:
		O_Block(std::default_random_engine& dre, int positionX, int positionY);
	};

	class S_Block :public Primitive
	{
	public:
		S_Block(std::default_random_engine& dre, int positionX, int positionY);
	};

	class Z_Block :public Primitive
	{
	public:
		Z_Block(std::default_random_engine& dre, int positionX, int positionY);
	};

	class I_Block :public Primitive
	{
	public:
		I_Block(std::default_random_engine& dre, int positionX, int positionY);
	};

	Primitive* getPrimitive(std::default_random_engine& dre, int positionX, int positionY);
}

#endif // !PRIMITIVE_H