#pragma once

#ifndef ECD
#define ECD

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

#endif // ECD