#include "DEpch.h"

// C-Style Wrapper (Bridge) function using pointer
extern "C"
{
	DLL_EXPORT DrillingSystem::DrillingEngine::DrillingEngine* CreateDrillingEngine()
	{
		auto drillingEngine = std::make_unique<DrillingSystem::DrillingEngine::DrillingEngine>();

		return drillingEngine.release();

		// return new DrillingSystem::DrillingEngine::DrillingEngine();
	}

	DLL_EXPORT double ImperialEquivalentCirculatingDensityCalculation(DrillingSystem::DrillingEngine::DrillingEngine* drillingEngine, double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet)
	{
		if (drillingEngine == nullptr)
		{
			throw std::invalid_argument("DrillingEngine pointer is null.");
		}

		return drillingEngine->ImperialEquivalentCirculatingDensity(mudWeight_ppg, pressureLoss_psi, trueVerticalDepth_feet);
	}

	DLL_EXPORT double MetricEquivalentCirculatingDensityCalculation(DrillingSystem::DrillingEngine::DrillingEngine* drillingEngine, double mudWeight_kg_m3, double pressureLoss_kPa, double trueVerticalDepth_meter)
	{
		if (drillingEngine == nullptr)
		{
			throw std::invalid_argument("DrillingEngine pointer is null.");
		}

		return drillingEngine->MetricEquivalentCirculatingDensity(mudWeight_kg_m3, pressureLoss_kPa, trueVerticalDepth_meter);
	}

	DLL_EXPORT double ImperialHydrostaticPressureCalculation(DrillingSystem::DrillingEngine::DrillingEngine* drillingEngine, double mudWeight_ppg, double trueVerticalDepth_feet)
	{
		if (drillingEngine == nullptr)
		{
			throw std::invalid_argument("DrillingEngine pointer is null.");
		}

		return drillingEngine->ImperialHydrostaticPressure(mudWeight_ppg, trueVerticalDepth_feet);
	}

	DLL_EXPORT double MetricHydrostaticPressureCalculation(DrillingSystem::DrillingEngine::DrillingEngine* drillingEngine, double mudWeight_kg_m3, double trueVerticalDepth_meter)
	{
		if (drillingEngine == nullptr)
		{
			throw std::invalid_argument("DrillingEngine pointer is null.");
		}

		return drillingEngine->MetricHydrostaticPressure(mudWeight_kg_m3, trueVerticalDepth_meter);
	}

	DLL_EXPORT double ImperialKillWeightMudCalculation(DrillingSystem::DrillingEngine::DrillingEngine* drillingEngine, double currentMudWeight_ppg, double SIDPP_psi, double trueVerticalDepth_feet)
	{
		if (drillingEngine == nullptr)
		{
			throw std::invalid_argument("DrillingEngine pointer is null.");
		}

		return drillingEngine->ImperialKillWeightMud(currentMudWeight_ppg, SIDPP_psi, trueVerticalDepth_feet);
	}

	DLL_EXPORT double MetricKillWeightMudCalculation(DrillingSystem::DrillingEngine::DrillingEngine* drillingEngine, double currentMudWeight_kg_m3, double SIDPP_KPa, double trueVerticalDepth_meter)
	{
		if (drillingEngine == nullptr)
		{
			throw std::invalid_argument("DrillingEngine pointer is null.");
		}

		return drillingEngine->MetricKillWeightMud(currentMudWeight_kg_m3, SIDPP_KPa, trueVerticalDepth_meter);
	}

	DLL_EXPORT void DestroyDrillingEngine(DrillingSystem::DrillingEngine::DrillingEngine* drillingEngine)
	{
		std::unique_ptr<DrillingSystem::DrillingEngine::DrillingEngine> de(drillingEngine);

		// delete de;
	}
}

/*
// C-Style Wrapper (Bridge) default function
extern "C" DLL_EXPORT double ImperialEquivalentCirculatingDensityCalculation(double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet)
{
	DrillingSystem::DrillingEngine::DrillingEngine drillingEngine;

	return drillingEngine.ImperialEquivalentCirculatingDensity(mudWeight_ppg, pressureLoss_psi, trueVerticalDepth_feet);
}
*/

int main(int argc, char** argv)
{
	auto debug = std::make_unique<DrillingSystem::DrillingEngine::Debug>();
		
	debug->Run();

	return EXIT_SUCCESS;
}