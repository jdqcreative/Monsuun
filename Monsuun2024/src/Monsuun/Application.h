#pragma once

#include "Core.h"

#include "Window.h"
#include "Monsuun/LayerStack.h"
#include "Events/Event.h"
#include "Monsuun/Events/ApplicationEvent.h"

#include "Monsuun/ImGui/ImGuiLayer.h"

#include "Monsuun/Renderer/Shader.h"
#include "Monsuun/Renderer/Buffer.h"

namespace Monsuun {

	class MONSUUN_API Application
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

		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}