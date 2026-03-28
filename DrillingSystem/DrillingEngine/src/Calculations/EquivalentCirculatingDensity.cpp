#include "EquivalentCirculatingDensity.h"

DrillingSystem::EquivalentCirculatingDensity::EquivalentCirculatingDensity(double mudWeight, double pressureLoss, double trueVerticalDepth)
{
	m_MudWeight = mudWeight;
	m_PressureLoss = pressureLoss;
	m_TrueVerticalDepth = trueVerticalDepth;
}

DrillingSystem::EquivalentCirculatingDensity::~EquivalentCirculatingDensity()
{
}

double DrillingSystem::EquivalentCirculatingDensity::ImperialCalculation()
{
	return m_MudWeight + (m_PressureLoss / (0.052 * m_TrueVerticalDepth));

	// Another imperial ECD formula is m_MudWeight + (m_PressureLoss / 0.052 / m_TrueVerticalDepth);
}

double DrillingSystem::EquivalentCirculatingDensity::MetricCalculation()
{
	return m_MudWeight + (m_PressureLoss * 1000 / 9.81 / m_TrueVerticalDepth);
}