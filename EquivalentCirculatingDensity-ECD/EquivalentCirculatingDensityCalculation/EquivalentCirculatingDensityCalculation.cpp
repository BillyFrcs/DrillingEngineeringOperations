#include <iostream>

#include "EquivalentCirculatingDensityCalculation.h"

EquivalentCirculatingDensity::EquivalentCirculatingDensityCalculation::EquivalentCirculatingDensityCalculation(double mudWeight, double pressureLoss, double trueVerticalDepth)
{
	this->mudWeight = mudWeight;
	this->pressureLoss = pressureLoss;
	this->trueVerticalDepth = trueVerticalDepth;
}

EquivalentCirculatingDensity::EquivalentCirculatingDensityCalculation::~EquivalentCirculatingDensityCalculation()
{
}

// Method to calculate ECD
double EquivalentCirculatingDensity::EquivalentCirculatingDensityCalculation::CalculateECD() const
{
	return this->mudWeight + (this->pressureLoss / (0.052 * this->trueVerticalDepth));
}

// Wrapper function
extern "C" __declspec(dllexport) double CalculateECD(double mudWeight, double pressureLoss, double trueVerticalDepth)
{
	EquivalentCirculatingDensity::EquivalentCirculatingDensityCalculation ecd(mudWeight, pressureLoss, trueVerticalDepth);

	return ecd.CalculateECD();
}

int main()
{
	std::cout << "Equivalent Circulating Density (ECD) Calculation" << std::endl;

	// DEBUG x86
	std::cout << CalculateECD(12.2, 400, 12000) << " ppg" << std::endl;

	return EXIT_SUCCESS;
}