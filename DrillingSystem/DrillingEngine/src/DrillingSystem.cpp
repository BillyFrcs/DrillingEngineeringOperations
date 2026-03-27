#include "DrillingSystem.h"
#include "Engine/DrillingEngine.h"

// C-Style Wrapper (Bridge) function using pointer
namespace DrillingSystem
{
	extern "C"
	{
		__declspec(dllexport)
		DrillingSystem::DrillingEngine* CreateDrillingEngine()
		{
			auto drillingEngine = std::make_unique<DrillingSystem::DrillingEngine>();

			return drillingEngine.release();

			// return new DrillingSystem::DrillingEngine();
		}

		__declspec(dllexport)
		double ImperialEquivalentCirculatingDensityCalculation(DrillingSystem::DrillingEngine* drillingEngine, double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet)
		{
			return drillingEngine->ImperialEquivalentCirculatingDensity(mudWeight_ppg, pressureLoss_psi, trueVerticalDepth_feet);
		}

		__declspec(dllexport)
		double MetricEquivalentCirculatingDensityCalculation(DrillingSystem::DrillingEngine* drillingEngine, double mudWeight_sg, double pressureLoss_bar, double trueVerticalDepth_meter)
		{
			return drillingEngine->MetricEquivalentCirculatingDensity(mudWeight_sg, pressureLoss_bar, trueVerticalDepth_meter);
		}

		__declspec(dllexport)
		void DestroyDrillingEngine(DrillingSystem::DrillingEngine* drillingEngine)
		{
			std::unique_ptr<DrillingSystem::DrillingEngine> drillingEnginePtr(drillingEngine);

			// delete drillingEngine;
		}
	}

	/*
	// C-Style Wrapper (Bridge) function
	extern "C" __declspec(dllexport) double ImperialEquivalentCirculatingDensityCalculation(double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet)
	{
		DrillingSystem::DrillingEngine drillingEngine;

		return drillingEngine.ImperialEquivalentCirculatingDensity(mudWeight_ppg, pressureLoss_psi, trueVerticalDepth_feet);
	}
	*/
}

int main(int argc, char** argv)
{
	auto drillingEngineUnique = std::make_unique<DrillingSystem::DrillingEngine>(); 

	drillingEngineUnique.release();

	DrillingSystem::DrillingEngine* drillingEngine = nullptr;

	// DEBUG: Check if the pointer is null before using it
	std::clog << drillingEngine->ImperialEquivalentCirculatingDensity(12.2, 400, 12000) << std::endl;
	std::clog << drillingEngine->MetricEquivalentCirculatingDensity(1200, 2760, 2440) << std::endl;

	std::unique_ptr<DrillingSystem::DrillingEngine> drillingEnginePtr(drillingEngine);

	/*
	// Default object instantiation and method calls
	DrillingSystem::DrillingEngine drillingEngine;

	std::cout << drillingEngine.ImperialEquivalentCirculatingDensity(12.2, 400, 12000) << std::endl;
	std::cout << drillingEngine.MetricEquivalentCirculatingDensity(1200, 2760, 2440) << std::endl;
	*/

	return EXIT_SUCCESS;
}