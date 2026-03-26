#include "DrillingEngine.h"

DrillingSystem::DrillingEngine::DrillingEngine()
{
}

DrillingSystem::DrillingEngine::~DrillingEngine()
{
}

double DrillingSystem::DrillingEngine::ImperialEquivalentCirculatingDensity(double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet)
{
	return DrillingSystem::EquivalentCirculatingDensity::ImperialCalculation(mudWeight_ppg, pressureLoss_psi, trueVerticalDepth_feet);
}

double DrillingSystem::DrillingEngine::MetricEquivalentCirculatingDensity(double mudWeight_sg, double pressureLoss_bar, double trueVerticalDepth_meter)
{
	return DrillingSystem::EquivalentCirculatingDensity::MetricCalculation(mudWeight_sg, pressureLoss_bar, trueVerticalDepth_meter);
}
