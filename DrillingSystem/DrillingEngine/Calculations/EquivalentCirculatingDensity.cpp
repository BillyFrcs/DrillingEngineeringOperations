#include "EquivalentCirculatingDensity.h"

DrillingSystem::EquivalentCirculatingDensity::EquivalentCirculatingDensity()
{
}

DrillingSystem::EquivalentCirculatingDensity::~EquivalentCirculatingDensity()
{
}

double DrillingSystem::EquivalentCirculatingDensity::ImperialCalculation(double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet)
{
	return mudWeight_ppg + (pressureLoss_psi / (0.052 * trueVerticalDepth_feet));

	// Another imperial ECD formula is (pressureLoss_psi / 0.052 / trueVerticalDepth_feet) + mudWeight_ppg;
}

double DrillingSystem::EquivalentCirculatingDensity::MetricCalculation(double mudWeight_sg, double pressureLoss_bar, double trueVerticalDepth_meter)
{
	// mudWeight -> kg/m^3
	// pressureLoss -> kPa
	// trueVerticalDepth -> m
	return mudWeight_sg + (pressureLoss_bar * 1000 / 9.81 / trueVerticalDepth_meter);
}