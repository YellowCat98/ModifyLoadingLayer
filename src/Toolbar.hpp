#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class Toolbar : public CCLayerColor {
protected:
    CCMenuItemSpriteExtra* hideToolbar;
    CCEaseSineOut* action; // this code is getting horrible
    bool init();
    void moving(CCObject* sender);
    void moveHidebutton();
    
public:
    static Toolbar* create();
};