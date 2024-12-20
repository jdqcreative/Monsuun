#pragma once

#include "Monsuun.h"

#include "ParticleSystem.h"

class Sandbox2D : public Monsuun::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Monsuun::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Monsuun::Event& e) override;

private:
	Monsuun::OrthographicCameraController m_CameraController;

	// Temp
	Monsuun::Ref<Monsuun::VertexArray> m_SquareVA;
	Monsuun::Ref<Monsuun::Shader> m_FlatColorShader;

	Monsuun::Ref<Monsuun::Texture2D> m_CheckerboardTexture;
	Monsuun::Ref<Monsuun::Texture2D> m_SpriteSheet;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

	ParticleSystem m_ParticleSystem;
	ParticleProps m_Particle;
};