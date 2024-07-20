#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class _rgba : public CCLayer {
private:
    std::string nodeID;
    Slider* sliderA;
    CCLabelBMFont* sliderAL;
    Slider* sliderR;
    CCLabelBMFont* sliderRL;
    Slider* sliderG;
    CCLabelBMFont* sliderGL;
    Slider* sliderB;
    CCLabelBMFont* sliderBL;
    bool init(std::string theNodeID);
    void onSliderA(CCObject* sender);
    void onSliderR(CCObject* sender);
    void onSliderG(CCObject* sender);
    void onSliderB(CCObject* sender);
    float calculate(float value);
public:
    static _rgba* create(std::string theNodeID);
};