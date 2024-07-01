// handles a lot of stuff!
#pragma once
#include <Geode/Geode.hpp>
#include "DragNode.hpp"

using namespace geode::prelude;

#define CCMENUISE_REMOVE_EASE(menuItem) do { \
    menuItem->m_animationEnabled = false; \
    menuItem->m_colorEnabled = true; \
    menuItem->m_baseScale = 1.0f; \
    menuItem->m_scaleMultiplier = 1.0f; \
} while(0)

class MMLManager : public CCNode {
protected:
    bool init();
public:
    void drag(DragNode* node, CCTouch* touch);
    static MMLManager* get();
};