#include "DragNode.hpp" // already includes geode and geode ns
#include "MLLManager.hpp"

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

	selectedDisplay = CCLayerColor::create();
	selectedDisplay->setColor({0, 0, 0});
	selectedDisplay->setOpacity(150.0f);
	selectedDisplay->setContentSize(this->getContentSize());
	selectedDisplay->setVisible(false);
	selectedDisplay->setZOrder(-1.0f);
	this->addChild(selectedDisplay);
	return true;
}

void DragNode::selectNode(const std::string& nodeID) {
	auto scene = CCDirector::sharedDirector()->getRunningScene();
	if (mllm->currentSelectedNode == nodeID) {
		return;
	}

	DragNode* previousNode = static_cast<DragNode*>(this->getParent()->getChildByID(mllm->currentSelectedNode));
	if (previousNode) {
		previousNode->selectedDisplay->setVisible(false);
	}

	auto newNode = static_cast<DragNode*>(this->getParent()->getChildByID(nodeID));
	if (newNode) {
		newNode->selectedDisplay->setVisible(true);
	}

	mllm->currentSelectedNode = nodeID;
}

bool DragNode::ccTouchBegan(CCTouch* touch, CCEvent*) {
	auto const point = this->getParent()->convertToNodeSpace(touch->getLocation());

	auto const rect = this->boundingBox();
	if (rect.containsPoint(point)) {
		this->selectNode(this->getID());
		return true;
	}
	return false;
}

void DragNode::ccTouchMoved(CCTouch* touch, CCEvent*) {
	if (mllm->canMoveNode) {
		mllm->drag(this, touch);
	}
	
}

void DragNode::ccTouchEnded(CCTouch* touch, CCEvent*) {
	
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