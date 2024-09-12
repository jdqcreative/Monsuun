#pragma once

#include "Core.h"

namespace Monsuun {

	class MONSUUN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}