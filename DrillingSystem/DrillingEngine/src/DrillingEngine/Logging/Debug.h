#pragma once

#include "DrillingEngine/Logging/Logging.h"
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

	private:
		std::unique_ptr<DrillingSystem::DrillingEngine::DrillingEngine> m_DrillingEngine;
	};
}

#endif // DEBUG_H