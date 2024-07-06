#pragma once
#include <Geode/Geode.hpp>
#include "MLLManager.hpp"

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
	bool init();
	void moving(CCObject* sender);
	void moveHidebutton();
	void Reset(CCObject* sender);
	void Restart(CCObject* sender);
	void hideMainF(CCObject* sender);
	void canMoveF(CCObject* sender);
	
public:
	static LoadingEditorUI* create();
	MLLManager* mllm;
};