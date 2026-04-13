#pragma once

#ifndef KILL_WEIGHT_MUD_H
#define KILL_WEIGHT_MUD_H

namespace DrillingSystem::DrillingEngine
{
	class KillWeightMud
	{
	public:
		KillWeightMud(double currentMudWeight, double SIDPP, double trueVerticalDepth);

		~KillWeightMud();

		double ImperialCalculation();

		double MetricCalculation();

	private:
		double m_CurrentMudWeight;
		double m_SIDPP;
		double m_TrueVerticalDepth;
	};
}

#endif // KILL_WEIGHT_MUD_H