#pragma once

#ifndef EQUIVALENT_CIRCULATING_DENSITY_H
#define EQUIVALENT_CIRCULATING_DENSITY_H

namespace DrillingSystem::DrillingEngine
{
	class EquivalentCirculatingDensity
	{
	public:
		EquivalentCirculatingDensity(double mudWeight, double pressureLoss, double trueVerticalDepth);

		~EquivalentCirculatingDensity();

		double ImperialCalculation();
		
		double MetricCalculation();

	private:
		double m_MudWeight;
		double m_PressureLoss;
		double m_TrueVerticalDepth;
	};
}

#endif // EQUIVALENT_CIRCULATING_DENSITY_H