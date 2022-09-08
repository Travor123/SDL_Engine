#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__

#include "Scene.h"
#include "Plane.h"
#include "Player.h"
#include "Button.h"
#include "Label.h"

const float PHYSICS_UPDATE_RATE = 1.0 / 60.0;

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene() override;

	// Scene LifeCycle Functions
	virtual void Draw() override;
	virtual void Update() override;
	virtual void Clean() override;
	virtual void HandleEvents() override;
	virtual void Start() override;
private:
	// IMGUI Function
	void GUI_Function();
	std::string m_guiTitle;
	
	glm::vec2 m_mousePosition;

	Plane* m_pPlaneSprite{};
	Player* m_pPlayer{};
	bool m_playerFacingRight{};

	float x1 = 0;
	float y1 = 0;

	float x2 = 0;
	float y2 = 0;

	float t = 0.0f;
	float dt = PHYSICS_UPDATE_RATE;
	float a = 1.0f;
	float b = 100.0f;
	float c = 100.0f;
	float d = 100.0f;


	// UI Items
	Button* m_pBackButton{};
	Button* m_pNextButton{};
	Label* m_pInstructionsLabel{};

	// Input Control
	int m_pCurrentInputType{};
	void GetPlayerInput();
	void GetKeyboardInput();
};

#endif /* defined (__PLAY_SCENE__) */