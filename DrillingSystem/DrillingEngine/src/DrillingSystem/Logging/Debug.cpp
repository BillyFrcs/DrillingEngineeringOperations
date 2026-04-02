#include "Debug.h"

DrillingSystem::Debug::Debug()
{
}

DrillingSystem::Debug::~Debug()
{
}

void DrillingSystem::Debug::Run()
{
	DrillingSystem::DrillingEngine de;
	DrillingSystem::DrillingEngine* drillingEngine = de.Create();

	// DEBUG: Check if the pointer is null before using it
	DrillingLog(drillingEngine->ImperialEquivalentCirculatingDensity(12.2, 400, 12000));
	DrillingLog(drillingEngine->MetricEquivalentCirculatingDensity(1200, 2760, 2440));

	DrillingLog(drillingEngine->ImperialHydrostaticPressure(12.2, 12000));
	DrillingLog(drillingEngine->MetricHydrostaticPressure(1200, 2440));

	drillingEngine->Destroy(drillingEngine);
}

template <typename T>
void DrillingSystem::Debug::DrillingLog(const T& value)
{
	spdlog::info(value);
}