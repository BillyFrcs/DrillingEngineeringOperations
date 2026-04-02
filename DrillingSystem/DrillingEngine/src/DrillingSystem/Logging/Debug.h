#pragma once

#include <iostream>
#include <cmath>

#include "spdlog/spdlog.h"
#include "DrillingSystem/Engine/DrillingEngine.h"

#ifndef APPLICATION_H
#define APPLICATION_H

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

#endif // APPLICATION_H