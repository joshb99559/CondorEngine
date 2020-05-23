#include <Condor.h>
//Sandbox is of type Application
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