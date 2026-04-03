#pragma once

#include <iostream>
#include <print>

#ifndef HOISTING_SYSTEM_H
#define HOISTING_SYSTEM_H

long double HookLoad1()
{
    long double buoyedWeight = 260000;
    long double blockHookWeight = 40000;

    long double totalHookLoad_W = buoyedWeight + blockHookWeight;

    return std::ceil(totalHookLoad_W);
}

long double FastLineTension()
{
    long double totalHookLoad_W = HookLoad1();
    long double noLines = 10;
    long double efficiency = 0.811;

    long double fastLineTension_Tt = totalHookLoad_W / (noLines * efficiency);

    return std::ceil(fastLineTension_Tt);
}

long double DeadLineTension()
{
    long double totalHookLoad_W = HookLoad1();
    long double linesEfficiency = 10;

    long double deadLineTension_Td = totalHookLoad_W / linesEfficiency;

    return std::ceil(deadLineTension_Td);
}

long double DerrickLoadUnderDynamicConditions()
{
    long double totalFastLineTension_Tt = FastLineTension();
    long double totalHookLoad_W = HookLoad1();
    long double totalDeadLineTension_Td = DeadLineTension();

    long double derrickLoad_fd = totalFastLineTension_Tt + totalHookLoad_W + totalDeadLineTension_Td;

    return std::ceil(derrickLoad_fd);
}

long double RequiredTravelingBlockOutput()
{
    long double Fh = 500000;
    long double Vtb = 100;

    long double Po = Fh * Vtb;

    return std::ceil(Po);
}

long double RequiredTravelingBlockInput()
{
    long double Fh = 500000;
    long double Vtb = 100;
    long double nh = 0.85;

    long double PDW_out = (Fh * Vtb) / nh;

    return std::ceil(PDW_out);
}

long double HorsePower()
{
    long double PDW_out = RequiredTravelingBlockInput();
    long double horsePower = 33000;

    long double hp = PDW_out / horsePower;

    return std::ceil(hp);
}

long double DrawWorksOutput()
{
    long double PDW_out = HorsePower();
    long double PDW_in = 0.75;

    long double nDW = PDW_out / PDW_in;

    return nDW;
}

long double PowerDrawWorksOutput()
{
    long double powerInput = 1200;
    long double travelingBlockInput_Pi = 0.80;

    long double PDW_out = powerInput * travelingBlockInput_Pi;

    return PDW_out;
}

long double Pi()
{
    long double PDW_out = PowerDrawWorksOutput();
    long double horsePower = 33000;

    long double calculate = PDW_out * horsePower;

    return calculate;
}

long double HoistingEfficiency()
{
    long double fh = 350000;
    long double Ff = 0.70;
    long double n = 12;

    long double nh = fh / (Ff * n);

    return std::ceil(nh);
}

long double FastLineVelocity()
{
    long double pi = Pi();
    long double nh = HoistingEfficiency();

    long double Vf = pi / nh;

    return Vf;
}

long double TravelingBlockVelocity()
{
    long double fastLineVelocity = FastLineVelocity();
    long double drillingLines = 12;

    long double Vtb = fastLineVelocity / drillingLines;

    return Vtb;
}

long double TravelingBlockSpeed()
{
    long double speed = 90;
    long double velocity = TravelingBlockVelocity();

    long double calculate = speed / velocity;

    return calculate;
}

long double DrillPipeWeight()
{
    long double holeDepth = 10000;
    long double DC_Length = 500;
    long double DP_Weight = 19.5;

    long double calculate = (holeDepth - DC_Length) * DP_Weight;

    return calculate;
}

long double DrillCollarWeight()
{
    long double DC_Length = 500;
    long double DC_Weight = 150;

    long double calculate = DC_Weight * DC_Length;

    return calculate;
}

long double DrillStringWeightInAir()
{
    long double DP_Weight = DrillPipeWeight();
    long double DC_Weight = DrillCollarWeight();

    long double calculate = DP_Weight + DC_Weight;

    return calculate;
}

long double DrillStringWeightInMud()
{
    long double bouyancyFactor = 0.847;
    long double weightInAir = DrillStringWeightInAir();

    long double calculate = bouyancyFactor * weightInAir;

    return calculate;
}

long double HookLoad2()
{
    long double weightOfStringInMud = DrillStringWeightInMud();
    long double weightOfTravelingBlock = 23500;

    long double calculate = weightOfStringInMud + weightOfTravelingBlock;

    return std::ceil(calculate);
}

long double DeadLineLoad()
{
    long double hookLoadWeight = HookLoad2();
    long double KN = std::pow(0.9615, 10);
    long double N = 10;
    long double E = 0.811;

    long double calculate = (hookLoadWeight * KN) / (N * E);

    return std::ceil(calculate);
}

long double FastLineLoad1()
{
    long double W = HookLoad2();
    long double N = 10;
    long double E = 0.811;

    long double calculate = W / (N * E);

    return std::ceil(calculate);
}

long double DynamicCrownLoad()
{
    long double hookLoad = HookLoad2();
    long double dealLineLoad = DeadLineLoad();
    long double fastLineLoad = FastLineLoad1();

    long double calculate = hookLoad + dealLineLoad + fastLineLoad;

    return calculate;
}

long double DesignFactor()
{
    long double breakingStrength = 228000;
    long double fastLineLoad = FastLineLoad1();

    long double calculate = breakingStrength / fastLineLoad;

    return calculate;
}

long double WeightOfCasingInMudWhenRunningCasing()
{
    // 7" Casing run
    long double holeDepth = 10000;
    long double designFactorWhenRunningCasing = 29;
    long double bouyancyFactor = 0.847;

    long double calculate = holeDepth * designFactorWhenRunningCasing * bouyancyFactor;

    return calculate;
}

long double HookLoadWhenRunningCasing()
{
    // 7" Casing run
    long double weightOfCasingInMud = WeightOfCasingInMudWhenRunningCasing();
    long double weightOfTravelingBlock = 23500;

    long double calculate = weightOfCasingInMud + weightOfTravelingBlock;

    return std::ceil(calculate);
}

long double FastLineLoadWhenRunningCasing()
{
    // 7" Casing run
    long double hookLoad = HookLoadWhenRunningCasing();
    long double N = 10;
    long double E = 0.811;

    long double calculate = hookLoad / (N * E);

    return std::ceil(calculate);
}

long double DesignFactorWhenRunningCasing()
{
    // 7" Casing run
    long double breakingStrength = 228000;
    long double fastLineLoad = FastLineLoadWhenRunningCasing();

    long double calculate = breakingStrength / fastLineLoad;

    return calculate;
}

long double HookLoadVelocity()
{
    return 120;
}

long double PowerAtDrum()
{
    long double hookLoad = 500000;
    long double hookLoadVelocity = HookLoadVelocity();
    long double EF = 0.811;
    long double horsePower = 33000;

    long double calculate = (hookLoad * hookLoadVelocity) / EF / horsePower;

    return calculate;
}

long double MotorPower()
{
    long double powerAtDrum = PowerAtDrum();
    long double motorEfficiency = 0.88;

    long double calculate = powerAtDrum / motorEfficiency;

    return calculate;
}

long double MarketDataMotorPower()
{
    return 3000;
}

long double MarketDataMotorSpeed()
{
    return 1200;
}

long double FastLineSpeed()
{
    long double N = 10;
    long double hookLoadSpeed = HookLoadVelocity();

    long double Vf = N * hookLoadSpeed;

    return Vf;
}

long double DrumSpeed()
{
    long double fastLineSpeed = FastLineSpeed();
    long double Pi = 3.14;
    long double hoistingDrumDiameter = 32.0 / 2.0 / 12.0; // Convert inches to feet

    long double calculate = fastLineSpeed / (2 * Pi * (hoistingDrumDiameter));

    return calculate;
}

long double GearRatio()
{
    long double motorSpeed = 1200;
    long double drumSpeed = DrumSpeed();

    long double calculate = motorSpeed / drumSpeed;

    return calculate;
}

#endif // HOISTING_SYSTEM_H