#pragma once

#include <iomanip>

#ifndef HOISTING_AND_DRAWWORKS_ANALYSIS_H
#define HOISTING_AND_DRAWWORKS_ANALYSIS_H

namespace HoistingSystem
{
	class HoistingAndDrawworksAnalysis
	{
	public:
		HoistingAndDrawworksAnalysis() = default;

		~HoistingAndDrawworksAnalysis() = default;

        long double DrillStringWeightInAir();

        long double DrillStringWeightInMud();

        long double HookLoad();

        long double DeadLineLoad();

        long double FastLineLoad();

        long double DynamicCrownLoad();

        long double DesignFactor();

        long double WeightOfCasingInMudWhenRunningCasing();

        long double HookLoadWhenRunningCasing();

        long double FastLineLoadWhenRunningCasing();

        long double DesignFactorWhenRunningCasing();

    private:
        long double DrillPipeLength();

        long double DrillPipeWeight();

        long double DrillCollarWeight();
	};
}

#endif // HOISTING_AND_DRAWWORKS_ANALYSIS_H