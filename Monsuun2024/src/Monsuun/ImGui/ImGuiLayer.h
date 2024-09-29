#pragma once

#include "Monsuun/Layer.h"

#include "Monsuun/Events/MouseEvent.h"
#include "Monsuun/Events/KeyEvent.h"
#include "Monsuun/Events/ApplicationEvent.h"

namespace Monsuun {

	class MONSUUN_API ImGuiLayer : public Layer
	{
	public:

		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);

		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);

		bool OnWindowResizedEvent(WindowResizeEvent& e);

	private:
		float m_Time = 0.0f;
	};

}