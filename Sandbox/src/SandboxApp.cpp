#include <Monsuun.h>

#include "imgui/imgui.h"

class ExampleLayer : public Monsuun::Layer
{
public:

	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(Monsuun::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			0.0f, 0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		std::shared_ptr<Monsuun::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Monsuun::VertexBuffer::Create(vertices, sizeof(vertices)));

		Monsuun::BufferLayout layout = {
			{ Monsuun::ShaderDataType::Float3, "a_Position"},
			{ Monsuun::ShaderDataType::Float4, "a_Color"}
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		std::shared_ptr<Monsuun::IndexBuffer> indexBuffer;
		indexBuffer.reset(Monsuun::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Monsuun::VertexArray::Create());

		float squarVertices[3 * 4] = {
			-0.75f, -0.75f, 0.0f,
			 0.75f, -0.75f, 0.0f,
			 0.75f,  0.75f, 0.0f,
			-0.75f,  0.75f, 0.0f
		};

		std::shared_ptr<Monsuun::VertexBuffer> squareVB;
		squareVB.reset(Monsuun::VertexBuffer::Create(squarVertices, sizeof(squarVertices)));
		squareVB->SetLayout({
			{ Monsuun::ShaderDataType::Float3, "a_Position"},
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Monsuun::IndexBuffer> squareIB;
		squareIB.reset(Monsuun::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(

#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;

uniform mat4 u_ViewProjection;

out vec3 v_Position;
out vec4 v_Color;

void main()
{
	v_Position = a_Position;
	v_Color = a_Color;
	gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
}

		)";

		std::string fragmentSrc = R"(

#version 330 core

layout(location = 0) out vec4 color;

in vec3 v_Position;
in vec4 v_Color;

void main()
{
	color = vec4(v_Position * 0.5 + 0.5, 1.0);
	color = v_Color;
}

		)";

		m_Shader.reset(new Monsuun::Shader(vertexSrc, fragmentSrc));

		std::string blueShaderVertexSrc = R"(

#version 330 core

layout(location = 0) in vec3 a_Position;

uniform mat4 u_ViewProjection;

out vec3 v_Position;

void main()
{
	v_Position = a_Position;
	gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
}

		)";

		std::string blueShaderFragmentSrc = R"(

#version 330 core

layout(location = 0) out vec4 color;

in vec3 v_Position;

void main()
{
	color = vec4(0.2, 0.3, 0.8, 1.0);
}

		)";

		m_BlueShader.reset(new Monsuun::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
	}

	void OnUpdate() override
	{
		if (Monsuun::Input::IsKeyPressed(MU_KEY_A))
			m_CameraPosition.x -= m_CameraMoveSpeed;
		else if (Monsuun::Input::IsKeyPressed(MU_KEY_D))
			m_CameraPosition.x += m_CameraMoveSpeed;

		if (Monsuun::Input::IsKeyPressed(MU_KEY_S))
			m_CameraPosition.y -= m_CameraMoveSpeed;
		else if (Monsuun::Input::IsKeyPressed(MU_KEY_W))
			m_CameraPosition.y += m_CameraMoveSpeed;

		if (Monsuun::Input::IsKeyPressed(MU_KEY_Q))
			m_CameraRotation += m_CameraRotationSpeed;
		if (Monsuun::Input::IsKeyPressed(MU_KEY_E))
			m_CameraRotation -= m_CameraRotationSpeed;

		Monsuun::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Monsuun::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Monsuun::Renderer::BeginScene(m_Camera);

		Monsuun::Renderer::Submit(m_BlueShader, m_SquareVA);
		Monsuun::Renderer::Submit(m_Shader, m_VertexArray);

		Monsuun::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		
	}

	void OnEvent(Monsuun::Event& event) override
	{}

private:
	std::shared_ptr<Monsuun::Shader> m_Shader;
	std::shared_ptr<Monsuun::VertexArray> m_VertexArray;

	std::shared_ptr<Monsuun::Shader> m_BlueShader;
	std::shared_ptr<Monsuun::VertexArray> m_SquareVA;

	Monsuun::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 0.1f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 2.0f;
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