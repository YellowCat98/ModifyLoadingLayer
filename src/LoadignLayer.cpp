#include <Geode/geode.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(LoadingLayer) {
    bool init(bool p0) {
        if (!LoadingLayer::init(p0))
            return false;

        auto saveDir = Mod::get()->getSaveDir();

        auto BGPath = saveDir.string() + "/BG.png";
        auto BGSPR = CCSprite::create(BGPath.c_str());
        auto bgtexture = static_cast<CCSprite*>(this->getChildByID("bg-texture"));
        if (BGSPR) {
            bgtexture->setTexture(BGSPR->getTexture());
            bgtexture->setColor(ccc3(255, 255, 255));
        }

        auto RLPath = saveDir.string() + "/RobTopLogo.png";
        auto RLSPR = CCSprite::create(RLPath.c_str());
        auto robtoplogo = static_cast<CCSprite*>(this->getChildByID("robtop-logo"));
        if (RLSPR) {
            auto robtoplogoscaleY = robtoplogo->getScaleY();
            RLSPR->setScaleY(robtoplogoscaleY);
            auto robtoplogoscaleX = robtoplogo->getScaleX();
            RLSPR->setScaleY(robtoplogoscaleX);
            robtoplogo->setTexture(RLSPR->getTexture());

        }

        auto CocosPath = saveDir.string() + "/Cocos.png";
        auto CocosSPR = CCSprite::create(CocosPath.c_str());
        auto cocoslogo = static_cast<CCSprite*>(this->getChildByID("cocos2d-logo"));
        if (CocosSPR) {
            cocoslogo->setTexture(CocosSPR->getTexture());
        }

        auto FModPath = saveDir.string() + "/FMod.png";
        auto FModSPR = CCSprite::create(FModPath.c_str());
        auto fmodlogo = static_cast<CCSprite*>(this->getChildByID("fmod-logo"));
        if (FModSPR) {
            fmodlogo->setTexture(FModSPR->getTexture());
        }

        auto GJLogoPath = saveDir.string() + "/GJLogo.png";
        auto GJLogoSPR = CCSprite::create(GJLogoPath.c_str());
        auto gjlogo = static_cast<CCSprite*>(this->getChildByID("gd-logo"));
        if (GJLogoSPR) {
            gjlogo->setTexture(GJLogoSPR->getTexture());
        }


        return true;
    }
};
