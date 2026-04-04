#include "HoistingAndDrawwoksAnalysis.h"

long double HoistingSystem::HoistingAndDrawworksAnalysis::DrillPipeLength()
{
    long double holeDepth = 10000;
    long double DC_Length = 500;

	long double DP_Weight = holeDepth - DC_Length;

    return DP_Weight;
}

long double HoistingSystem::HoistingAndDrawworksAnalysis::DrillPipeWeight()
{
    long double DP_Length = DrillPipeLength();
    long double DP_Weight = 19.5;

	long double DP_Joint = DP_Length * DP_Weight;

    return DP_Joint;
}

long double HoistingSystem::HoistingAndDrawworksAnalysis::DrillCollarWeight()
{
    long double DC_Length = 500;
    long double DC_Weight = 150;

    long double DC_Joint = DC_Weight * DC_Length;

    return DC_Joint;
}

long double HoistingSystem::HoistingAndDrawworksAnalysis::DrillStringWeightInAir()
{
    long double DP_Weight = DrillPipeWeight();
    long double DC_Weight = DrillCollarWeight();

    long double drillStringWeightInAir = DP_Weight + DC_Weight;

    return drillStringWeightInAir;
}

long double HoistingSystem::HoistingAndDrawworksAnalysis::DrillStringWeightInMud()
{
    long double bouyancyFactor = 0.847;
    long double weightInAir = DrillStringWeightInAir();

    long double drillStringWeightInMud = bouyancyFactor * weightInAir;

    return drillStringWeightInMud;
}

long double HoistingSystem::HoistingAndDrawworksAnalysis::HookLoad()
{
    long double weightOfStringInMud = DrillStringWeightInMud();
    long double weightOfTravelingBlock = 23500;

    long double hookLoad_W = weightOfStringInMud + weightOfTravelingBlock;

    return std::ceill(hookLoad_W);
}

long double HoistingSystem::HoistingAndDrawworksAnalysis::DeadLineLoad()
{
    long double hookLoadWeight = HookLoad();
    long double KN = std::pow(0.9615, 10);
    long double N = 10;
    long double E = 0.811;

    long double Td = (hookLoadWeight * KN) / (N * E);

    return std::ceill(Td);
}

long double HoistingSystem::HoistingAndDrawworksAnalysis::FastLineLoad()
{
    long double W = HookLoad();
    long double N = 10;
    long double E = 0.811;

    long double Td = W / (N * E);

    return std::ceill(Td);
}

long double HoistingSystem::HoistingAndDrawworksAnalysis::DynamicCrownLoad()
{
    long double hookLoad = HookLoad();
    long double dealLineLoad = DeadLineLoad();
    long double fastLineLoad = FastLineLoad();

    long double dynamicCrownLoad = hookLoad + dealLineLoad + fastLineLoad;

    return dynamicCrownLoad;
}

long double HoistingSystem::HoistingAndDrawworksAnalysis::DesignFactor()
{
    long double breakingStrength = 228000;
    long double fastLineLoad = FastLineLoad();

    long double designFactor = breakingStrength / fastLineLoad;

    return designFactor;
}

long double HoistingSystem::HoistingAndDrawworksAnalysis::WeightOfCasingInMudWhenRunningCasing()
{
    // 7" Casing run
    long double holeDepth = 10000;
    long double designFactorWhenRunningCasing = 29;
    long double bouyancyFactor = 0.847;

    long double weightOfCasingInMud = holeDepth * designFactorWhenRunningCasing * bouyancyFactor;

    return weightOfCasingInMud;
}

long double HoistingSystem::HoistingAndDrawworksAnalysis::HookLoadWhenRunningCasing()
{
    // 7" Casing run
    long double weightOfCasingInMud = WeightOfCasingInMudWhenRunningCasing();
    long double weightOfTravelingBlock = 23500;

    long double hookLoad = weightOfCasingInMud + weightOfTravelingBlock;

    return std::ceil(hookLoad);
}

long double HoistingSystem::HoistingAndDrawworksAnalysis::FastLineLoadWhenRunningCasing()
{
    // 7" Casing run
    long double W = HookLoadWhenRunningCasing();
    long double N = 10;
    long double E = 0.811;

    long double Tf = W / (N * E);

    return std::ceil(Tf);
}

long double HoistingSystem::HoistingAndDrawworksAnalysis::DesignFactorWhenRunningCasing()
{
    // 7" Casing run
    long double breakingStrength = 228000;
    long double fastLineLoad = FastLineLoadWhenRunningCasing();

    long double designFactor = breakingStrength / fastLineLoad;

    return designFactor;
}