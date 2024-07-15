#pragma once
#include <Geode/Geode.hpp>
#include "../MLLManager.hpp"
#include "Rotation.hpp"
#include "Scale.hpp"
#include "RGBA.hpp"
using namespace geode::prelude;

class LoadingEditorUI : public CCLayer {
protected:
	
	CCMenuItemSpriteExtra* hideToolbar;
	CCMenuItemSpriteExtra* hideBoxB;
	CCMenuItemSpriteExtra* reset;
	CCMenuItemSpriteExtra* restart;
	CCLayerColor* toolbar;
	CCLayerColor* main;
	CCMenu* mainMenu;
	CCSize winSize;
	CCMenuItemSpriteExtra* hideMain;
	CCMenuItemToggler* selectMove;
	CCMenuItemToggler* brainRot;
	CCMenuItemToggler* scale;
	CCMenuItemToggler* hideBtn;
	CCArray* buttonArray;
	Rotation* r;
	Scale* scaleInstance;
	_rgba* _rgba;
	CCMenuItemSpriteExtra* saveBtn;
	bool canRotate;
	bool canScale;
	bool canOpacity;
	EventListener<Task<Result<std::filesystem::path>>> m_pickListener;
	std::filesystem::path temp;
	bool init();
	void moving(CCObject* sender);
	void moveHidebutton();
	void Reset(CCObject* sender);
	void Restart(CCObject* sender);
	void hideMainF(CCObject* sender);
	void canMoveF(CCObject* sender);
	void canRotateF(CCObject* sender);
	void onScale(CCObject* sender);
	void onHide(CCObject* sender);
	void onChangeSprite(CCObject* sender);
	void Save(CCObject* sender);
	CCTexture2D* texture;
public:
	static LoadingEditorUI* create();
	MLLManager* mllm;
};