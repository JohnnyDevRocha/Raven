#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Raven {

	class RAVEN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define RV_CORE_ERROR(...)   ::Raven::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RV_CORE_WARN(...)    ::Raven::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RV_CORE_INFO(...)    ::Raven::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RV_CORE_TRACE(...)   ::Raven::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RV_CORE_FATAL(...)   ::Raven::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client log macros
#define RV_ERROR(...)   ::Raven::Log::GetClientLogger()->error(__VA_ARGS__)
#define RV_WARN(...)    ::Raven::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RV_INFO(...)    ::Raven::Log::GetClientLogger()->info(__VA_ARGS__)
#define RV_TRACE(...)   ::Raven::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RV_FATAL(...)   ::Raven::Log::GetClientLogger()->fatal(__VA_ARGS__)