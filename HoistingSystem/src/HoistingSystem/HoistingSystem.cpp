#include "HoistingSystem.h"

int main(int argc, char* argv[])
{
	std::println("Total Hook Load = {:.2f} lb", HookLoad1());

	std::println("Fast Line Tension = {} lb", FastLineTension());

	std::println("Dead Line Tension = {} lb", DeadLineTension());

	std::println("Derrick Load under the Dynamic Conditions = {} lb \n", DerrickLoadUnderDynamicConditions());

	std::println("Required Traveling Block Output = {:.2f} ft-lb/min", RequiredTravelingBlockOutput());

	std::println("Required Traveling Block Input = {} ft-lb/min", RequiredTravelingBlockInput());

	std::println("Horse Power = {} hp", HorsePower());

	std::println("Draw-Works Output = {} hp \n", DrawWorksOutput());

	std::println("Power Draw-Works Output = {} hp", PowerDrawWorksOutput());

	std::println("Power Input = {} ft-lb/min", Pi());

	std::println("Hoisting Efficiency = {}", HoistingEfficiency());

	std::println("Fast Line Velocity = {} fpm", FastLineVelocity());

	std::println("Traveling Block Velocity = {} fpm", TravelingBlockVelocity());

	std::println("Traveling Block Speed = {} min \n", TravelingBlockSpeed());

	std::println("Drill Pipe Weight = {} lb", DrillPipeWeight());

	std::println("Drill Collar Weight = {} lb", DrillCollarWeight());

	std::println("Drill String Weight in Air = {} lb", DrillStringWeightInAir());

	std::println("Drill String Weight in Mud = {} lb", DrillStringWeightInMud());

	std::println("Hook Load = {} lb", HookLoad2());

	std::println("Dead Line Load = {} lb", DeadLineLoad());

	std::println("Fast Line Load = {} lb", FastLineLoad1());

	std::println("Dynamic Crown Load = {} lb", DynamicCrownLoad());

	std::println("Design Factor = {}", DesignFactor());

	std::println("Weight of Casing in Mud when running casing = {} lb", WeightOfCasingInMudWhenRunningCasing());

	std::println("Hook Load When running casing = {} lb", HookLoadWhenRunningCasing());

	std::println("Fast Line Load when running casing = {} lb", FastLineLoadWhenRunningCasing());
	
    std::println("Design Factor when running casing = {} \n", DesignFactorWhenRunningCasing());

	std::println("Hook Load Velocity = {} ft/min", HookLoadVelocity());

	std::println("Power at Drum = {} hp", PowerAtDrum());

	std::println("Motor Power = {} hp", MotorPower());

	std::println("Select a Motor = {} hp rating", MarketDataMotorPower());

	std::println("Market Data {} hp Motor Speed = {} RPM", MarketDataMotorPower(), MarketDataMotorSpeed());

	std::println("Fast Line Speed = {} ft/min", FastLineSpeed());

	std::println("Drum Speed = {} rpm", DrumSpeed());

	std::println("Gear Ratio = {}", GearRatio());

    return EXIT_SUCCESS;
}