#include "DrillingEngine.h"

DrillingSystem::DrillingEngine::DrillingEngine::DrillingEngine()
{
}

DrillingSystem::DrillingEngine::DrillingEngine::~DrillingEngine()
{
}

double DrillingSystem::DrillingEngine::DrillingEngine::ImperialEquivalentCirculatingDensity(double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet)
{
	auto ecd = std::make_unique<DrillingSystem::DrillingEngine::EquivalentCirculatingDensity>(mudWeight_ppg, pressureLoss_psi, trueVerticalDepth_feet);

	return ecd->ImperialCalculation();
}

double DrillingSystem::DrillingEngine::DrillingEngine::MetricEquivalentCirculatingDensity(double mudWeight_kg_m3, double pressureLoss_kPa, double trueVerticalDepth_meter)
{
	auto ecd = std::make_unique<DrillingSystem::DrillingEngine::EquivalentCirculatingDensity>(mudWeight_kg_m3, pressureLoss_kPa, trueVerticalDepth_meter);

	return ecd->MetricCalculation();
}

double DrillingSystem::DrillingEngine::DrillingEngine::ImperialHydrostaticPressure(double mudWeight_ppg, double trueVerticalDepth_feet)
{
	auto hp = std::make_unique<DrillingSystem::DrillingEngine::HydrostaticPressure>(mudWeight_ppg, trueVerticalDepth_feet);

	return hp->ImperialCalculation();
}

double DrillingSystem::DrillingEngine::DrillingEngine::MetricHydrostaticPressure(double mudWeight_kg_m3, double trueVerticalDepth_meter)
{
	auto hp = std::make_unique<DrillingSystem::DrillingEngine::HydrostaticPressure>(mudWeight_kg_m3, trueVerticalDepth_meter);
	
	return hp->MetricCalculation();
}

double DrillingSystem::DrillingEngine::DrillingEngine::ImperialKillWeightMud(double currentMudWeight_ppg, double SIDPP_psi, double trueVerticalDepth_feet)
{
	auto kwm = std::make_unique<DrillingSystem::DrillingEngine::KillWeightMud>(currentMudWeight_ppg, SIDPP_psi, trueVerticalDepth_feet);

	return kwm->ImperialCalculation();
}

double DrillingSystem::DrillingEngine::DrillingEngine::MetricKillWeightMud(double currentMudWeight_kg_m3, double SIDPP_KPa, double trueVerticalDepth_meter)
{
	auto kwm = std::make_unique<DrillingSystem::DrillingEngine::KillWeightMud>(currentMudWeight_kg_m3, SIDPP_KPa, trueVerticalDepth_meter);

	return kwm->MetricCalculation();
}