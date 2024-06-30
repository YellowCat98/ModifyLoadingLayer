#include "Toolbar.hpp"

bool Toolbar::init() {
    if (!CCLayerColor::init()) return false;
    float top = CCDirector::sharedDirector()->getWinSize().height;

    this->setPositionY(top - 20.0f);

    auto size = this->getContentSize();
    this->setContentSize({size.width, 20.0f});
    this->setOpacity(150);
    auto menu = CCMenu::create();
    menu->setPosition({0.0f, 0.0f});
    menu->setContentSize({size.width, 20.0f});
    this->addChild(menu);
    

    auto moveBtn = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png"), this, menu_selector(Toolbar::moving));
    menu->addChild(moveBtn);

    return true;
}

void Toolbar::moving(CCObject* sender) {
    float duration = 0.4f;
    float deltaY = (this->getPositionY() + 20.0f) - 300; // wtf

    auto moveBy = CCMoveBy::create(duration, CCPoint(0, deltaY));

    auto easeSineOut = CCEaseSineOut::create(moveBy);

    this->runAction(easeSineOut);
}

Toolbar* Toolbar::create() {
    Toolbar* layer = new Toolbar();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}