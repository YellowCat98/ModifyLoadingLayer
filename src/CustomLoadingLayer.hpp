#pragma once
#include <Geode/Geode.hpp>
#include "DragNode.hpp"

using namespace geode::prelude;

class CustomLoadingLayer : public cocos2d::CCLayer {
public:
    DragNode* robtoplogo;
    DragNode* fmodlogo;
    DragNode* cocos2dlogo;
    DragNode* gdlogo;
    CCSprite* bgtexture;
    static CustomLoadingLayer* create();
    void resetPosition();
private:
    bool init() override;
};