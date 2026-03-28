#include "DrillingEngine.h"

DrillingSystem::DrillingEngine::DrillingEngine()
{
}

DrillingSystem::DrillingEngine::~DrillingEngine()
{
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
