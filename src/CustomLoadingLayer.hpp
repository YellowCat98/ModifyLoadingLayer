#pragma once
#include <Geode/Geode.hpp>
#include "DragNode.hpp"
#include "MLLManager.hpp"

using namespace geode::prelude;

class CustomLoadingLayer : public cocos2d::CCLayer {
public:
    DragNode* robtoplogo;
    DragNode* fmodlogo;
    DragNode* cocos2dlogo;
    DragNode* gdlogo;
    CCSprite* bgtexture;
    MLLManager* mllm;
    std::map<std::string, std::map<std::string, float>> DefaultPositions;
    std::map<std::string, std::map<std::string, float>> Positions;

    static CustomLoadingLayer* create();
    void resetPosition();
    void getPositions();
private:
    bool init() override;
};