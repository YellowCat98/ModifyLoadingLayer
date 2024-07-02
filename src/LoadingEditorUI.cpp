#include "LoadingEditorUI.hpp"
#include "MMLManager.hpp" // for CCMENUISE_REMOVE_EASE

bool LoadingEditorUI::init() {
    if (!CCLayer::init()) return false;
    // <create toolbar>
    toolbar = CCLayerColor::create();
    float top = CCDirector::sharedDirector()->getWinSize().height;

    toolbar->setPositionY(top - 20.0f);

    auto size = this->getContentSize();
    toolbar->setContentSize({size.width, 20.0f});
    toolbar->setOpacity(150);
    auto menu = CCMenu::create();
    menu->setPosition({0.0f, 0.0f});
    menu->setContentSize({size.width, 20.0f});
    toolbar->addChild(menu);
    this->addChild(toolbar);
    // </create toolbar>

    // <create hide toolbar>
    auto moveBtn = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png"), this, menu_selector(LoadingEditorUI::moving));
    moveBtn->setRotation(-90.0f);
    moveBtn->setPosition({10.0f, 10.0f});
    moveBtn->setScale(0.5f);
    CCMENUISE_REMOVE_EASE(moveBtn);
    menu->addChild(moveBtn);
    hideToolbar = moveBtn;
    // </create hide toolbar>

    return true;
}

void LoadingEditorUI::moving(CCObject* sender) {
    hideToolbar->setScale(0.5f); // thanks!
    hideToolbar->setEnabled(false);
    static bool shown = true;
    float duration = 0.4f;
    float deltaY;
    float fartY;
    float positionY = this->getPositionY();
    if (shown) {
        deltaY = 20.0f;
        fartY = -20.0f;
        shown = false;
    } else {
        deltaY = -20.0f;
        fartY = 20.0f;
        shown = true;
    }

    auto moveBy = CCMoveBy::create(duration, CCPoint(0, deltaY));
    auto fartBy = CCMoveBy::create(duration, CCPoint(0, fartY));

    auto easeSineOut = CCEaseSineOut::create(moveBy);
    auto easeFartOut = CCEaseSineOut::create(fartBy);

    toolbar->runAction(easeSineOut);

    auto callback = CCCallFunc::create(this, callfunc_selector(LoadingEditorUI::moveHidebutton));
    
    if (callback) {
        auto sequence = CCSequence::create(CCDelayTime::create(0.4f), easeFartOut, callback, nullptr);
        if (sequence) {
            hideToolbar->runAction(sequence);
        }
    }
}

void LoadingEditorUI::moveHidebutton() {
    hideToolbar->setEnabled(true);
}

LoadingEditorUI* LoadingEditorUI::create() {
    LoadingEditorUI* layer = new LoadingEditorUI();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}