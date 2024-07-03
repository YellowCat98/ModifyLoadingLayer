#include <Geode/Geode.hpp>

using namespace geode::prelude;

// i couldnt use robs GJRotationControl so i used my own!!
class RotationControl : public GJRotationControl {
public:
    CCSprite* sprite;
    bool init() override;
    bool ccTouchBegan(CCTouch* touch, CCEvent* event) override;
    void ccTouchMoved(CCTouch* touch, CCEvent* event) override;
    static RotationControl* create();
};