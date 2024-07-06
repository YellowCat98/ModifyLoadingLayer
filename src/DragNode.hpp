#pragma once
#include <Geode/Geode.hpp>
#include "MLLManager.hpp"

using namespace geode::prelude;

class DragNode : public CCLayerColor {
protected:
	CCSprite* theSprite;
	CCLayerColor* selectedDisplay;

	bool init(CCSprite* THEFUCKINGSPRITE);

	bool ccTouchBegan(CCTouch* touch, CCEvent*) override;
	void ccTouchMoved(CCTouch* touch, CCEvent*) override;
	void ccTouchEnded(CCTouch* touch, CCEvent*) override;

	void selectNode(const std::string& nodeID);
public:
	static DragNode* create(CCSprite* THEFUCKINGSPRITE);
	virtual void setColor(const ccColor3B& color3) override;
	MLLManager* mllm;
};