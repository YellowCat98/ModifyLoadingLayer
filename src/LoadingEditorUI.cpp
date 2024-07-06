#include "LoadingEditorUI.hpp"
#include "MLLManager.hpp" // for CCMENUISE_REMOVE_EASE
#include "CustomLoadingLayer.hpp"

bool LoadingEditorUI::init() {
	if (!CCLayer::init()) return false;
	this->setID("LoadingEditorUI");
	winSize = CCDirector::sharedDirector()->getWinSize();

	// <create toolbar>
	toolbar = CCLayerColor::create();
	float top = CCDirector::sharedDirector()->getWinSize().height;
	toolbar->setPositionY(top - 20.0f);
	auto size = this->getContentSize();
	toolbar->setContentSize({size.width, 20.0f});
	toolbar->setOpacity(150);
	auto menu = CCMenu::create();
	menu->setPosition({0.0f, 0.0f});
	menu->setContentSize({size.width, 20.0f});
	toolbar->addChild(menu);
	this->addChild(toolbar);
	

	// <create hide toolbar>
	auto moveBtn = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png"), this, menu_selector(LoadingEditorUI::moving));
	moveBtn->setRotation(-90.0f);
	moveBtn->setPosition({10.0f, 10.0f});
	moveBtn->setScale(0.5f);
	REMOVE_EASE(moveBtn);
	menu->addChild(moveBtn);
	hideToolbar = moveBtn;
	// </create hide toolbar>

	// <create reset button>
	reset = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("MLL_EraseBtn.png"_spr), this, menu_selector(LoadingEditorUI::Reset));
	reset->setPosition({(moveBtn->getPositionX() + 20.0f), 10.0f});
	reset->setScale(0.4f);
	REMOVE_EASE(reset);
	menu->addChild(reset);
	// </create reset button>

	// <create restart button>
	restart = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("MLL_RestartBtn.png"_spr), this, menu_selector(LoadingEditorUI::Restart));
	restart->setPosition({(reset->getPositionX() + 20.0f), 10.0f});
	restart->setScale(0.4f);
	REMOVE_EASE(restart);
	menu->addChild(restart);
	// </create restart button>
	// </create toolbar>

	// </create main>
	main = CCLayerColor::create();
	main->setColor({ 0, 0, 0 });
	main->setOpacity(150);
	main->setContentSize({main->getContentSize().width, 120});
	main->setPositionY(main->getPositionY() - 120.0f);
	this->addChild(main);

	// <create menu>
	mainMenu = CCMenu::create();
	mainMenu->setContentSize(main->getContentSize());
	mainMenu->setPosition({0.0f, 0.0f});
	main->addChild(mainMenu);
	// </create menu>

	// <create hide main button>
	hideMain = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png"), this, menu_selector(LoadingEditorUI::hideMainF));
	REMOVE_EASE(hideMain);
	hideMain->setRotation(90.0f);
	hideMain->setScale(0.5f);
	hideMain->setPosition({winSize.width / 2, (winSize.height / 2) - 30});
	mainMenu->addChild(hideMain);
	// </create hide main button>

	// <create main buttons>
	selectMove = CCMenuItemToggler::create(CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png"), CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"), this, menu_selector(LoadingEditorUI::canMoveF));
	mainMenu->addChild(selectMove);
	// </create main buttons>

	// </create main>

	return true;
}

void LoadingEditorUI::canMoveF(CCObject* sender) {
	mllm->canMoveNode = !mllm->canMoveNode;
}

void LoadingEditorUI::hideMainF(CCObject* sender) {
	hideMain->setScale(0.5f);
	static bool shown = false;
	float duration = 0.4;
	float deltaY;

	if (shown) {
		deltaY = -120.0f;
		shown = false;
	} else {
		deltaY = 120.0f;
		shown = true;
	}
	
	auto moveBy = CCMoveBy::create(duration, CCPoint(0, deltaY));
	auto easeSineOut = CCEaseSineOut::create(moveBy);
	main->runAction(easeSineOut);
}

void LoadingEditorUI::moving(CCObject* sender) {
	hideToolbar->setScale(0.5f); // thanks!
	hideToolbar->setEnabled(false);
	static bool shown = true;
	float duration = 0.4f;
	float deltaY;
	float fartY;
	float positionY = this->getPositionY();
	if (shown) {
		deltaY = 20.0f;
		fartY = -20.0f;
		shown = false;
	} else {
		deltaY = -20.0f;
		fartY = 20.0f;
		shown = true;
	}

	auto moveBy = CCMoveBy::create(duration, CCPoint(0, deltaY));
	auto fartBy = CCMoveBy::create(duration, CCPoint(0, fartY));

	auto easeSineOut = CCEaseSineOut::create(moveBy);
	auto easeFartOut = CCEaseSineOut::create(fartBy);

	toolbar->runAction(easeSineOut);

	auto callback = CCCallFunc::create(this, callfunc_selector(LoadingEditorUI::moveHidebutton));
	
	if (callback) {
		auto sequence = CCSequence::create(CCDelayTime::create(0.4f), easeFartOut, callback, nullptr);
		if (sequence) {
			hideToolbar->runAction(sequence);
		}
	}
}

void LoadingEditorUI::moveHidebutton() {
	hideToolbar->setEnabled(true);
}

void LoadingEditorUI::Reset(CCObject* sender) {
	reset->setScale(0.4f);
	geode::createQuickPopup(
		"Confirm",
		"This <cr>resets</c> all modifications you've done. Are you sure?",
		"Yes", "No",
		[this](auto, bool btn2) {
			if (!btn2) {
				auto customloadinglayer = static_cast<CustomLoadingLayer*>(this->getParent());
				customloadinglayer->resetPosition();
			}
		}
	);
}

void LoadingEditorUI::Restart(CCObject* sender) {
	restart->setScale(0.4f);
	geode::createQuickPopup(
		"Confirm",
		"This restarts the game,\n"
		"Please save any changes you've done.\n"
		"Otherwise they will be <cr>lost.</c>\n"
		"Are you sure?",
		"Yes", "No",
		[](auto, bool btn2) {
			if (!btn2) {
				utils::game::restart();
			}
		}
	);
}

LoadingEditorUI* LoadingEditorUI::create() {
	LoadingEditorUI* layer = new LoadingEditorUI();
	if (layer && layer->init()) {
		layer->autorelease();
		return layer;
	}
	CC_SAFE_DELETE(layer);
	return nullptr;
}