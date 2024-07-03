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
#include "MLLManager.hpp"
using namespace geode::prelude;

void touch() {
    log::info("node touched");
}

void untouch() {
    log::info("not touching node");
}

bool CustomLoadingLayer::init() {
    if (!CCLayer::init()) return false;
    this->setID("CustomLoadingLayer");

    // <reverseengineeringloadinglayer>

    auto saveDir = Mod::get()->getSaveDir();

    gdlogo = DragNode::create(std::bind(&touch), std::bind(&untouch), CCSprite::createWithSpriteFrameName("GJ_logo_001.png"));
    robtoplogo = DragNode::create(std::bind(&touch), std::bind(&untouch), CCSprite::createWithSpriteFrameName("RobTopLogoBig_001.png"));
    fmodlogo = DragNode::create(std::bind(&touch), std::bind(&untouch), CCSprite::createWithSpriteFrameName("fmodLogo.png"));
    cocos2dlogo = DragNode::create(std::bind(&touch), std::bind(&untouch), CCSprite::createWithSpriteFrameName("cocos2DxLogo.png"));
    bgtexture = CCSprite::create("game_bg_01_001.png");

    // gd logo

    gdlogo->setPosition(ccp(283.5, 160.0));
    gdlogo->setID("gd-logo");
    gdlogo->setContentSize(CCSize(429.0, 52.0));
    this->addChild(gdlogo);

    // robtop logo

    robtoplogo->setPosition(ccp(283.4, 240.0));
    robtoplogo->setID("robtop-logo");
    robtoplogo->setContentSize(CCSize(148.0, 55.5));
    robtoplogo->setAnchorPoint(ccp(0.5, 0.5));
    this->addChild(robtoplogo);

    // fmod logo

    fmodlogo->setPosition(ccp(533.0, 33.0));
    fmodlogo->setID("fmod-logo");
    fmodlogo->setScale(0.6f);
    fmodlogo->setContentSize(CCSize(90, 23.75));
    fmodlogo->setAnchorPoint(ccp(0.5, 0.5));
    fmodlogo->setColor(ccc3(0, 0, 0));
    this->addChild(fmodlogo);

    // cocos2d logo

    cocos2dlogo->setPosition(ccp(533.0, 13.0));
    cocos2dlogo->setID("cocos2d-logo");
    cocos2dlogo->setScale(0.6f);
    cocos2dlogo->setContentSize(CCSize(90, 24));
    cocos2dlogo->setAnchorPoint(ccp(0.5, 0.5));
    this->addChild(cocos2dlogo);

    // bg texture

    bgtexture->setID("bg-texture");
    bgtexture->setColor(ccc3(0, 102, 255));
    bgtexture->setPosition(ccp(283.5, 160.0));
    bgtexture->setContentSize(ccp(512, 512));
    bgtexture->setScale(1.181);
    bgtexture->setAnchorPoint(ccp(0.5, 0.5));
    bgtexture->setZOrder(-1);
    this->addChild(bgtexture);

    // </reverseengineeringloadinglayer>

    auto editorui = LoadingEditorUI::create();
    this->addChild(editorui);
    auto mmlm = MLLManager::get();
    DefaultPositions[gdlogo->getID()] = mmlm->CCPointToMap(CCPoint(283.5, 160.0));
    DefaultPositions[robtoplogo->getID()] = mmlm->CCPointToMap(CCPoint(283.4, 240.0));
    DefaultPositions[fmodlogo->getID()] = mmlm->CCPointToMap(CCPoint(533.0, 33.0));
    DefaultPositions[cocos2dlogo->getID()] = mmlm->CCPointToMap(CCPoint(533.0, 13.0));

    return true;
}

void CustomLoadingLayer::resetPosition() {
    auto gdlogopos = CCPoint(DefaultPositions["gd-logo"]["x"], DefaultPositions["gd-logo"]["y"]);
    auto robtoplogopos = CCPoint(DefaultPositions["robtop-logo"]["x"], DefaultPositions["robtop-logo"]["y"]);
    auto fmodlogopos = CCPoint(DefaultPositions["fmod-logo"]["x"], DefaultPositions["fmod-logo"]["y"]);
    auto cocos2dlogopos= CCPoint(DefaultPositions["cocos2d-logo"]["x"], DefaultPositions["cocos2d-logo"]["y"]);
    gdlogo->setPosition(gdlogopos);
    robtoplogo->setPosition(robtoplogopos);
    fmodlogo->setPosition(fmodlogopos);
    cocos2dlogo->setPosition(cocos2dlogopos);
}

void CustomLoadingLayer::getPositions() {
    auto mmlm = MLLManager::get();
    Positions[gdlogo->getID()] = mmlm->CCPointToMap(gdlogo->getPosition());
    Positions[robtoplogo->getID()] = mmlm->CCPointToMap(robtoplogo->getPosition());
    Positions[fmodlogo->getID()] = mmlm->CCPointToMap(fmodlogo->getPosition());
    Positions[cocos2dlogo->getID()] = mmlm->CCPointToMap(cocos2dlogo->getPosition());
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