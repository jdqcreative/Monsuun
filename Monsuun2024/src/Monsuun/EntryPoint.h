#pragma once

#include "Application.h"

#ifdef MO_PLATFORM_WINDOWS

extern Monsuun::Application* Monsuun::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Monsuun::CreateApplication();
	app->Run();
	delete app;
}

#endif