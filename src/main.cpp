// yes i used the template

#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include "CustomLoadingLayer.hpp"
#include "LoadingLayerEditor.hpp"

using namespace geode::prelude;


class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}
		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::create("MLL_EditorBtn_001.png"_spr),
			this,
			menu_selector(MyMenuLayer::onMyButton)
		);


		auto menu = this->getChildByID("right-side-menu");
		menu->addChild(myButton);


		myButton->setID("mll-editor-button"_spr);

		menu->updateLayout();

		return true;
	}

	void onMyButton(CCObject*) {
    auto scene = cocos2d::CCScene::create();

	
    auto loadinglayer = CustomLoadingLayer::create();
	auto loadinglayereditor = LoadingLayerEditor::create();
    


    scene->addChild(loadinglayer);
	scene->addChild(loadinglayereditor);


    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f, scene));
	}
};

