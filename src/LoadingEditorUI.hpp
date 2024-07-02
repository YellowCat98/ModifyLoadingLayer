#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class LoadingEditorUI : public CCLayer {
protected:
    CCMenuItemSpriteExtra* hideToolbar;
    CCMenuItemSpriteExtra* hideBoxB;
    CCLayerColor* toolbar;
    bool init();
    void moving(CCObject* sender);
    void moveHidebutton();
    
public:
    static LoadingEditorUI* create();
};