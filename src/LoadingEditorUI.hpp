#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class LoadingEditorUI : public CCLayer {
protected:
    CCMenuItemSpriteExtra* hideToolbar;
    CCMenuItemSpriteExtra* hideBoxB;
    CCMenuItemSpriteExtra* reset;
    CCLayerColor* toolbar;
    bool init();
    void moving(CCObject* sender);
    void moveHidebutton();
    void Reset(CCObject* sender);
    
public:
    static LoadingEditorUI* create();
};