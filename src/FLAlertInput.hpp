// oh well
#pragma once
#include <Geode/Geode.hpp>
#include <Geode/ui/MDPopup.hpp> // Include MDPopup header

using namespace geode::prelude;
// inheriting MDPopup was better
// due to FLAlertLayer being hard to do!
class FLAlertInput : public MDPopup {
private:
    bool setup(std::string const& title, std::string const& content, char const* btn1, char const* btn2, geode::utils::MiniFunction<void (bool)> onClick) override;
public:
    static FLAlertInput* create(std::string const& title, std::string const& content, char const* btn1, char const* btn2, geode::utils::MiniFunction<void (bool)> onClick);
};