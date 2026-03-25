#pragma once

#ifndef EQUIVALENT_CIRCULATING_DENSITY_CALCULATION_H
#define EQUIVALENT_CIRCULATING_DENSITY_CALCULATION_H

namespace EquivalentCirculatingDensity
{
    class EquivalentCirculatingDensityCalculation
    {
    private:
        double mudWeight = 0.0;
        double pressureLoss = 0.0;
        double trueVerticalDepth = 0.0;

    public:
        EquivalentCirculatingDensityCalculation(double mudWeight, double pressureLoss, double trueVerticalDepth);

        ~EquivalentCirculatingDensityCalculation();

        double CalculateECD() const;
    };
}

#endif //EQUIVALENT_CIRCULATING_DENSITY_CALCULATION_H