#include "KillWeightMud.h"

DrillingSystem::KillWeightMud::KillWeightMud(double currentMudWeight, double SIDPP, double trueVerticalDepth)
{
	m_CurrentMudWeight = currentMudWeight;
	m_SIDPP = SIDPP;
	m_TrueVerticalDepth = trueVerticalDepth;
}

DrillingSystem::KillWeightMud::~KillWeightMud()
{
}

double DrillingSystem::KillWeightMud::ImperialCalculation()
{
	double killWeightMud = m_CurrentMudWeight + (m_SIDPP / (0.052 * m_TrueVerticalDepth));

	return killWeightMud;
}

double DrillingSystem::KillWeightMud::MetricCalculation()
{
	double killWeightMud = m_CurrentMudWeight + (m_SIDPP / 0.00981 / m_TrueVerticalDepth);

	return 	killWeightMud;
}