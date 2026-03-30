#include "Application.h"

DrillingSystem::Application::Application()
{
}

DrillingSystem::Application::~Application()
{
}

void DrillingSystem::Application::Run()
{
	DrillingSystem::DrillingEngine de;
	DrillingSystem::DrillingEngine* drillingEngine = de.Create();

	// DEBUG: Check if the pointer is null before using it
	std::clog << drillingEngine->ImperialEquivalentCirculatingDensity(12.2, 400, 12000) << std::endl;
	std::clog << drillingEngine->MetricEquivalentCirculatingDensity(1200, 2760, 2440) << std::endl;

	std::clog << drillingEngine->ImperialHydrostaticPressure(12.2, 12000) << std::endl;
	std::clog << drillingEngine->MetricHydrostaticPressure(1200, 2440) << std::endl;

	drillingEngine->Destroy(drillingEngine);

	/*
	// Default object instantiation and method calls
	DrillingSystem::DrillingEngine drillingEngine;

	std::cout << drillingEngine.ImperialEquivalentCirculatingDensity(12.2, 400, 12000) << std::endl;
	std::cout << drillingEngine.MetricEquivalentCirculatingDensity(1200, 2760, 2440) << std::endl;
	*/
}
