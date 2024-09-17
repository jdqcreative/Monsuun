#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Monsuun {

	class MONSUUN_API Log
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
#define MO_CORE_TRACE(...)  ::Monsuun::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MO_CORE_INFO(...)   ::Monsuun::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MO_CORE_WARN(...)   ::Monsuun::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MO_CORE_ERROR(...)  ::Monsuun::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MO_CORE_FATAL(...)  ::Monsuun::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define MO_TRACE(...)       ::Monsuun::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MO_INFO(...)        ::Monsuun::Log::GetClientLogger()->info(__VA_ARGS__)
#define MO_WARN(...)        ::Monsuun::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MO_ERROR(...)       ::Monsuun::Log::GetClientLogger()->error(__VA_ARGS__)
#define MO_FATAL(...)       ::Monsuun::Log::GetClientLogger()->critical(__VA_ARGS__)