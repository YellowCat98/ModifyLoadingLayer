#include "MLLManager.hpp"
#include "DragNode.hpp"

bool MLLManager::init() {
	if (!CCNode::init()) return false;
	return true;
}

void MLLManager::drag(CCNode* node, CCTouch* touch) {
	auto touchLoc = touch->getLocation();

	auto nodeParent = node->getParent();
	if (nodeParent) {
		auto nodePosition = nodeParent->convertToNodeSpace(touchLoc);
		node->setPosition(nodePosition);
	}
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