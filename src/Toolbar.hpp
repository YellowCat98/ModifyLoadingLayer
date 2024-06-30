#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class Toolbar : public CCLayerColor {
protected:
    CCMenu* themenu;

    bool init();
    
public:
    static Toolbar* create();
};