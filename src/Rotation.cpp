#include "Rotation.hpp"

bool Rotation::init() {
    if (!CCNode::init()) return false;
    this->addChild(CCSprite::createWithSpriteFrameName("GJ_rotationControlBtn01_001.png"));
    return true;
}

Rotation* create() {
    auto ret = new Rotation();

    if (ret->init()) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}