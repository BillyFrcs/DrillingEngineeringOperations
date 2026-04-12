#include "DrillingEngine.h"

DrillingSystem::DrillingEngine::DrillingEngine()
{
}

DrillingSystem::DrillingEngine::~DrillingEngine()
{
}

DrillingSystem::DrillingEngine* DrillingSystem::DrillingEngine::Create()
{
	auto drillingEngine = std::make_unique<DrillingSystem::DrillingEngine>();

	return drillingEngine.release();
}

double DrillingSystem::DrillingEngine::ImperialEquivalentCirculatingDensity(double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet)
{
	auto ecd = std::make_unique<DrillingSystem::EquivalentCirculatingDensity>(mudWeight_ppg, pressureLoss_psi, trueVerticalDepth_feet);

	return ecd->ImperialCalculation();
}

double DrillingSystem::DrillingEngine::MetricEquivalentCirculatingDensity(double mudWeight_sg, double pressureLoss_bar, double trueVerticalDepth_meter)
{
	auto ecd = std::make_unique<DrillingSystem::EquivalentCirculatingDensity>(mudWeight_sg, pressureLoss_bar, trueVerticalDepth_meter);

	return ecd->MetricCalculation();
}

double DrillingSystem::DrillingEngine::ImperialHydrostaticPressure(double mudWeight_ppg, double trueVerticalDepth_feet)
{
	auto hp = std::make_unique<DrillingSystem::HydrostaticPressure>(mudWeight_ppg, trueVerticalDepth_feet);

	return hp->ImperialCalculation();
}

double DrillingSystem::DrillingEngine::MetricHydrostaticPressure(double mudWeight_sg, double trueVerticalDepth_meter)
{
	auto hp = std::make_unique<DrillingSystem::HydrostaticPressure>(mudWeight_sg, trueVerticalDepth_meter);
	
	return hp->MetricCalculation();
}

double DrillingSystem::DrillingEngine::ImperialKillWeightMud(double currentMudWeight_ppg, double SIDPP_psi, double trueVerticalDepth_feet)
{
	auto kwm = std::make_unique<DrillingSystem::KillWeightMud>(currentMudWeight_ppg, SIDPP_psi, trueVerticalDepth_feet);

	return kwm->ImperialCalculation();
}

double DrillingSystem::DrillingEngine::MetricKillWeightMud(double currentMudWeight_kg_m3, double SIDPP_KPa, double trueVerticalDepth_meter)
{
	auto kwm = std::make_unique<DrillingSystem::KillWeightMud>(currentMudWeight_kg_m3, SIDPP_KPa, trueVerticalDepth_meter);

	return kwm->MetricCalculation();
}

void DrillingSystem::DrillingEngine::Destroy(DrillingEngine* drillingEngine)
{
	std::unique_ptr<DrillingSystem::DrillingEngine> drillingEnginePtr(drillingEngine);
}