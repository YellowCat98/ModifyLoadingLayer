#include "InputPopup.hpp"

bool InputPopup::init(float width, float height, std::string const& asdasd, DragNode* node) {
	if (!Popup::init(width, height, asdasd)) return false;
	asdasdNode = node;
	return true;
}

bool InputPopup::setup(std::string const& value) {
	auto winSize = CCDirector::sharedDirector()->getWinSize();

	this->setTitle("Type a Node ID");

	a = InputNode::create(200.0f, value.c_str(), "chatFont.fnt", "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~", 0);
	m_buttonMenu->addChild(a);
	conf = CCMenuItemSpriteExtra::create(ButtonSprite::create("OK"), this, menu_selector(InputPopup::confirm));
	conf->setScale(0.8f);
	conf->setPositionY(-30.0f);
	m_buttonMenu->addChild(conf);

	return true;
}

void InputPopup::confirm(CCObject* sender) {
	asdasdNode->setID(a->getString() += "-custom");
	auto scene = CCDirector::sharedDirector()->getRunningScene();
	log::info("{}", asdasdNode->getID());
}


InputPopup* InputPopup::create(std::string const& text, DragNode* node) {
	auto ret = new InputPopup();
	if (ret->init(240.0f, 100.0f, text, node)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}