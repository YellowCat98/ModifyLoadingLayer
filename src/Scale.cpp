#include "Scale.hpp"

bool Scale::init(std::string theNodeID) {
    if (!CCLayer::init()) return false;
    sliderX = Slider::create(this, menu_selector(Scale::onSliderX));
    sliderXL = CCLabelBMFont::create("", "bigFont.fnt");
    sliderY = Slider::create(this, menu_selector(Scale::onSliderY));
    sliderYL = CCLabelBMFont::create("", "bigFont.fnt");
    sliderX->setValue(0.5f);
    sliderY->setValue(0.5f);
    sliderY->setPositionY(sliderX->getPositionY() - 50);
    this->addChild(sliderX);
    this->addChild(sliderY);
    sliderYL->setScale(0.7f);
    sliderYL->setPosition((sliderX->getPosition() + sliderY->getPosition()) / 2);
    sliderYL->setString(fmt::format("Y: {}", CCDirector::sharedDirector()->getRunningScene()->getChildByIDRecursive(nodeID)->getScaleY()).c_str());
    this->addChild(sliderYL);
    sliderXL->setScale(0.7f);
    sliderXL->setPositionY(sliderX->getPositionX() + 30);
    sliderXL->setString(fmt::format("X: {}", CCDirector::sharedDirector()->getRunningScene()->getChildByIDRecursive(nodeID)->getScaleX()).c_str());
    this->addChild(sliderXL);
    nodeID = theNodeID;
    this->setPosition(CCDirector::sharedDirector()->getRunningScene()->getChildByIDRecursive(nodeID)->getPosition());
    this->setPositionY(CCDirector::sharedDirector()->getRunningScene()->getChildByIDRecursive(nodeID)->getPositionY() + 50);
    return true;
}

float Scale::calculate(float hi) {
    return 2.0f * hi;
}

void Scale::onSliderX(CCObject* sender) {
    auto scene = CCDirector::sharedDirector()->getRunningScene();
    auto node = scene->getChildByIDRecursive(nodeID);
    node->setScaleX(this->calculate(sliderX->getThumb()->getValue()));
    sliderXL->setString(fmt::format("X: {}", node->getScaleX()).c_str());
}

void Scale::onSliderY(CCObject* sender) {
    auto scene = CCDirector::sharedDirector()->getRunningScene();
    auto node = scene->getChildByIDRecursive(nodeID);
    node->setScaleY(this->calculate(sliderY->getThumb()->getValue()));
    sliderYL->setString(fmt::format("Y: {}", node->getScaleY()).c_str());
}

Scale* Scale::create(std::string theNodeID) {
    auto ret = new Scale();
    if (ret && ret->init(theNodeID)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}