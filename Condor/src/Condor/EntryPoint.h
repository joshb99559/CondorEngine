#pragma once

#ifdef CD_PLATFORM_WINDOWS

extern Condor::Application* Condor::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Condor::CreateApplication();
	app->Run();
	delete app;
}

#endif
