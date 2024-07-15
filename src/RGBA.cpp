#include "RGBA.hpp"

bool _rgba::init(std::string theNodeID) {
	if (!CCLayer::init()) return false;
	nodeID = theNodeID;
	auto node = static_cast<CCSprite*>(CCDirector::sharedDirector()->getRunningScene()->getChildByIDRecursive(nodeID));
	sliderA = Slider::create(this, menu_selector(_rgba::onSliderA));
	sliderAL = CCLabelBMFont::create("", "bigFont.fnt");
	sliderA->setValue(node->getOpacity() / 255);
	this->addChild(sliderA);

	sliderAL->setScale(0.7f);
	sliderAL->setPositionY(sliderA->getPositionY() + 17);
	
	sliderAL->setString(fmt::format("A: {}", node->getOpacity()).c_str());
	this->addChild(sliderAL);


	sliderR = Slider::create(this, menu_selector(_rgba::onSliderR));
	sliderRL = CCLabelBMFont::create("", "bigFont.fnt");
	sliderR->setValue(node->getColor().r / 255);
	sliderR->setPositionY(sliderA->getPositionY() + 30);
	this->addChild(sliderR);

	sliderRL->setScale(0.7f);
	sliderRL->setPositionY(sliderR->getPositionY() + 20);


	sliderRL->setString((fmt::format("R: {}", node->getColor().r)).c_str());
	this->addChild(sliderRL);

	sliderG = Slider::create(this, menu_selector(_rgba::onSliderG));
	sliderGL = CCLabelBMFont::create("", "bigFont.fnt");
	sliderG->setValue(node->getColor().g / 255);
	sliderG->setPositionY(sliderR->getPositionY() + 30);
	this->addChild(sliderG);

	sliderGL->setScale(0.7f);
	sliderGL->setPositionY(sliderG->getPositionY() + 20);

	this->setPosition(CCDirector::sharedDirector()->getRunningScene()->getChildByIDRecursive(nodeID)->getPosition());
	this->setPositionY(CCDirector::sharedDirector()->getRunningScene()->getChildByIDRecursive(nodeID)->getPositionY() + 50);


	return true;
}

float _rgba::calculate(float value) {
	return value * 255;
}

void _rgba::onSliderR(CCObject* sender) {
	auto node = static_cast<CCSprite*>(CCDirector::sharedDirector()->getRunningScene()->getChildByIDRecursive(nodeID)->getChildByID("the-sprite"));
	sliderRL->setString(fmt::format("R: {}", calculate(sliderR->getThumb()->getValue())).c_str());
	node->setColor(ccc3(calculate(sliderR->getThumb()->getValue()), node->getColor().g, node->getColor().b));
}

void _rgba::onSliderG(CCObject* sender) {
	auto node = static_cast<CCSprite*>(CCDirector::sharedDirector()->getRunningScene()->getChildByIDRecursive(nodeID)->getChildByID("the-sprite"));
	sliderGL->setString(fmt::format("G: {}", calculate(sliderG->getThumb()->getValue())).c_str());
	node->setColor(ccc3(node->getColor().r, calculate(sliderG->getThumb()->getValue()), node->getColor().b));
}

void _rgba::onSliderA(CCObject* sender) {
	auto node = static_cast<CCSprite*>(CCDirector::sharedDirector()->getRunningScene()->getChildByIDRecursive(nodeID)->getChildByID("the-sprite"));
	sliderAL->setString(fmt::format("A: {}", calculate(sliderA->getThumb()->getValue())).c_str());
	node->setOpacity(calculate(sliderA->getThumb()->getValue()));
}

_rgba* _rgba::create(std::string theNodeID) {
	auto ret = new _rgba();
	if (ret && ret->init(theNodeID)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}