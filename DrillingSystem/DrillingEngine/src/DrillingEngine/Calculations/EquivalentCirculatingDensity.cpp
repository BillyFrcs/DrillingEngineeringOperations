#include "EquivalentCirculatingDensity.h"

DrillingSystem::DrillingEngine::EquivalentCirculatingDensity::EquivalentCirculatingDensity(double mudWeight, double annularPressureLoss, double trueVerticalDepth)
{
	m_MudWeight = mudWeight;
	m_AnnularPressureLoss = annularPressureLoss;
	m_TrueVerticalDepth = trueVerticalDepth;
}

DrillingSystem::DrillingEngine::EquivalentCirculatingDensity::~EquivalentCirculatingDensity()
{
}

double DrillingSystem::DrillingEngine::EquivalentCirculatingDensity::ImperialCalculation()
{
	double equivalentCirculatingDensity = m_MudWeight + (m_AnnularPressureLoss / (0.052 * m_TrueVerticalDepth));

	return equivalentCirculatingDensity;

	// Another imperial ECD formula is m_MudWeight + (m_AnnularPressureLoss / 0.052 / m_TrueVerticalDepth);
}

double DrillingSystem::DrillingEngine::EquivalentCirculatingDensity::MetricCalculation()
{
	double equivalentCirculatingDensity = m_MudWeight + (m_AnnularPressureLoss * 1000.0 / 9.81 / m_TrueVerticalDepth);

	return 	equivalentCirculatingDensity;
}