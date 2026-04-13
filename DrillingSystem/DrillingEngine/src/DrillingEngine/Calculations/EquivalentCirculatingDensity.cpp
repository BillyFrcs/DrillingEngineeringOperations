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
	double equivalentCirculatingDensity = m_MudWeight + (m_PressureLoss / (0.052 * m_TrueVerticalDepth));

	return equivalentCirculatingDensity;

	// Another imperial ECD formula is m_MudWeight + (m_PressureLoss / 0.052 / m_TrueVerticalDepth);
}

double DrillingSystem::EquivalentCirculatingDensity::MetricCalculation()
{
	double equivalentCirculatingDensity = m_MudWeight + (m_PressureLoss * 1000 / 9.81 / m_TrueVerticalDepth);

	return 	equivalentCirculatingDensity;
}