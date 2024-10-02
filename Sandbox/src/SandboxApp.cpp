#include <Monsuun.h>

class ExampleLayer : public Monsuun::Layer
{
public:

	ExampleLayer()
		: Layer("Example")
	{}

	void OnUpdate() override
	{
		if (Monsuun::Input::IsKeyPressed(MU_KEY_TAB))
			MU_TRACE("Tab key is pressed");
	}

	void OnEvent(Monsuun::Event& event) override
	{
		//MU_TRACE("{0}", event);
	}

};

class Sandbox : public Monsuun::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{}

};

Monsuun::Application* Monsuun::CreateApplication()
{
	return new Sandbox();
}