#include <Geode/Geode.hpp>
#include <Geode/Bindings.hpp>
#include "CustomLoadingLayer.hpp"
#include <filesystem>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include "DragNode.hpp"
#include "LoadingEditorUI.hpp"
using namespace geode::prelude;

void touch() {
    log::info("TOUCHED!");
}

void untouch() {
    log::info("UNTOUCHED!");
}

bool CustomLoadingLayer::init() {
    if (!CCLayer::init()) return false;
    this->setID("CustomLoadingLayer");

    // <reverseengineeringloadinglayer>

    auto saveDir = Mod::get()->getSaveDir();

    auto BGPath = saveDir.string() + "/BG.png";
    auto BGSPR = CCSprite::create(BGPath.c_str());

    auto RLPath = saveDir.string() + "/RobTopLogo.png";
    auto RLSPR = DragNode::create(std::bind(&touch), std::bind(&untouch), CCSprite::create(RLPath.c_str()));

    auto CocosPath = saveDir.string() + "/Cocos.png";
    auto CocosSPR = DragNode::create(std::bind(&touch), std::bind(&untouch), CCSprite::create(CocosPath.c_str()));

    auto FModPath = saveDir.string() + "/FMod.png";
    auto FModSPR = DragNode::create(std::bind(&touch), std::bind(&untouch), CCSprite::create(FModPath.c_str()));

    auto GJLogoPath = saveDir.string() + "/GJLogo.png";
    auto GJLogoSPR = DragNode::create(std::bind(&touch), std::bind(&untouch), CCSprite::create(GJLogoPath.c_str()));

    auto gdlogo = DragNode::create(std::bind(&touch), std::bind(&untouch), CCSprite::createWithSpriteFrameName("GJ_logo_001.png"));
    auto robtoplogo = DragNode::create(std::bind(&touch), std::bind(&untouch), CCSprite::createWithSpriteFrameName("RobTopLogoBig_001.png"));
    auto fmodlogo = DragNode::create(std::bind(&touch), std::bind(&untouch), CCSprite::createWithSpriteFrameName("fmodLogo.png"));
    auto cocos2dlogo = DragNode::create(std::bind(&touch), std::bind(&untouch), CCSprite::createWithSpriteFrameName("cocos2DxLogo.png"));
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

    auto toolbar = LoadingEditorUI::create();
    this->addChild(toolbar);


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

