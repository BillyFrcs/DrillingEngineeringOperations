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
	DrillingSystem::DrillingEngine::Logging::Info(m_DrillingEngine->ImperialEquivalentCirculatingDensity(12.2, 400, 12000));
	DrillingSystem::DrillingEngine::Logging::Info(m_DrillingEngine->MetricEquivalentCirculatingDensity(1200, 2760, 2440));
}

void DrillingSystem::DrillingEngine::Debug::HydrostaticPressure()
{
	DrillingSystem::DrillingEngine::Logging::Info(m_DrillingEngine->ImperialHydrostaticPressure(12.2, 12000));
	DrillingSystem::DrillingEngine::Logging::Info(m_DrillingEngine->MetricHydrostaticPressure(1200, 2440));
}

void DrillingSystem::DrillingEngine::Debug::KillWeightMud()
{
	DrillingSystem::DrillingEngine::Logging::Info(m_DrillingEngine->ImperialKillWeightMud(9.5, 500, 9000));
	DrillingSystem::DrillingEngine::Logging::Info(m_DrillingEngine->MetricKillWeightMud(1140, 3450, 2700));
}

void DrillingSystem::DrillingEngine::Debug::Run()
{
	EquivalentCirculatingDensity();

	HydrostaticPressure();

	KillWeightMud();
}