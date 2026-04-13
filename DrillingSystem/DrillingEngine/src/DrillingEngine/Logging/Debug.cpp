#include "Debug.h"

DrillingSystem::Debug::Debug()
{
	m_DrillingEngine = std::make_unique<DrillingSystem::DrillingEngine>();
}

DrillingSystem::Debug::~Debug()
{
}

void DrillingSystem::Debug::EquivalentCirculatingDensity()
{
	DrillingLog(m_DrillingEngine->ImperialEquivalentCirculatingDensity(12.2, 400, 12000));
	DrillingLog(m_DrillingEngine->MetricEquivalentCirculatingDensity(1200, 2760, 2440));
}

void DrillingSystem::Debug::HydrostaticPressure()
{
	DrillingLog(m_DrillingEngine->ImperialHydrostaticPressure(12.2, 12000));
	DrillingLog(m_DrillingEngine->MetricHydrostaticPressure(1200, 2440));
}

void DrillingSystem::Debug::KillWeightMud()
{
	DrillingLog(m_DrillingEngine->ImperialKillWeightMud(9.5, 500, 9000));
	DrillingLog(m_DrillingEngine->MetricKillWeightMud(1140, 3450, 2700));
}

void DrillingSystem::Debug::Run()
{
	EquivalentCirculatingDensity();

	HydrostaticPressure();

	KillWeightMud();

	/*
	DrillingSystem::DrillingEngine de;
	DrillingSystem::DrillingEngine* drillingEngine = de.Create();

	// DEBUG: Check if the pointer is null before using it
	DrillingLog(drillingEngine->ImperialEquivalentCirculatingDensity(12.2, 400, 12000));
	DrillingLog(drillingEngine->MetricEquivalentCirculatingDensity(1200, 2760, 2440));

	DrillingLog(drillingEngine->ImperialHydrostaticPressure(12.2, 12000));
	DrillingLog(drillingEngine->MetricHydrostaticPressure(1200, 2440));

	drillingEngine->Destroy(drillingEngine);
	*/
}

template <typename T>
void DrillingSystem::Debug::DrillingLog(const T& value)
{
	spdlog::info(value);
}