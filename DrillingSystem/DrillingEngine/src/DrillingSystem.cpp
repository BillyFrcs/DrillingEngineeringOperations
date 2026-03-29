#include "DrillingSystem.h"

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
		double ImperialHydrostaticPressureCalculation(DrillingSystem::DrillingEngine* drillingEngine, double mudWeight_ppg, double trueVerticalDepth_feet)
		{
			return drillingEngine->ImperialHydrostaticPressure(mudWeight_ppg, trueVerticalDepth_feet);
		}

		__declspec(dllexport)
		double MetricHydrostaticPressureCalculation(DrillingSystem::DrillingEngine* drillingEngine, double mudWeight_sg, double trueVerticalDepth_meter)
		{
			return drillingEngine->MetricHydrostaticPressure(mudWeight_sg, trueVerticalDepth_meter);
		}

		__declspec(dllexport)
		void DestroyDrillingEngine(DrillingSystem::DrillingEngine* drillingEngine)
		{
			std::unique_ptr<DrillingSystem::DrillingEngine> drillingEnginePtr(drillingEngine);

			// delete drillingEnginePtr;
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
	DrillingSystem::Application::Run();

	return EXIT_SUCCESS;
}