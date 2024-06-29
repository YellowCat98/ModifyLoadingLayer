#include "DragNode.hpp" // already includes geode and geode ns
#include "MMLManager.hpp"

#include <utility>

bool DragNode::init(std::function<void()> onClick, std::function<void()> onRelease, CCSprite* THEFUCKINGSPRITE) {
    if (!CCLayer::init()) return false;
    m_onClick = std::move(onClick);
    m_onRelease = std::move(onRelease);

    this->addChild(THEFUCKINGSPRITE);
    THEFUCKINGSPRITE->setID("the-sprite");
    this->setTouchMode(kCCTouchesOneByOne);
    this->setTouchEnabled(true);

    this->ignoreAnchorPointForPosition(false);
    
    return true;
}

bool DragNode::ccTouchBegan(CCTouch* touch, CCEvent*) {
    auto const point = this->getParent()->convertToNodeSpace(touch->getLocation());

    auto const rect = this->boundingBox();
    if (rect.containsPoint(point)) {
        if (m_onClick)
            m_onClick();
        return true;
    }
    return false;
}

void DragNode::ccTouchMoved(CCTouch* touch, CCEvent*) {
    MMLManager* mmlm = MMLManager::get();
    mmlm->drag(this);
}

void DragNode::ccTouchEnded(CCTouch* touch, CCEvent*) {
    if (m_onRelease)
        m_onRelease();
}

DragNode* DragNode::create(std::function<void()> onClick, std::function<void()> onRelease, CCSprite* THEFUCKINGSPRITE) {
    auto ret = new DragNode;
    if (ret->init(std::move(onClick), std::move(onRelease), THEFUCKINGSPRITE)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}