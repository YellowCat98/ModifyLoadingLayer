#include <Geode/Geode.hpp>
#include <Geode/Bindings.hpp>
#include "CustomLoadingLayer.hpp"
#include "LoadingLayerEditor.hpp"
#include <Windows.h> // who cares about cross platform anyway (jk ill look into mobile support soon, we dont talk about mac.)
#include <cocos2d.h>
#include <filesystem>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>

using namespace geode::prelude;

bool CustomLoadingLayer::init() {
    if (!CCLayer::init()) return false;
    this->setID("CustomLoadingLayer");

    // <reverseengineeringloadinglayer>

    auto saveDir = Mod::get()->getSaveDir();

    this->setScale(1.0f);

    auto BGPath = saveDir.string() + "/BG.png";
    auto BGSPR = CCSprite::create(BGPath.c_str());

    auto RLPath = saveDir.string() + "/RobTopLogo.png";
    auto RLSPR = CCSprite::create(RLPath.c_str());

    auto CocosPath = saveDir.string() + "/Cocos.png";
    auto CocosSPR = CCSprite::create(CocosPath.c_str());

    auto FModPath = saveDir.string() + "/FMod.png";
    auto FModSPR = CCSprite::create(FModPath.c_str());

    auto GJLogoPath = saveDir.string() + "/GJLogo.png";
    auto GJLogoSPR = CCSprite::create(GJLogoPath.c_str());

    auto gdlogo = CCSprite::createWithSpriteFrameName("GJ_logo_001.png");
    auto robtoplogo = CCSprite::createWithSpriteFrameName("RobTopLogoBig_001.png");
    auto fmodlogo = CCSprite::createWithSpriteFrameName("fmodLogo.png");
    auto cocos2dlogo = CCSprite::createWithSpriteFrameName("cocos2DxLogo.png");
    auto bgtexture = CCSprite::create("game_bg_01_001.png");

    // gd logo

    if (GJLogoSPR) {
        GJLogoSPR->setPosition(ccp(283.5, 160.0));
        GJLogoSPR->setID("gd-logo");
        GJLogoSPR->setContentSize(CCSize(429.0, 52.0));
        this->addChild(GJLogoSPR);
    } else {
    gdlogo->setPosition(ccp(283.5, 160.0));
    gdlogo->setID("gd-logo");
    gdlogo->setContentSize(CCSize(429.0, 52.0));
    this->addChild(gdlogo);
    }

    // robtop logo

    if (RLSPR) {
        RLSPR->setPosition(ccp(283.4, 240.0));
        RLSPR->setID("robtop-logo");
        RLSPR->setContentSize(CCSize(148.0, 55.5));
        RLSPR->setAnchorPoint(ccp(0.5, 0.5));
        this->addChild(RLSPR);
    } else {
        robtoplogo->setPosition(ccp(283.4, 240.0));
        robtoplogo->setID("robtop-logo");
        robtoplogo->setContentSize(CCSize(148.0, 55.5));
        robtoplogo->setAnchorPoint(ccp(0.5, 0.5));
        this->addChild(robtoplogo);
    }

    // fmod logo

    if (FModSPR) { 
    FModSPR->setPosition(ccp(533.0, 33.0));
    FModSPR->setID("fmod-logo");
    FModSPR->setScale(0.6f);
    FModSPR->setContentSize(CCSize(90, 23.75));
    FModSPR->setAnchorPoint(ccp(0.5, 0.5));
    FModSPR->setColor(ccc3(0, 0, 0));
    this->addChild(FModSPR);
    } else {
        fmodlogo->setPosition(ccp(533.0, 33.0));
        fmodlogo->setID("fmod-logo");
        fmodlogo->setScale(0.6f);
        fmodlogo->setContentSize(CCSize(90, 23.75));
        fmodlogo->setAnchorPoint(ccp(0.5, 0.5));
        fmodlogo->setColor(ccc3(0, 0, 0));
        this->addChild(fmodlogo);
    }

    // cocos2d logo

    if (CocosSPR) {
        CocosSPR->setPosition(ccp(533.0, 13.0));
        CocosSPR->setID("cocos2d-logo");
        CocosSPR->setScale(0.6f);
        CocosSPR->setContentSize(CCSize(90, 24));
        CocosSPR->setAnchorPoint(ccp(0.5, 0.5));
        this->addChild(CocosSPR);
    } else {
        cocos2dlogo->setPosition(ccp(533.0, 13.0));
        cocos2dlogo->setID("cocos2d-logo");
        cocos2dlogo->setScale(0.6f);
        cocos2dlogo->setContentSize(CCSize(90, 24));
        cocos2dlogo->setAnchorPoint(ccp(0.5, 0.5));
        this->addChild(cocos2dlogo);
    }

    // bg texture

    if (BGSPR) {
    BGSPR->setID("bg-texture");
    BGSPR->setColor(ccc3(255, 255, 255));
    BGSPR->setPosition(ccp(283.5, 160.0));
    BGSPR->setContentSize(ccp(512, 512));
    BGSPR->setScale(1.181);
    BGSPR->setAnchorPoint(ccp(0.5, 0.5));
    BGSPR->setZOrder(-1);
    this->addChild(BGSPR);
    } else {
    bgtexture->setID("bg-texture");
    bgtexture->setColor(ccc3(0, 102, 255));
    bgtexture->setPosition(ccp(283.5, 160.0));
    bgtexture->setContentSize(ccp(512, 512));
    bgtexture->setScale(1.181);
    bgtexture->setAnchorPoint(ccp(0.5, 0.5));
    bgtexture->setZOrder(-1);
    this->addChild(bgtexture);
    }


    // </reverseengineeringloadinglayer>

    return true;
}

CustomLoadingLayer* CustomLoadingLayer::create() {
    CustomLoadingLayer* layer = new CustomLoadingLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

// this is the editor itself
// please dont kill me

bool LoadingLayerEditor::init() {
    if (!CCLayer::init()) return false;
    this->setID("LoadingLayerEditor");

    auto LayerColor = CCLayerColor::create(ccc4(0, 0, 0, 145));
    LayerColor->setPosition(ccp(0, -225));

    auto leftSideMenu = CCMenu::create();
    leftSideMenu->setID("left-side-menu");
    leftSideMenu->setContentSize(ccp(162, 320));
    leftSideMenu->setPosition(ccp(0, 0));
    this->addChild(leftSideMenu);

    auto rightSideMenu = CCMenu::create();
    rightSideMenu->setID("right-side-menu");
    rightSideMenu->setPosition(ccp(405, 0));
    rightSideMenu->setContentSize(ccp(165, 320));
    this->addChild(rightSideMenu);

    auto bottomMenu = CCMenu::create();
    bottomMenu->setID("bottom-menu");
    bottomMenu->setPosition(ccp(0, 0));
    bottomMenu->setContentSize(ccp(567, 95));
    this->addChild(bottomMenu);

    auto exitBtn = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png"), this, menu_selector(LoadingLayerEditor::onExit));
    exitBtn->setPosition(ccp(20, 295));
    exitBtn->setID("exit-button");

    leftSideMenu->addChild(exitBtn);
    bottomMenu->addChild(LayerColor);

    // oh no (user interface, the point of human-computer interaction and communication on a device, webpage, or app. This can include display screens, keyboards, a mouse, and the appearance of a desktop. User interfaces enable users to effectively control the computer or device they are interacting with.)

    auto setBG = CCMenuItemSpriteExtra::create(ButtonSprite::create("Set BG"), this, menu_selector(LoadingLayerEditor::onBG));
    setBG->setPosition(70, 70);
    setBG->setID("set-bg");
    bottomMenu->addChild(setBG);

    auto setGJLogo = CCMenuItemSpriteExtra::create(ButtonSprite::create("Set GJ Logo"), this, menu_selector(LoadingLayerEditor::onGJLogoSpr));
    setGJLogo->setPosition(ccp(225, 70));
    setGJLogo->setID("set-gj-logo");
    bottomMenu->addChild(setGJLogo);

    auto setRobert = CCMenuItemSpriteExtra::create(ButtonSprite::create("Set RobTop Logo"), this, menu_selector(LoadingLayerEditor::onRobert));
    setRobert->setPosition(ccp(435, 70));
    setRobert->setID("set-robert-logo");
    bottomMenu->addChild(setRobert);

    auto setCocos = CCMenuItemSpriteExtra::create(ButtonSprite::create("Set Cocos Logo"), this, menu_selector(LoadingLayerEditor::onCocos));
    setCocos->setPosition(ccp(195, 30));
    setCocos->setID("set-cocos-logo");
    bottomMenu->addChild(setCocos);

    auto setFMod = CCMenuItemSpriteExtra::create(ButtonSprite::create("Set FMod Logo"), this, menu_selector(LoadingLayerEditor::onFMod));
    setFMod->setPosition(ccp(415, 30));
    setFMod->setID("set-fmod-logo");
    bottomMenu->addChild(setFMod);

    auto Erase = CCMenuItemSpriteExtra::create(ButtonSprite::create("Erase"), this, menu_selector(LoadingLayerEditor::onErase));
    Erase->setID("erase-button");
    leftSideMenu->addChild(Erase);
    Erase->setPosition(ccp(75, 256));

    auto Reload = CCMenuItemSpriteExtra::create(ButtonSprite::create("Reload"), this, menu_selector(LoadingLayerEditor::onReload));
    Reload->setID("reload-button");
    leftSideMenu->addChild(Reload);
    Reload->setPosition(ccp(75, 210));

    auto Restart = CCMenuItemSpriteExtra::create(ButtonSprite::create("Restart"), this, menu_selector(LoadingLayerEditor::onRestart));
    Restart->setID("restart-button");
    leftSideMenu->addChild(Restart);
    Restart->setPosition(ccp(75, 165));


    return true;
}

void LoadingLayerEditor::onExit(CCObject* sender) {

    auto scene = CCScene::create();

    bool p0 = false;

    auto menulayer = MenuLayer::scene(p0);

    scene->addChild(menulayer);

    CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, scene));

}

void LoadingLayerEditor::onErase(CCObject* sender) {
    geode::createQuickPopup(
        "WARNING!",
        "This will <cr>erase</c> ALL of your <cy>Loading Layer modifications</c>, are you sure you wanna proceed?",
        "nuh uh", "yes",
        [](auto, bool btn2) {
            if (btn2) {
                // Delete files from save directory
                std::string saveDir = Mod::get()->getSaveDir().string();
                std::remove((saveDir + "/GJLogo.png").c_str());
                std::remove((saveDir + "/BG.png").c_str());
                std::remove((saveDir + "/Cocos.png").c_str());
                std::remove((saveDir + "/FMod.png").c_str());
                std::remove((saveDir + "/RobTopLogo.png").c_str());
                
                
            }
        }
    );
}

void LoadingLayerEditor::onRestart(CCObject* sender) {
    auto disableornot = Mod::get()->getSettingValue<bool>("disable-restart-confirmation");
    if (!disableornot) {
    geode::createQuickPopup(
        "Are you sure?",
        "are you sure you want to restart the game? (you can disable this confirmation in the mod's <cy>settings.</c>)",
        "no", "yes",
        [](auto, bool btn2) {
            if (btn2) {
                utils::game::restart();
                }
            }
        );
    } else {
        utils::game::restart();
    }
}

void LoadingLayerEditor::onReload(CCObject* sender) {
    auto scene = cocos2d::CCScene::create();

	
    auto loadinglayer = CustomLoadingLayer::create();
	auto loadinglayereditor = LoadingLayerEditor::create();
    


    scene->addChild(loadinglayer);
	scene->addChild(loadinglayereditor);


    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f, scene));
}

LoadingLayerEditor* LoadingLayerEditor::create() {
    LoadingLayerEditor* layer = new LoadingLayerEditor();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}