#include "HoistingSystem.h"

int main(int argc, char* argv[])
{
    std::cout << "Total Hook Load = " << HookLoad1() << " lb" << std::endl;

    std::cout << "Fast Line Tension = " << FastLineTension() << " lb" << std::endl;

    std::cout << "Dead Line Tension = " << DeadLineTension() << " lb" << std::endl;

    std::cout << "Derrick Load under the Dynamic Conditions = " << DerrickLoadUnderDynamicConditions() << " lb \n" << std::endl;

    std::cout << "Required Traveling Block Output = " << std::fixed << std::setprecision(0) << RequiredTravelingBlockOutput() << " ft-lb/min" << std::endl;

    std::cout << "Required Traveling Block Input = " << std::fixed << std::setprecision(0) << RequiredTravelingBlockInput() << " ft-lb/min" << std::endl;

    std::cout << "Horse Power = " << std::fixed << std::setprecision(2) << HorsePower() << " hp" << std::endl;

    std::cout << "Draw-Works Output = " << DrawWorksOutput() << " hp \n" << std::endl;

    std::cout << "Power Draw-Works Output = " << std::fixed << std::setprecision(0) << PDWOut() << " hp" << std::endl;

    std::cout << "Power Input = " << std::fixed << std::setprecision(0) << Pi() << " ft-lb/min" << std::endl;

    std::cout << "Hoisting Efficiency = " << std::fixed << std::setprecision(2) << HoistingEfficiency() << " lb" << std::endl;

    std::cout << "Fast Line Velocity = " << std::fixed << std::setprecision(0) << FastLineVelocity() << " fpm" << std::endl;

    std::cout << "Traveling Block Velocity = " << std::fixed << std::setprecision(0) << TravelingBlockVelocity() << " fpm" << std::endl;

    std::cout << "Traveling Block Speed = " << TravelingBlockSpeed() << " min \n" << std::endl;

    std::cout << "Drill Pipe Weight = " << DrillPipeWeight() << " lb" << std::endl;

    std::cout << "Drill Collar Weight = " << DrillCollarWeight() << " lb" << std::endl;

    std::cout << "Drill String Weight in Air = " << DrillStringWeightInAir() << " lb" << std::endl;

    std::cout << "Drill String Weight in Mud = " << DrillStringWeightInMud() << " lb" << std::endl;

    std::cout << "Hook Load = " << HookLoad2() << " lb" << std::endl;

    std::cout << "Dead Line Load = " << DeadLineLoad() << " lb" << std::endl;

    std::cout << "Fast Line Load = " << FastLineLoad1() << " lb" << std::endl;

    std::cout << "Dynamic Crown Load = " << DynamicCrownLoad() << " lb" << std::endl;

    std::cout << "Design Factor = " << DesignFactor() << " \n" << std::endl;

    std::cout << "Weight of Casing in Mud when running casing = " << WeightOfCasingInMudWhenRunningCasing() << " lb" << std::endl;

    std::cout << "Hook Load when running casing = " << HookLoadWhenRunningCasing() << " lb" << std::endl;

    std::cout << "Fast Line Load when running casing = " << FastLineLoadWhenRunningCasing() << " lb" << std::endl;

    std::cout << "Design Factor when running casing = " << DesignFactorWhenRunningCasing() << " \n" << std::endl;

    std::cout << "Hook Load Velocity = " << HookLoadVelocity() << " ft/min" << std::endl;

    std::cout << "Power at Drum = " << PowerAtDrum() << " hp" << std::endl;

    std::cout << "Motor Power = " << MotorPower() << " hp" << std::endl;

    std::cout << "Market Data Motor Power = " << MarketDataMotorPower() << " with hp rating" << std::endl;

    std::cout << "Fast Line Speed = " << FastLineSpeed() << " ft/min" << std::endl;

    std::cout << "Drum Speed = " << DrumSpeed() << " rpm" << std::endl;

    std::cout << "Gear Ratio = " << GearRatio() << std::endl;

    return EXIT_SUCCESS;
}