#include "Application.h"

void HoistingSystem::Application::Run()
{	
	RigDerrickLoad();

	BlockAndDrillingLine();

	HoistingAndDrawworksAnalysis();

	OilWellBlockAndTackleSystem();
}

void HoistingSystem::Application::RigDerrickLoad()
{
	std::unique_ptr<HoistingSystem::RigDerrickLoad> rigDerrickLoad = std::make_unique<HoistingSystem::RigDerrickLoad>();

	std::println("Total Hook Load = {:.2f} lb", rigDerrickLoad->HookLoad());

	std::println("Fast Line Tension = {} lb", rigDerrickLoad->FastLineTension());

	std::println("Dead Line Tension = {} lb", rigDerrickLoad->DeadLineTension());

	std::println("Derrick Load under the Dynamic Conditions = {} lb \n", rigDerrickLoad->DerrickLoadUnderDynamicConditions());
}

void HoistingSystem::Application::BlockAndDrillingLine()
{
	std::unique_ptr<HoistingSystem::BlockAndDrillingLine> blockAndDrillingLine = std::make_unique<HoistingSystem::BlockAndDrillingLine>();

	std::println("Required Traveling Block Output = {:.2f} ft-lb/min", blockAndDrillingLine->RequiredTravelingBlockOutput());

	std::println("Required Traveling Block Input = {} ft-lb/min", blockAndDrillingLine->RequiredTravelingBlockInput());

	std::println("Horse Power = {} hp", blockAndDrillingLine->HorsePower());

	std::println("Draw-Works Output = {} hp \n", blockAndDrillingLine->DrawWorksOutput());

	std::println("Power Draw-Works Output = {} hp", blockAndDrillingLine->PowerDrawWorksOutput());

	std::println("Power Input = {} ft-lb/min", blockAndDrillingLine->PowerInput());

	std::println("Hoisting Efficiency = {}", blockAndDrillingLine->HoistingEfficiency());

	std::println("Fast Line Velocity = {} fpm", blockAndDrillingLine->FastLineVelocity());

	std::println("Traveling Block Velocity = {} fpm", blockAndDrillingLine->TravelingBlockVelocity());

	std::println("Traveling Block Speed = {} min \n", blockAndDrillingLine->TravelingBlockSpeed());

}

void HoistingSystem::Application::HoistingAndDrawworksAnalysis()
{
	std::unique_ptr<HoistingSystem::HoistingAndDrawworksAnalysis> hoistingAndDrawworksAnalysis = std::make_unique<HoistingSystem::HoistingAndDrawworksAnalysis>();

	std::println("Drill String Weight in Air = {} lb", hoistingAndDrawworksAnalysis->DrillStringWeightInAir());

	std::println("Drill String Weight in Mud = {} lb", hoistingAndDrawworksAnalysis->DrillStringWeightInMud());

	std::println("Hook Load = {} lb", hoistingAndDrawworksAnalysis->HookLoad());

	std::println("Dead Line Load = {} lb", hoistingAndDrawworksAnalysis->DeadLineLoad());

	std::println("Fast Line Load = {} lb", hoistingAndDrawworksAnalysis->FastLineLoad());

	std::println("Dynamic Crown Load = {} lb", hoistingAndDrawworksAnalysis->DynamicCrownLoad());

	std::println("Design Factor = {}", hoistingAndDrawworksAnalysis->DesignFactor());

	std::println("Weight of Casing in Mud when running casing = {} lb", hoistingAndDrawworksAnalysis->WeightOfCasingInMudWhenRunningCasing());

	std::println("Hook Load when running casing = {} lb", hoistingAndDrawworksAnalysis->HookLoadWhenRunningCasing());

	std::println("Fast Line Load when running casing = {} lb", hoistingAndDrawworksAnalysis->FastLineLoadWhenRunningCasing());

	std::println("Design Factor when running casing = {} \n", hoistingAndDrawworksAnalysis->DesignFactorWhenRunningCasing());
}

void HoistingSystem::Application::OilWellBlockAndTackleSystem()
{
	std::unique_ptr<HoistingSystem::OilWellBlockAndTackleSystem> oilWellBlockAndTackleSystem = std::make_unique<HoistingSystem::OilWellBlockAndTackleSystem>();

	std::println("Hook Load Velocity = {} ft/min", oilWellBlockAndTackleSystem->HookLoadVelocity());

	std::println("Power at Drum = {} hp", oilWellBlockAndTackleSystem->PowerAtDrum());

	std::println("Motor Power = {} hp", oilWellBlockAndTackleSystem->MotorPower());

	std::println("Select a Motor = {} hp rating", oilWellBlockAndTackleSystem->MarketDataMotorPower());

	std::println("Fast Line Speed = {} ft/min", oilWellBlockAndTackleSystem->FastLineSpeed());

	std::println("Drum Speed = {} rpm", oilWellBlockAndTackleSystem->DrumSpeed());

	std::println("Market Data {} hp Motor Speed = {} RPM", oilWellBlockAndTackleSystem->MarketDataMotorPower(), oilWellBlockAndTackleSystem->MarketDataMotorSpeed());

	std::println("Gear Ratio = {}", oilWellBlockAndTackleSystem->GearRatio());
}
