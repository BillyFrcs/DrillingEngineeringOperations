#include "HydrostaticPressure.h"

DrillingSystem::DrillingEngine::HydrostaticPressure::HydrostaticPressure(double mudWeight, double trueVerticalDepth)
{
	m_MudWeight = mudWeight;
	m_TrueVerticalDepth = trueVerticalDepth;
}

DrillingSystem::DrillingEngine::HydrostaticPressure::~HydrostaticPressure()
{
}

double DrillingSystem::DrillingEngine::HydrostaticPressure::ImperialCalculation()
{
	double hydrostaticPressure = m_MudWeight * 0.052 * m_TrueVerticalDepth;

	return hydrostaticPressure;
}

double DrillingSystem::DrillingEngine::HydrostaticPressure::MetricCalculation()
{
	double hydrostaticPressure = m_MudWeight * 9.81 * m_TrueVerticalDepth / 100000.0;

	return hydrostaticPressure;
}