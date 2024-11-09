#pragma once

#include "Application.h"

#ifdef MO_PLATFORM_WINDOWS

extern Monsuun::Application* Monsuun::CreateApplication();

int main(int argc, char** argv)
{
	Monsuun::Log::Init();

	MU_PROFILE_BEGIN_SESSION("Startup", "MonsuunProfile-Startup.json");
	auto app = Monsuun::CreateApplication();
	MU_PROFILE_END_SESSION();

	MU_PROFILE_BEGIN_SESSION("Runtime", "MonsuunProfile-Runtime.json");
	app->Run();
	MU_PROFILE_END_SESSION();

	MU_PROFILE_BEGIN_SESSION("Shutdown", "MonsuunProfile-Shutdown.json");
	delete app;
	MU_PROFILE_END_SESSION();
}

#endif