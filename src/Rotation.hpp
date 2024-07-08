#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class Rotation : public CCLayer {
public:
	CCTouch* thetouch;
	bool init(std::string theNodeID);
	void rotate(const std::string& nodeID, CCTouch* touch);
	std::string nodeID;

	bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	void ccTouchMoved(CCTouch* touch, CCEvent* event);
	static Rotation* get(std::string theNodeID);
};