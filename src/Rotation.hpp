#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class Rotation : public CCLayer {
private:
	CCTouch* thetouch;
	bool init(std::string theNodeID);
	void rotate(const std::string& nodeID, CCTouch* touch);
	std::string nodeID;
	CCLabelBMFont* label;

	bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	void ccTouchMoved(CCTouch* touch, CCEvent* event);
public:
	static Rotation* get(std::string theNodeID);
};