#pragma once

#include "Application.h"

#ifdef MO_PLATFORM_WINDOWS

extern Monsuun::Application* Monsuun::CreateApplication();

int main(int argc, char** argv)
{
	// Temporary
	Monsuun::Log::Init();
	MO_CORE_WARN("Initialized Log!");
	int a = 5;
	MO_INFO("Hello! Var={0}", a);

	auto app = Monsuun::CreateApplication();
	app->Run();
	delete app;
}

#endif