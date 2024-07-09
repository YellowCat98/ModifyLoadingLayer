#include "Rotation.hpp"
#include "MLLManager.hpp"

bool Rotation::init(std::string theNodeID) {
	if (!CCLayer::init()) return false;
	CCSprite* sprite;
	this->addChild(sprite = CCSprite::createWithSpriteFrameName("GJ_rotationControlBtn01_001.png"));

	this->setTouchMode(kCCTouchesOneByOne);
	this->setTouchEnabled(true);
	this->ignoreAnchorPointForPosition(false);
	this->addChild(sprite);
	auto sprSize = sprite->getContentSize();
	sprite->setID("the-sprite");
	this->setContentSize(sprSize);
	auto size = this->getContentSize();
	auto center = CCPoint(size.width / 2, size.height / 2);
	sprite->setPosition(center);

	nodeID = theNodeID;

	label = CCLabelBMFont::create("", "bigFont.fnt");
	label->setPosition({sprite->getPositionX(), (sprite->getPositionY() + 30)});
	this->addChild(label);
	return true;
}

bool Rotation::ccTouchBegan(CCTouch* touch, CCEvent* event) {
	auto const point = this->getParent()->convertToNodeSpace(touch->getLocation());

	auto const rect = this->boundingBox();
	if (rect.containsPoint(point)) {
		return true;
	}
	return false;
}

void Rotation::ccTouchMoved(CCTouch* touch, CCEvent* event) {
	MLLManager::get()->drag(this, touch);
	this->rotate(nodeID, touch);
}

void Rotation::rotate(const std::string& nodeID, CCTouch* touch) {
	auto loc = touch->getLocation();
	auto scene = CCDirector::sharedDirector()->getRunningScene();
	auto node = scene->getChildByIDRecursive(nodeID);
	float dx = loc.x - node->getPositionX();
	float dy = loc.y - node->getPositionY();
	float angle = atan2(dx, dy);
	angle = CC_RADIANS_TO_DEGREES(angle) - 90;
	node->setRotation(angle);
	label->setString(std::to_string(angle).c_str());
}

Rotation* Rotation::get(std::string theNodeID) {
	auto ret = new Rotation();

	if (ret->init(theNodeID)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}