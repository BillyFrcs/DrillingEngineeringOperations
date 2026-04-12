#include "Platform.h"
#include "DrillingSystem/Engine/DrillingEngine.h"
#include "DrillingSystem/Logging/Debug.h"

// C-Style Wrapper (Bridge) function using pointer
extern "C"
{
	DLL_EXPORT DrillingSystem::DrillingEngine* CreateDrillingEngine()
	{
		auto drillingEngine = std::make_unique<DrillingSystem::DrillingEngine>();

		return drillingEngine.release();

		// return new DrillingSystem::DrillingEngine();
	}

	DLL_EXPORT double ImperialEquivalentCirculatingDensityCalculation(DrillingSystem::DrillingEngine* drillingEngine, double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet)
	{
		if (drillingEngine == nullptr)
		{
			throw std::invalid_argument("DrillingEngine pointer is null.");
		}

		return drillingEngine->ImperialEquivalentCirculatingDensity(mudWeight_ppg, pressureLoss_psi, trueVerticalDepth_feet);
	}

	DLL_EXPORT double MetricEquivalentCirculatingDensityCalculation(DrillingSystem::DrillingEngine* drillingEngine, double mudWeight_sg, double pressureLoss_bar, double trueVerticalDepth_meter)
	{
		if (drillingEngine == nullptr)
		{
			throw std::invalid_argument("DrillingEngine pointer is null.");
		}

		return drillingEngine->MetricEquivalentCirculatingDensity(mudWeight_sg, pressureLoss_bar, trueVerticalDepth_meter);
	}

	DLL_EXPORT double ImperialHydrostaticPressureCalculation(DrillingSystem::DrillingEngine* drillingEngine, double mudWeight_ppg, double trueVerticalDepth_feet)
	{
		if (drillingEngine == nullptr)
		{
			throw std::invalid_argument("DrillingEngine pointer is null.");
		}

		return drillingEngine->ImperialHydrostaticPressure(mudWeight_ppg, trueVerticalDepth_feet);
	}

	DLL_EXPORT double MetricHydrostaticPressureCalculation(DrillingSystem::DrillingEngine* drillingEngine, double mudWeight_sg, double trueVerticalDepth_meter)
	{
		if (drillingEngine == nullptr)
		{
			throw std::invalid_argument("DrillingEngine pointer is null.");
		}

		return drillingEngine->MetricHydrostaticPressure(mudWeight_sg, trueVerticalDepth_meter);
	}

	DLL_EXPORT double ImperialKillWeightCalculation(DrillingSystem::DrillingEngine* drillingEngine, double currentMudWeight_ppg, double SIDPP_psi, double trueVerticalDepth_feet)
	{
		if (drillingEngine == nullptr)
		{
			throw std::invalid_argument("DrillingEngine pointer is null.");
		}

		return drillingEngine->ImperialKillWeightMud(currentMudWeight_ppg, SIDPP_psi, trueVerticalDepth_feet);
	}

	DLL_EXPORT double MetricKillWeightCalculation(DrillingSystem::DrillingEngine* drillingEngine, double currentMudWeight_kg_m3, double SIDPP_KPa, double trueVerticalDepth_meter)
	{
		if (drillingEngine == nullptr)
		{
			throw std::invalid_argument("DrillingEngine pointer is null.");
		}

		return drillingEngine->MetricKillWeightMud(currentMudWeight_kg_m3, SIDPP_KPa, trueVerticalDepth_meter);
	}

	DLL_EXPORT void DestroyDrillingEngine(DrillingSystem::DrillingEngine* drillingEngine)
	{
		std::unique_ptr<DrillingSystem::DrillingEngine> drillingEnginePtr(drillingEngine);

		// delete drillingEnginePtr;
	}
}

/*
// C-Style Wrapper (Bridge) default function
extern "C" DLL_EXPORT double ImperialEquivalentCirculatingDensityCalculation(double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet)
{
	DrillingSystem::DrillingEngine drillingEngine;

	return drillingEngine.ImperialEquivalentCirculatingDensity(mudWeight_ppg, pressureLoss_psi, trueVerticalDepth_feet);
}
*/

int main(int argc, char** argv)
{
	auto debug = std::make_unique<DrillingSystem::Debug>();
		
	debug->Run();

	return EXIT_SUCCESS;
}