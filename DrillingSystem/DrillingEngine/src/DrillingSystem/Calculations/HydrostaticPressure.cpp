#include "HydrostaticPressure.h"

DrillingSystem::HydrostaticPressure::HydrostaticPressure(double mudWeight, double trueVerticalDepth)
{
	m_MudWeight = mudWeight;
	m_TrueVerticalDepth = trueVerticalDepth;
}

DrillingSystem::HydrostaticPressure::~HydrostaticPressure()
{
}

double DrillingSystem::HydrostaticPressure::ImperialCalculation()
{
	double hydrostaticPressure = m_MudWeight * 0.052 * m_TrueVerticalDepth;

	return hydrostaticPressure;
}

double DrillingSystem::HydrostaticPressure::MetricCalculation()
{
	double hydrostaticPressure = m_MudWeight * 9.81 * m_TrueVerticalDepth / 1000;

	return hydrostaticPressure;
}