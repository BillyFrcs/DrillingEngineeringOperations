#pragma once

#include <iostream>
#include <cmath>

#include "spdlog/spdlog.h"
#include "DrillingEngine/Core/DrillingEngine.h"

#ifndef DEBUG_H
#define DEBUG_H

namespace DrillingSystem::DrillingEngine
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
		std::unique_ptr<DrillingSystem::DrillingEngine::DrillingEngine> m_DrillingEngine;
	};
}

#endif // DEBUG_H