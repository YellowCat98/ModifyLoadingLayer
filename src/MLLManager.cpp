#include "MLLManager.hpp"
#include "Editor/DragNode.hpp"

bool MLLManager::init() {
	if (!CCNode::init()) return false;
	temp = Mod::get()->getConfigDir() / "temp";
	if (!std::filesystem::exists(temp)) {
		std::filesystem::create_directory(temp);
	}
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

bool MLLManager::isCustom(const std::string& id) {
	std::string suffix = "-custom";
	if (id.size() >= suffix.size() &&
		id.compare(id.size() - suffix.size(), suffix.size(), suffix) == 0) {
			return true;
		}
	return false;
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