#include "MMLManager.hpp"
#include "DragNode.hpp"

bool MMLManager::init() {
    if (!CCNode::init()) return false;

    return true;
}

void MMLManager::drag(DragNode* node) {
    auto m_toDrag = node;
    auto m_lastDrag = -1;

    auto const pos = node->convertToWorldSpace(node->getPosition());

    node->setPosition(this->convertToNodeSpace(pos));
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