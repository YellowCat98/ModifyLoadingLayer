// oh well
#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class InputPopup : public geode::Popup<std::string const&> {
protected:
    bool setup(std::string const& value) override;
    void confirm(CCObject* sender);
    InputNode* a;
    std::string val;
    CCMenuItemSpriteExtra* conf;
public:
    static InputPopup* create(std::string const& text);
};