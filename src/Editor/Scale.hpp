#pragma once
#include <Geode/Geode.hpp>
#include "DragNode.hpp"

using namespace geode::prelude;

class Scale : public CCLayer {
private:
    CCNode* node;
    std::string nodeID;
    Slider* sliderX;
    Slider* sliderY;
    CCLabelBMFont* sliderXL;
    CCLabelBMFont* sliderYL;
    bool init(std::string theNodeID);
    void onSliderX(CCObject* sender);
    void onSliderY(CCObject* sender);
    float calculate(float hi);
public:
    static Scale* create(std::string theNodeID);
};