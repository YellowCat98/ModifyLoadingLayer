#include "DragNode.hpp" // already includes geode and geode ns
#include "MLLManager.hpp"

#include <utility>

bool DragNode::init(CCSprite* THEFUCKINGSPRITE) {
    if (!CCLayerColor::init()) return false;
    if (THEFUCKINGSPRITE) {
        theSprite = THEFUCKINGSPRITE;
        this->addChild(THEFUCKINGSPRITE);
        auto sprSize = THEFUCKINGSPRITE->getContentSize();
        THEFUCKINGSPRITE->setID("the-sprite");
        this->setContentSize(sprSize);
        auto size = this->getContentSize();
        auto center = CCPoint(size.width / 2, size.height / 2);
        THEFUCKINGSPRITE->setPosition(center);
    } else {
        return false;
    }

    
    
    this->setTouchMode(kCCTouchesOneByOne);
    this->setTouchEnabled(true);

    this->ignoreAnchorPointForPosition(false);
    
    return true;
}

bool DragNode::ccTouchBegan(CCTouch* touch, CCEvent*) {
    auto const point = this->getParent()->convertToNodeSpace(touch->getLocation());

    auto const rect = this->boundingBox();
    if (rect.containsPoint(point)) {
        log::info("clicked node");
        return true;
    }
    return false;
}

void DragNode::ccTouchMoved(CCTouch* touch, CCEvent*) {
    MLLManager* mmlm = MLLManager::get();
    mmlm->drag(this, touch);
}

void DragNode::ccTouchEnded(CCTouch* touch, CCEvent*) {
    log::info("not clicking node");
}

void DragNode::setColor(const ccColor3B& color3) {
    if (theSprite) {
        theSprite->setColor(color3);
    } else {
        return;
    }
}

DragNode* DragNode::create(CCSprite* THEFUCKINGSPRITE) {
    auto ret = new DragNode;
    if (ret->init(THEFUCKINGSPRITE)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}