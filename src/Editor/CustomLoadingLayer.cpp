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
#include "../MLLManager.hpp"

using namespace geode::prelude;



bool CustomLoadingLayer::init() {
	if (!CCLayer::init()) return false;
	this->setID("CustomLoadingLayer");
	this->setKeypadEnabled(true);

	// <reverseengineeringloadinglayer>

	auto saveDir = Mod::get()->getSaveDir();

	mllm = MLLManager::get();
	mllm->setID("manager");

	auto editorui = LoadingEditorUI::create();
	editorui->mllm = mllm;
	this->addChild(editorui);


	gdlogo = DragNode::create(CCSprite::createWithSpriteFrameName("GJ_logo_001.png"));
	robtoplogo = DragNode::create(CCSprite::createWithSpriteFrameName("RobTopLogoBig_001.png"));
	fmodlogo = DragNode::create(CCSprite::createWithSpriteFrameName("fmodLogo.png"));
	cocos2dlogo = DragNode::create(CCSprite::createWithSpriteFrameName("cocos2DxLogo.png"));
	bgtexture = CCSprite::create("game_bg_01_001.png");
	progressSlider = DragNode::create(CCSprite::create("slidergroove.png"));

	gdlogo->mllm = mllm;
	robtoplogo->mllm = mllm;
	fmodlogo->mllm = mllm;
	cocos2dlogo->mllm = mllm;
	progressSlider->mllm = mllm;

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

	// progress slider

	progressSlider->setID("progress-slider");
	progressSlider->setPosition(ccp(283.5f, 100.0f));
	progressSlider->setContentSize(CCSize(210.0f, 16.0f));
	progressSlider->setAnchorPoint(ccp(0.5f, 0.5f));
	this->addChild(progressSlider);

	// </reverseengineeringloadinglayer>

	
	this->addChild(mllm); // might need for later
	DefaultPositions[gdlogo->getID()] = mllm->CCPointToMap(CCPoint(283.5, 160.0));
	DefaultPositions[robtoplogo->getID()] = mllm->CCPointToMap(CCPoint(283.4, 240.0));
	DefaultPositions[fmodlogo->getID()] = mllm->CCPointToMap(CCPoint(533.0, 33.0));
	DefaultPositions[cocos2dlogo->getID()] = mllm->CCPointToMap(CCPoint(533.0, 13.0));

	DefaultBrainrot[gdlogo->getID()] = 0.0f;
	DefaultBrainrot[robtoplogo->getID()] = 0.0f;
	DefaultBrainrot[fmodlogo->getID()] = 0.0f;
	DefaultBrainrot[cocos2dlogo->getID()] = 0.0f;

	this->getPositions();

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

void CustomLoadingLayer::resetRotation() {
	for (const auto& pos : DefaultBrainrot) {
		this->getChildByID(pos.first)->setRotation(pos.second);
	}
}

void CustomLoadingLayer::getPositions() {
	Positions = matjson::parse(fmt::format(R"(
{{
	"{}": {{"x": {}, "y": {} }},
	"{}": {{"x": {}, "y": {} }},
	"{}": {{"x": {}, "y": {} }},
	"{}": {{"x": {}, "y": {} }},
	"{}": {{"x": {}, "y": {} }}
}}
)", gdlogo->getID(), gdlogo->getPositionX(), gdlogo->getPositionY(),
	robtoplogo->getID(), robtoplogo->getPositionX(), robtoplogo->getPositionY(),
	fmodlogo->getID(), fmodlogo->getPositionX(), fmodlogo->getPositionY(),
	cocos2dlogo->getID(), cocos2dlogo->getPositionX(), cocos2dlogo->getPositionY(),
	progressSlider->getID(), progressSlider->getPositionX(), progressSlider->getPositionY()
));

	log::info("{}", Positions.dump());

}

void CustomLoadingLayer::getRotations() {
	Rotations = matjson::parse(fmt::format(R"(
{{
	"{}": {},
	"{}": {},
	"{}": {},
	"{}": {}
}}
)", gdlogo->getID(), gdlogo->getRotation(),
	robtoplogo->getID(), robtoplogo->getRotation(),
	fmodlogo->getID(), fmodlogo->getRotation(),
	cocos2dlogo->getID(), cocos2dlogo->getRotation()
));

	log::info("{}", Rotations.dump());

}

void CustomLoadingLayer::resetOpacity() {
	static_cast<CCSprite*>(gdlogo->getChildByID("the-sprite"))->setOpacity(255);
	static_cast<CCSprite*>(robtoplogo->getChildByID("the-sprite"))->setOpacity(255);
	static_cast<CCSprite*>(cocos2dlogo->getChildByID("the-sprite"))->setOpacity(255);
	static_cast<CCSprite*>(fmodlogo->getChildByID("the-sprite"))->setOpacity(255);
}

void CustomLoadingLayer::resetScale() {
	gdlogo->setScale(1.0f);
	robtoplogo->setScale(1.0f);
	cocos2dlogo->setScale(0.6f);
	fmodlogo->setScale(0.6f);

}

void CustomLoadingLayer::resetSprite() {
	CCArrayExt<DragNode*> kids = this->getChildren();
	std::vector<std::string> nodeIDS;
	nodeIDS.reserve(kids.size());
	auto scene = CCDirector::sharedDirector()->getRunningScene();
	
	for (auto kiddo : kids) {
		std::string str(typeid(*kiddo).name());
		if (str.find("DragNode") != std::string::npos || str.find("CCSprite") != std::string::npos) {
			nodeIDS.push_back(kiddo->getID());
		}
	}
	for (auto babynodeID : nodeIDS) {
		if (babynodeID.find("-custom") != std::string::npos) {
			scene->getChildByIDRecursive(babynodeID)->removeFromParent();
		} else {
			// im lazy

			auto gdlogologo = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("GJ_logo_001.png");
			auto robtoplogologo = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("RobTopLogoBig_001.png");
			auto fmodlogologo = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("fmodLogo.png");
			auto cocos2dlogologo = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("cocos2DxLogo.png");
			auto bgtexturetexture = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("game_bg_01_001.png");
			static_cast<CCSprite*>(gdlogo->getChildByID("the-sprite"))->setDisplayFrame(gdlogologo);
			static_cast<CCSprite*>(robtoplogo->getChildByID("the-sprite"))->setDisplayFrame(robtoplogologo);
			static_cast<CCSprite*>(fmodlogo->getChildByID("the-sprite"))->setDisplayFrame(fmodlogologo);
			static_cast<CCSprite*>(cocos2dlogo->getChildByID("the-sprite"))->setDisplayFrame(cocos2dlogologo);
			static_cast<CCSprite*>(bgtexture)->setDisplayFrame(bgtexturetexture);
			log::info("aaaaa");
			
		}
	}
}

void CustomLoadingLayer::keyBackClicked() {
	this->setKeypadEnabled(false);
	auto director = CCDirector::sharedDirector();
	director->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
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