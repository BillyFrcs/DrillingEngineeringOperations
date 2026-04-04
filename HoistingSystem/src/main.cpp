#include "HoistingSystem/Application/Application.h"

int main(int argc, char* argv[])
{
	auto app = std::make_unique<HoistingSystem::Application>();

	app->Run();

	return EXIT_SUCCESS;
}