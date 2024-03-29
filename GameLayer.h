#pragma once
#include <Engine3D/Core/Layer.h>
#include "Level.h"
#include <imgui/imgui.h>
#include <Engine3D/Events/KeyEvent.h>
#include <Engine3D/Events/MouseEvent.h>
#include <Engine3D/Renderer2D/OrthographicCamera.h>

class GameLayer : public Engine3D::Layer{
public:
	GameLayer();

	virtual void onAttach() override;

	virtual void onDetach() override;

	virtual void onUpdate(Engine3D::Timestep ts) override;

	virtual void onImguiRender() override;

	virtual void onEvent(Engine3D::Event& event) override;

	bool onMouseButtonPressed(Engine3D::MouseButtonPressedEvent& event);
	bool onWindowResize(Engine3D::WindowResizeEvent& event);

private:
	void createCamera(uint32_t w, uint32_t h);

private:
	Engine3D::Scope<Engine3D::OrthographicCamera> camera;
	Level level;
	ImFont* font;

	enum class GameState {
		Play=0,
		MainMenu=1,
		GameOver=2
	};

	GameState state = GameState::MainMenu;
	float time = 0.0f;
	float blink = false;
};
