#pragma once
#include "Core.h"

namespace Condor {
	//Define Application class for Condor applications
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
