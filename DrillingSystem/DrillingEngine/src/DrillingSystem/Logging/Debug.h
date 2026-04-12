#pragma once

#include <iostream>
#include <cmath>

#include "spdlog/spdlog.h"
#include "DrillingSystem/Engine/DrillingEngine.h"

#ifndef DEBUG_H
#define DEBUG_H

namespace DrillingSystem
{
	class Debug
	{
	public:
		Debug();

		~Debug();

		void EquivalentCirculatingDensity();

		void HydrostaticPressure();

		void KillWeightMud();

		void Run();

		template <typename T>
		static void DrillingLog(const T& log);

	private:
		std::unique_ptr<DrillingSystem::DrillingEngine> m_DrillingEnginePtr;
	};
}

#endif // DEBUG_H