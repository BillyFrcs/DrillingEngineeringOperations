#pragma once

#include <iostream>
#include <print>
#include <memory>

#include "HoistingSystem/Calculations/RigDerrickLoad.h"
#include "HoistingSystem/Calculations/BlockAndDrillingLine.h"
#include "HoistingSystem/Calculations/BlockAndDrillingLine.h"
#include "HoistingSystem/Calculations/HoistingAndDrawwoksAnalysis.h"
#include "HoistingSystem/Calculations/OilWellBlockAndTackleSystem.h"

#ifndef APPLICATION_H
#define APPLICATION_H

namespace HoistingSystem
{
	class Application
	{
	public:
		Application() = default;

		~Application() = default;

		void Run();

		void RigDerrickLoad();

		void BlockAndDrillingLine();

		void HoistingAndDrawworksAnalysis();

		void OilWellBlockAndTackleSystem();
	};
}

#endif // APPLICATION_H