#include <OGL3D/Windows/OGame.h>
#include <glad/glad.h>
#include <glad/glad_wgl.h>
#include <iostream>
#include <locale>

int main()
{
	try
	{
		SetConsoleOutputCP(CP_UTF8);
		std::locale::global(std::locale("en_US.UTF-8"));
		OGame game;
		game.Run();
	} 
	catch (const std::exception& e)
	{
		std::wclog << e.what() << std::endl;
		return 1;
	}
	
}