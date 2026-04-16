#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

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
		static void Warning(const T& value)
		{
			spdlog::warn(value);
		}

		template<typename T>
		static void Critical(const T& value)
		{
			spdlog::critical(value);
		}

		template<typename T>
		static void Debug(const T& value)
		{
			spdlog::set_level(spdlog::level::debug);

			spdlog::debug(value);
		}

		template<typename T>
		static void Console(const T& value)
		{
			auto console = spdlog::stdout_color_mt("console");
			auto err_logger = spdlog::stderr_color_mt("stderr");

			spdlog::get("console")->info(value);
		}
	};
}

#endif // LOGGING_H