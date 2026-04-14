#pragma once

#include <iostream>
#include <cmath>

#include "spdlog/spdlog.h"

#ifndef LOGGING_H
#define LOGGING_H

namespace DrillingSystem::DrillingEngine
{
	class Logging
	{
	public:
		Logging();

		~Logging();

		template <typename T>
		static void Info(const T& value)
		{
			spdlog::info(value);
		}

		template<typename T>
		static void Error(const T& value)
		{
			spdlog::error(value);
		}

		template<typename T>
		static void Debug(const T& value)
		{
			spdlog::debug(value);
		}

		template<typename T>
		static void Warning(const T& value)
		{
			spdlog::warn(value);
		}

		template<typename T>
		static void Critical(const T& value)
		{
			spdlog::critical(value);
		}
	};
}

#endif // LOGGING_H