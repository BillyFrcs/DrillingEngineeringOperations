#pragma once

#ifndef ECD
#define ECD

namespace EquivalentCirculationDensity
{
    class EquivalentCirculationDensityCalculation
    {
    private:
        double mudWeight = 0.0;
        double pressureLoss = 0.0;
        double trueVerticalDepth = 0.0;

    public:
        EquivalentCirculationDensityCalculation(double mw, double pl, double tvd);

        ~EquivalentCirculationDensityCalculation();

        double CalculateECD() const;
    };
}

#endif // ECD