#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class Opacity : public CCLayer {
private:
    std::string nodeID;
    Slider* slider;
    CCLabelBMFont* sliderL;
    bool init(std::string theNodeID);
    void onSlider(CCObject* sender);
    float calculate(float value);
public:
    static Opacity* create(std::string theNodeID);
};