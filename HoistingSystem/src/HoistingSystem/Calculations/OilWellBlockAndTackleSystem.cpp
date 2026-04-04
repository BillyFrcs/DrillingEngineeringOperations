#include "OilWellBlockAndTackleSystem.h"

long double HoistingSystem::OilWellBlockAndTackleSystem::HookLoadVelocity()
{
    return 120;
}

long double HoistingSystem::OilWellBlockAndTackleSystem::PowerAtDrum()
{
    long double hookLoad = 500000;
    long double hookLoadVelocity = HookLoadVelocity();
    long double EF = 0.811;
    long double horsePower = 33000;

    long double powerAtDrum = (hookLoad * hookLoadVelocity) / EF / horsePower;

    return powerAtDrum;
}

long double HoistingSystem::OilWellBlockAndTackleSystem::MotorPower()
{
    long double powerAtDrum = PowerAtDrum();
    long double motorEfficiency = 0.88;

    long double motorPower = powerAtDrum / motorEfficiency;

    return motorPower;
}

long double HoistingSystem::OilWellBlockAndTackleSystem::MarketDataMotorPower()
{
    return 3000;
}

long double HoistingSystem::OilWellBlockAndTackleSystem::MarketDataMotorSpeed()
{
    return 1200;
}

long double HoistingSystem::OilWellBlockAndTackleSystem::FastLineSpeed()
{
    long double N = 10;
    long double hookLoadSpeed = HookLoadVelocity();

    long double Vf = N * hookLoadSpeed;

    return Vf;
}

long double HoistingSystem::OilWellBlockAndTackleSystem::DrumSpeed()
{
    long double fastLineSpeed = FastLineSpeed();
    long double Pi = 3.14;
    long double hoistingDrumDiameter = 32.0 / 2.0 / 12.0; // Convert inches to feet

    long double drumSpeed = fastLineSpeed / (2 * Pi * (hoistingDrumDiameter));

    return drumSpeed;
}

long double HoistingSystem::OilWellBlockAndTackleSystem::GearRatio()
{
    long double motorSpeed = 1200;
    long double drumSpeed = DrumSpeed();

    long double gearRatio = motorSpeed / drumSpeed;

    return gearRatio;
}