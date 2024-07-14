#include "Opacity.hpp"

bool Opacity::init(std::string theNodeID) {
    if (!CCLayer::init()) return false;
    nodeID = theNodeID;
    auto node = static_cast<CCSprite*>(CCDirector::sharedDirector()->getRunningScene()->getChildByIDRecursive(nodeID));
    slider = Slider::create(this, menu_selector(Opacity::onSlider));
    sliderL = CCLabelBMFont::create("", "bigFont.fnt");
    slider->setValue(node->getOpacity() / 255);
    this->addChild(slider);

    sliderL->setScale(0.7f);
    sliderL->setPositionY(slider->getPositionX() + 30);
    
    sliderL->setString(fmt::format("{}", node->getOpacity()).c_str());
    this->addChild(sliderL);

    this->setPosition(CCDirector::sharedDirector()->getRunningScene()->getChildByIDRecursive(nodeID)->getPosition());
    this->setPositionY(CCDirector::sharedDirector()->getRunningScene()->getChildByIDRecursive(nodeID)->getPositionY() + 50);
    return true;
}

float Opacity::calculate(float value) {
    return value * 255;
}

void Opacity::onSlider(CCObject* sender) {
    auto node = static_cast<CCSprite*>(CCDirector::sharedDirector()->getRunningScene()->getChildByIDRecursive(nodeID)->getChildByID("the-sprite"));
    sliderL->setString(std::to_string(node->getOpacity()).c_str());
    node->setOpacity(calculate(slider->getThumb()->getValue()));
}

Opacity* Opacity::create(std::string theNodeID) {
    auto ret = new Opacity();
    if (ret && ret->init(theNodeID)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}