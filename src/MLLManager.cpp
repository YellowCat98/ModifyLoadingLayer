#include "MLLManager.hpp"
#include "DragNode.hpp"

bool MLLManager::init() {
    if (!CCNode::init()) return false;

    return true;
}

void MLLManager::drag(DragNode* node, CCTouch* touch) {
    auto touchLoc = touch->getLocation();

    auto nodeParent = node->getParent();
    if (nodeParent) {
        auto nodePosition = nodeParent->convertToNodeSpace(touchLoc);
        node->setPosition(nodePosition);
    }
}
void MLLManager::rotateAroundPoint(CCSprite* node, CCTouch* touch, const float& radius, CCPoint center) {
    auto loc = touch->getLocation();

    center = node->getParent()->convertToNodeSpace(center);
    auto currentPos = node->getPosition();
    auto direction = loc - center;

    direction = ccpNormalize(direction);

    auto newPos = center + direction * radius;

    node->setPosition(newPos);
}

std::map<std::string, float> MLLManager::CCPointToMap(const CCPoint& point) {
    std::map<std::string, float> value;
    value["x"] = point.x;
    value["y"] = point.y;
    return value;
}

MLLManager* MLLManager::get() {
    MLLManager* layer = new MLLManager();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}