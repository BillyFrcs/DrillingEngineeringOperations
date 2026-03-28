#pragma once

#include "DrillingSystem.h"

#ifndef HYDROSTATIC_PRESSURE_H
#define HYDROSTATIC_PRESSURE_H

namespace DrillingSystem
{
	class HydrostaticPressure
	{
	public:
		HydrostaticPressure(double mudWeight, double trueVerticalDepth);

		~HydrostaticPressure();

		double ImperialCalculation();

		double MetricCalculation();

	private:
		double m_MudWeight;
		double m_TrueVerticalDepth;
	};
}

#endif // HYDROSTATIC_PRESSURE_H