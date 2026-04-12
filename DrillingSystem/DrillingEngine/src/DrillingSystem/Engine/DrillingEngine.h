#pragma once

#include <memory>

#include "DrillingSystem/Calculations/EquivalentCirculatingDensity.h"
#include "DrillingSystem/Calculations/HydrostaticPressure.h"
#include "DrillingSystem/Calculations/KillWeightMud.h"

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

        double ImperialHydrostaticPressure(double mudWeight_ppg, double trueVerticalDepth_feet);

        double MetricHydrostaticPressure(double mudWeight_sg, double trueVerticalDepth_meter);

        double ImperialKillWeightMud(double currentMudWeight_ppg, double SIDPP_psi, double trueVerticalDepth_feet);

        double MetricKillWeightMud(double currentMudWeight_kg_m3, double SIDPP_KPa, double trueVerticalDepth_meter);
	};
}

#endif // DRILLING_ENGINE_H