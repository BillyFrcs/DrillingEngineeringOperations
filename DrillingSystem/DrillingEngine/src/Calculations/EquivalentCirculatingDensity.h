#pragma once

#include "DrillingSystem.h"

#ifndef EQUIVALENT_CIRCULATING_DENSITY_H
#define EQUIVALENT_CIRCULATING_DENSITY_H

namespace DrillingSystem
{
	class EquivalentCirculatingDensity
	{
	public:
		EquivalentCirculatingDensity();

		~EquivalentCirculatingDensity();

		static double ImperialCalculation(double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet);
		
		static double MetricCalculation(double mudWeight_sg, double pressureLoss_bar, double trueVerticalDepth_meter);
	};
}

#endif // EQUIVALENT_CIRCULATING_DENSITY_H