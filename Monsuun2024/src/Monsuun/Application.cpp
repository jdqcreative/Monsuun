#include "Application.h"

#include "Monsuun/Events/ApplicationEvent.h"
#include "Monsuun/Log.h"

namespace Monsuun {

	Application::Application()
	{}

	Application::~Application()
	{}

	void Application::Run() 
	{
		WindowResizeEvent e(1280, 720);
		MO_TRACE(e);

		while (true);
	}

}