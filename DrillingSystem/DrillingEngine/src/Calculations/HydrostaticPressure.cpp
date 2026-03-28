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
	return m_MudWeight * 0.052 * m_TrueVerticalDepth;
}

double DrillingSystem::HydrostaticPressure::MetricCalculation()
{
	return m_MudWeight * 9.81 * m_TrueVerticalDepth / 1000;
}