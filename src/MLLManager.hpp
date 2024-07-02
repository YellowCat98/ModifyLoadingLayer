// handles a lot of stuff!
#pragma once
#include <Geode/Geode.hpp>
#include "DragNode.hpp"

using namespace geode::prelude;

#define REMOVE_EASE(menuItem) do { \
    menuItem->m_animationEnabled = false; \
    menuItem->m_colorEnabled = true; \
} while(0)

class MLLManager : public CCNode {
protected:
    bool init();
public:
    void drag(DragNode* node, CCTouch* touch);
    std::map<std::string, float> CCPointToMap(const CCPoint& point);
    static MLLManager* get();
};