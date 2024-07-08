// yes i AM the geode tempalte

#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include "CustomLoadingLayer.hpp"
#include "DragNode.hpp"
#include "MLLManager.hpp"
#include "Rotation.hpp"

using namespace geode::prelude;


class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}
		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("MLL_EditorBtn.png"_spr),
			this,
			menu_selector(MyMenuLayer::onMyButton)
		);


		auto menu = this->getChildByID("right-side-menu");
		menu->addChild(myButton);
		menu->updateLayout();
		myButton->setID("mll-editor-button"_spr);

		auto array = CCArray::create();
		array->addObject(this->getChildByIDRecursive("achievements-button"));
		array->addObject(this->getChildByIDRecursive("settings-button"));

		auto hmm = ListButtonPage::create(array, {100, 100}, 15, 15, 25.0f, 25.0f, 25.0f);
		this->addChild(hmm);

		return true;
	}

	void onMyButton(CCObject*) {
	auto scene = cocos2d::CCScene::create();

	
	auto loadinglayer = CustomLoadingLayer::create();


	scene->addChild(loadinglayer);

	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f, scene));
	}
};