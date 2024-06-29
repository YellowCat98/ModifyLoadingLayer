// handles a lot of stuff!
#pragma once
#include <Geode/Geode.hpp>
#include "DragNode.hpp"

using namespace geode::prelude;

class MMLManager : public CCNode {
protected:
    bool init();
public:
    void drag(DragNode* node);
    static MMLManager* get();
};