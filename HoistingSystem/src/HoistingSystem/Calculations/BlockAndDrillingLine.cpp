#include "BlockAndDrillingLine.h"

long double HoistingSystem::BlockAndDrillingLine::RequiredTravelingBlockOutput()
{
    long double Fh = 500000;
    long double Vtb = 100;

    long double Po = Fh * Vtb;

    return std::ceill(Po);
}

long double HoistingSystem::BlockAndDrillingLine::RequiredTravelingBlockInput()
{
    long double Fh = 500000;
    long double Vtb = 100;
    long double nh = 0.85;

    long double powerDrawWorksOutput = (Fh * Vtb) / nh;

    return std::ceill(powerDrawWorksOutput);
}

long double HoistingSystem::BlockAndDrillingLine::HorsePower()
{
    long double powerDrawWorksOutput = RequiredTravelingBlockInput();
    long double horsePower = 33000;

    long double hp = powerDrawWorksOutput / horsePower;

    return std::ceill(hp);
}

long double HoistingSystem::BlockAndDrillingLine::DrawWorksOutput()
{
    long double powerDrawWorksOuput = HorsePower();
    long double powerDrawWorksInput = 0.75;

    long double nDrawWorks = powerDrawWorksOuput / powerDrawWorksInput;

    return std::ceill(nDrawWorks);
}

long double HoistingSystem::BlockAndDrillingLine::PowerDrawWorksOutput()
{
    long double powerInput = 1200;
    long double travelingBlockInput = 0.80;

    long double powerDrawWorksOutput = powerInput * travelingBlockInput;

    return powerDrawWorksOutput;
}

long double HoistingSystem::BlockAndDrillingLine::PowerInput()
{
    long double powerDrawWorksOutput = PowerDrawWorksOutput();
    long double horsePower = 33000;

    long double powerInput = powerDrawWorksOutput * horsePower;

    return powerInput;
}

long double HoistingSystem::BlockAndDrillingLine::HoistingEfficiency()
{
    long double Fh = 350000;
    long double Ff = 0.70;
    long double n = 12;

    long double nh = Fh / (Ff * n);

    return nh;
}

long double HoistingSystem::BlockAndDrillingLine::FastLineVelocity()
{
    long double powerInput = PowerInput();
    long double nh = HoistingEfficiency();

    long double Vf = powerInput / nh;

    return Vf;
}

long double HoistingSystem::BlockAndDrillingLine::TravelingBlockVelocity()
{
    long double fastLineVelocity = FastLineVelocity();
    long double drillingLines = 12;

    long double Vtb = fastLineVelocity / drillingLines;

    return Vtb;
}

long double HoistingSystem::BlockAndDrillingLine::TravelingBlockSpeed()
{
    long double ftStand = 90;
    long double velocity = TravelingBlockVelocity();

    long double speed = ftStand / velocity;

    return speed;
}