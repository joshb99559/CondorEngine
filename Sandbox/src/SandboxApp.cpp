#include <Condor.h>

class Sandbox : public Condor::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}


};

Condor::Application* Condor::CreateApplication()
{
	return new Sandbox();
}