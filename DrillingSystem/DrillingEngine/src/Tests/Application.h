#pragma once

#include "DrillingSystem.h"

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