#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class Opacity : public CCLayer {
private:
    std::string nodeID;
    Slider* sliderA;
    CCLabelBMFont* sliderAL;
    Slider* sliderR;
    CCLabelBMFont* sliderRL;
    bool init(std::string theNodeID);
    void onSliderA(CCObject* sender);
    void onSliderR(CCObject* sender);
    float calculate(float value);
public:
    static Opacity* create(std::string theNodeID);
};