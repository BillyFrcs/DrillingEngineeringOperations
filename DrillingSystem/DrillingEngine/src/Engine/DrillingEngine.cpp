#include "DrillingEngine.h"

DrillingSystem::DrillingEngine::DrillingEngine()
{
}

DrillingSystem::DrillingEngine::~DrillingEngine()
{
}

DrillingSystem::DrillingEngine* DrillingSystem::DrillingEngine::CreateDrillingEngine()
{
	auto drillingEngine = std::make_unique<DrillingSystem::DrillingEngine>();

	return drillingEngine.release();
}

double DrillingSystem::DrillingEngine::ImperialEquivalentCirculatingDensity(double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet)
{
	auto ecd = std::make_unique<DrillingSystem::EquivalentCirculatingDensity>(mudWeight_ppg, pressureLoss_psi, trueVerticalDepth_feet);

	return ecd->ImperialCalculation();

	ecd.release();
}

double DrillingSystem::DrillingEngine::MetricEquivalentCirculatingDensity(double mudWeight_sg, double pressureLoss_bar, double trueVerticalDepth_meter)
{
	auto ecd = std::make_unique<DrillingSystem::EquivalentCirculatingDensity>(mudWeight_sg, pressureLoss_bar, trueVerticalDepth_meter);

	return ecd->MetricCalculation();

	ecd.release();
}

double DrillingSystem::DrillingEngine::ImperialHydrostaticPressure(double mudWeight_ppg, double trueVerticalDepth_feet)
{
	auto hp = std::make_unique<DrillingSystem::HydrostaticPressure>(mudWeight_ppg, trueVerticalDepth_feet);

	return hp->ImperialCalculation();

	hp.release();
}

double DrillingSystem::DrillingEngine::MetricHydrostaticPressure(double mudWeight_sg, double trueVerticalDepth_meter)
{
	auto hp = std::make_unique<DrillingSystem::HydrostaticPressure>(mudWeight_sg, trueVerticalDepth_meter);
	
	return hp->MetricCalculation();
	
	hp.release();
}

void DrillingSystem::DrillingEngine::DestroyDrillingEngine(DrillingEngine* drillingEngine)
{
	std::unique_ptr<DrillingSystem::DrillingEngine> drillingEnginePtr(drillingEngine);
}