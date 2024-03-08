#pragma once

class CustomLoadingLayer : public cocos2d::CCLayer {
    public:
    static CustomLoadingLayer* create();
    private:
    bool init() override;
};