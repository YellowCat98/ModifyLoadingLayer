// oh well
#pragma once
#include <Geode/Geode.hpp>
#include "../MLLManager.hpp"
#include "DragNode.hpp"

using namespace geode::prelude;

class InputPopup : public geode::Popup<std::string const&> {
protected:
    bool setup(std::string const& value) override;
    bool init(float width, float height, std::string const& asdasd, DragNode* node);
    void confirm(CCObject* sender);
    //void keyBackClicked() override;
    InputNode* a;
    DragNode* asdasdNode;
    
    CCMenuItemSpriteExtra* conf;
public:
    static InputPopup* create(std::string const& text, DragNode* node);

};