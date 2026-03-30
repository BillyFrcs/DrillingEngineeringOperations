#pragma once

#include <iostream>
#include <cmath>

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
	};
}

#endif // APPLICATION_H