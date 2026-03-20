#include <iostream>

#include "EquivalentCirculatingDensityCalculation.h"

EquivalentCirculationDensity::EquivalentCirculationDensityCalculation::EquivalentCirculationDensityCalculation(double mw, double pl, double tvd)
{
	mudWeight = mw;
	pressureLoss = pl;
	trueVerticalDepth = tvd;
}

EquivalentCirculationDensity::EquivalentCirculationDensityCalculation::~EquivalentCirculationDensityCalculation()
{
}

// Method to calculate ECD
double EquivalentCirculationDensity::EquivalentCirculationDensityCalculation::CalculateECD() const
{
    return mudWeight + (pressureLoss / (0.052 * trueVerticalDepth));
}

// Wrapper function 
extern "C" __declspec(dllexport)
double CalculateECD(double mudWeight, double pressureLoss, double trueVerticalDepth)
{
	EquivalentCirculationDensity::EquivalentCirculationDensityCalculation ecd(mudWeight, pressureLoss, trueVerticalDepth);

	return ecd.CalculateECD();
}

int main()
{
    std::cout << "Equivalent Circulation Density (ECD) Calculation" << std::endl;

	// DEBUG x86
	std::cout << CalculateECD(12.2, 400, 12000) << " ppg" << std::endl;

	return EXIT_SUCCESS;
}