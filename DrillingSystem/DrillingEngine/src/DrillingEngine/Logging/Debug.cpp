#include "Debug.h"

DrillingSystem::DrillingEngine::Debug::Debug()
{
	m_DrillingEngine = std::make_unique<DrillingSystem::DrillingEngine::DrillingEngine>();
}

DrillingSystem::DrillingEngine::Debug::~Debug()
{
}

void DrillingSystem::DrillingEngine::Debug::EquivalentCirculatingDensity()
{
	DrillingLog(m_DrillingEngine->ImperialEquivalentCirculatingDensity(12.2, 400, 12000));
	DrillingLog(m_DrillingEngine->MetricEquivalentCirculatingDensity(1200, 2760, 2440));
}

void DrillingSystem::DrillingEngine::Debug::HydrostaticPressure()
{
	DrillingLog(m_DrillingEngine->ImperialHydrostaticPressure(12.2, 12000));
	DrillingLog(m_DrillingEngine->MetricHydrostaticPressure(1200, 2440));
}

void DrillingSystem::DrillingEngine::Debug::KillWeightMud()
{
	DrillingLog(m_DrillingEngine->ImperialKillWeightMud(9.5, 500, 9000));
	DrillingLog(m_DrillingEngine->MetricKillWeightMud(1140, 3450, 2700));
}

void DrillingSystem::DrillingEngine::Debug::Run()
{
	EquivalentCirculatingDensity();

	HydrostaticPressure();

	KillWeightMud();
}

template <typename T>
void DrillingSystem::DrillingEngine::Debug::DrillingLog(const T& value)
{
	spdlog::info(value);
}