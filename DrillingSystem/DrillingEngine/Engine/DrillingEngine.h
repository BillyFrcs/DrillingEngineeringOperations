#pragma once

#include "../Calculations/EquivalentCirculatingDensity.h"

#ifndef DRILLING_ENGINE_H
#define DRILLING_ENGINE_H

namespace DrillingSystem
{
	class DrillingEngine
	{
    public:
        DrillingEngine();

        ~DrillingEngine();

        double ImperialEquivalentCirculatingDensity(double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet);

        double MetricEquivalentCirculatingDensity(double mudWeight_sg, double pressureLoss_bar, double trueVerticalDepth_meter);
	};
}

#endif // DRILLING_ENGINE_H