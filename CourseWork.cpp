#include <iostream>
#include <exception>

#include "game.h"
using namespace GameSpace;

int main()
{
	try
	{
		Game tetris(640, 480, false);
		tetris.doWork();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << std::endl;
	}
	return 0;
}