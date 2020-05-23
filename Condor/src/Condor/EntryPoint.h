#pragma once

#ifdef CD_PLATFORM_WINDOWS
//Require app to supply Application object with implementation of CreateApplication to return an instance
extern Condor::Application* Condor::CreateApplication();

int main(int argc, char** argv)
{

	Condor::Log::Init();
	CD_CORE_WARN("Initialized Log");
	int a = 5;
	CD_INFO("Hello Var = {0}", a);


	auto app = Condor::CreateApplication();
	app->Run();
	delete app;
}

#endif
