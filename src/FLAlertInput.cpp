#include "FLAlertInput.hpp"

bool FLAlertInput::setup(std::string const& title, std::string const& content, char const* btn1, char const* btn2, geode::utils::MiniFunction<void (bool)> onClick) {
    if (!MDPopup::setup(title, content, btn1, btn2, onClick)) return false;
    log::info("hi");
    return true;
}

FLAlertInput* FLAlertInput::create(std::string const& title, std::string const& content, char const* btn1, char const* btn2, geode::utils::MiniFunction<void (bool)> onClick) {
    auto ret = new FLAlertInput();
    if (ret && ret->setup(title, content, btn1, btn2, onClick)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}