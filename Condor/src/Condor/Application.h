#pragma once
#include "Core.h"

namespace Condor {
	class CONDOR_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//TO be defined in client
	Application* CreateApplication();

}
