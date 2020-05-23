#pragma once
#pragma warning( disable : 4996 ) 
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Condor {
	class CONDOR_API Log
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

// Core Log macros
#define CD_CORE_TRACE(...)   	 ::Condor::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CD_CORE_INFO(...)    	 ::Condor::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CD_CORE_WARN(...)        ::Condor::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CD_CORE_ERROR(...)       ::Condor::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CD_CORE_FATAL(...)       ::Condor::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros
#define CD_TRACE(...)   	     ::Condor::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CD_INFO(...)    	     ::Condor::Log::GetClientLogger()->info(__VA_ARGS__)
#define CD_WARN(...)             ::Condor::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CD_ERROR(...)            ::Condor::Log::GetClientLogger()->error(__VA_ARGS__)
#define CD_FATAL(...)            ::Condor::Log::GetClientLogger()->fatal(__VA_ARGS__)
