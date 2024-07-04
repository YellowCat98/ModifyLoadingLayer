#include "RotationControl.hpp"
#include "MLLManager.hpp"

bool RotationControl::init() {
    if (!GJRotationControl::init()) return false;
    this->setTouchMode(kCCTouchesOneByOne);
    this->setTouchEnabled(true);
    this->ignoreAnchorPointForPosition(false);
    sprite = getChildOfType<CCSprite>(this, 0);
    log::info("sprite REAL: {}", sprite->getPosition());
    return true;
}

bool RotationControl::ccTouchBegan(CCTouch* touch, CCEvent* event) {
    auto const point = sprite->getParent()->convertToNodeSpace(touch->getLocation());

    auto const rect = sprite->boundingBox();
    if (rect.containsPoint(point)) {
        return true;
    }
    return false;
}

void RotationControl::ccTouchMoved(CCTouch* touch, CCEvent* event) {
    auto mllm = MLLManager::get();
    mllm->rotateAroundPoint(sprite, touch, 60.0f, CCPoint(this->getPosition().x - this->getAnchorPoint().x * this->getContentSize().width, this->getPosition().y - this->getAnchorPoint().y * this->getContentSize().height));
    sprite->setTexture(CCSprite::createWithSpriteFrameName("GJ_rotationControlBtn02_001.png")->getTexture());
}

RotationControl* RotationControl::create() {
    auto ret = new RotationControl();
    if (ret->init()) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}