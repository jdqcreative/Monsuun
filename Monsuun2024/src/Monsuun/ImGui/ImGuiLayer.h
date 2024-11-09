#pragma once

#include "Monsuun/Core/Layer.h"

#include "Monsuun/Events/MouseEvent.h"
#include "Monsuun/Events/KeyEvent.h"
#include "Monsuun/Events/ApplicationEvent.h"

namespace Monsuun {

	class MONSUUN_API ImGuiLayer : public Layer
	{
	public:

		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		
		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};

}