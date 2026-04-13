#include "KillWeightMud.h"

DrillingSystem::DrillingEngine::KillWeightMud::KillWeightMud(double currentMudWeight, double SIDPP, double trueVerticalDepth)
{
	m_CurrentMudWeight = currentMudWeight;
	m_SIDPP = SIDPP;
	m_TrueVerticalDepth = trueVerticalDepth;
}

DrillingSystem::DrillingEngine::KillWeightMud::~KillWeightMud()
{
}

double DrillingSystem::DrillingEngine::KillWeightMud::ImperialCalculation()
{
	double killWeightMud = m_CurrentMudWeight + (m_SIDPP / (0.052 * m_TrueVerticalDepth));

	return killWeightMud;
}

double DrillingSystem::DrillingEngine::KillWeightMud::MetricCalculation()
{
	double killWeightMud = m_CurrentMudWeight + (m_SIDPP / 0.00981 / m_TrueVerticalDepth);

	return 	killWeightMud;
}