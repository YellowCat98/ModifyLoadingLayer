#include "MMLManager.hpp"
#include "DragNode.hpp"

bool MMLManager::init() {
    if (!CCNode::init()) return false;

    return true;
}

void MMLManager::drag(DragNode* node, CCTouch* touch) {
    auto touchLoc = touch->getLocation();

    auto nodeParent = node->getParent();
    if (nodeParent) {
        auto nodePosition = nodeParent->convertToNodeSpace(touchLoc);
        node->setPosition(nodePosition);
    }
}

MMLManager* MMLManager::get() {
    MMLManager* layer = new MMLManager();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}