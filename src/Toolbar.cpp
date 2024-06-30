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
    themenu = menu;

    return true;
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