#include "Rotation.hpp"
#include "MLLManager.hpp"

bool Rotation::init() {
    if (!CCLayer::init()) return false;
    this->addChild(CCSprite::createWithSpriteFrameName("GJ_rotationControlBtn01_001.png"));

    this->setTouchMode(kCCTouchesOneByOne);
    this->setTouchEnabled(true);
    this->ignoreAnchorPointForPosition(false);

    return true;
}

bool Rotation::ccTouchBegan(CCTouch* touch, CCEvent* event) {
    log::info("touch");
    return true;
}

void Rotation::ccTouchMoved(CCTouch* touch, CCEvent* event) {
    MLLManager::get()->drag(this, touch);
    this->rotate("main-title");
}

void Rotation::rotate(const std::string& nodeID) {
    auto node = this->getParent()->getChildByIDRecursive(nodeID);
    float dx = node->getPositionX();
    float dy = node->getPositionY();
    float angle = atan2(dy, dx);
    angle = CC_RADIANS_TO_DEGREES(angle) + 90.0f;
    node->setRotation(angle);
}

Rotation* Rotation::create() {
    auto ret = new Rotation();

    if (ret->init()) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}