#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class DragNode : public CCLayerColor {
protected:
    std::function<void()> m_onClick;
    std::function<void()> m_onRelease;
    CCSprite* theSprite;

    bool init(std::function<void()> onClick, std::function<void()> onRelease, CCSprite* THEFUCKINGSPRITE);



    bool ccTouchBegan(CCTouch* touch, CCEvent*) override;
    void ccTouchMoved(CCTouch* touch, CCEvent*) override;
    void ccTouchEnded(CCTouch* touch, CCEvent*) override;
public:
    static DragNode* create(std::function<void()> onClick, std::function<void()> onRelease, CCSprite* THEFUCKINGSPRITE);
    virtual void setColor(const ccColor3B& color3) override;
};