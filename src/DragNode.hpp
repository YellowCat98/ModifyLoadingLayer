#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class DragNode : public CCLayer {
protected:
    std::function<void()> m_onClick;
    std::function<void()> m_onRelease;

    bool init(std::function<void()> onClick, std::function<void()> onRelease, CCSprite* THEFUCKINGSPRITE);

    bool ccTouchBegan(CCTouch* touch, CCEvent*) override;
    void ccTouchMoved(CCTouch* touch, CCEvent*) override;
    void ccTouchEnded(CCTouch* touch, CCEvent*) override;
public:
    static DragNode* create(std::function<void()> onClick, std::function<void()> onRelease, CCSprite* THEFUCKINGSPRITE);
};