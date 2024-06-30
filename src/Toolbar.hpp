#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class Toolbar : public CCLayerColor {
protected:

    bool init();
    void moving(CCObject* sender);
    
public:
    static Toolbar* create();
};