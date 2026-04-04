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

		static void Run();

		template <typename T>
		static void DrillingLog(const T& log);
	};
}

#endif // DEBUG_H