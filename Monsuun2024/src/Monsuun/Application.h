#pragma once

#include "Core.h"

#include "Window.h"
#include "Monsuun/LayerStack.h"
#include "Events/Event.h"
#include "Monsuun/Events/ApplicationEvent.h"

#include "Monsuun/ImGui/ImGuiLayer.h"

namespace Monsuun {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		// Temporary?: Hacky ImGui Implementation
		inline static Application& Get() { return *s_Instance; }

		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}