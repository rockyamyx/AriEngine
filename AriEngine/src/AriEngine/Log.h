#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace AriEngine {

	class ARI_API Log
	{
		public:
			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_CoreLogger;  }

		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define AE_CORE_TRACE(...)	::AriEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AE_CORE_INFO(...)	::AriEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AE_CORE_WARN(...)	::AriEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AE_CORE_ERROR(...)	::AriEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AE_CORE_FATAL(...)	::AriEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define AE_TRACE(...)		::AriEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AE_INFO(...)		::AriEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define AE_WARN(...)		::AriEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AE_ERROR(...)		::AriEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define AE_FATAL(...)		::AriEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
