#pragma once

#include "DrillingSystem.h"

#ifndef DRILLING_ENGINE_H
#define DRILLING_ENGINE_H

namespace DrillingSystem
{
	class DrillingEngine
	{
    public:
        DrillingEngine();

        ~DrillingEngine();

        DrillingEngine* CreateDrillingEngine();

        double ImperialEquivalentCirculatingDensity(double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet);

        double MetricEquivalentCirculatingDensity(double mudWeight_sg, double pressureLoss_bar, double trueVerticalDepth_meter);

        double ImperialHydrostaticPressure(double mudWeight_ppg, double trueVerticalDepth_feet);

        double MetricHydrostaticPressure(double mudWeight_sg, double trueVerticalDepth_meter);

        void DestroyDrillingEngine(DrillingEngine* drillingEngine);
	};
}

#endif // DRILLING_ENGINE_H