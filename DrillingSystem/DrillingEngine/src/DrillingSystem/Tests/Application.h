#pragma once

#include <iostream>
#include <cmath>

#include "DrillingSystem/Engine/DrillingEngine.h"

#ifndef APPLICATION_H
#define APPLICATION_H

namespace DrillingSystem
{
	class Application
	{
	public:
		Application();

		~Application();

		static void Run();
	};
}

#endif // APPLICATION_H