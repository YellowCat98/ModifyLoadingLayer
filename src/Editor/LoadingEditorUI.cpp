#include "LoadingEditorUI.hpp"
#include "../MLLManager.hpp" // for literally most things here
#include "CustomLoadingLayer.hpp"
#include "Rotation.hpp"
#include "Scale.hpp"
#include "InputPopup.hpp"
#include "RGBA.hpp"

bool LoadingEditorUI::init() {
	if (!CCLayer::init()) return false;
	this->setID("LoadingEditorUI");
	winSize = CCDirector::sharedDirector()->getWinSize();
	this->setZOrder(1.0f);
	buttonArray = CCArray::create();
	canRotate = false;

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

	// <create save button>
	saveBtn = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("MLL_SaveBtn.png"_spr), this, menu_selector(LoadingEditorUI::Save));
	saveBtn->setPosition({restart->getPositionX() + 20.0f}, 10.0f);
	saveBtn->setScale(0.4f);
	REMOVE_EASE(saveBtn);
	menu->addChild(saveBtn);
	// </create save button>

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
	// <create button sprites>

	// <create move button sprite>

	auto moveSprite = ButtonSprite::create(CCSprite::createWithSpriteFrameName("MLL_DragBtn.png"_spr), 100, true, 50.0f, "GJ_button_01.png", 1.25f);
	auto moveBtnSelectedSpr = ButtonSprite::create(CCSprite::createWithSpriteFrameName("MLL_DragBtn.png"_spr), 100, true, 50.0f, "GJ_button_01.png", 1.25f);
	moveBtnSelectedSpr->setColor({128, 128, 128});
	moveSprite->setColor({123,123,123});

	// </create move button sprite>

	// <create rotate button sprite>

	auto brainrotBtnSpr = ButtonSprite::create(CCSprite::createWithSpriteFrameName("MLL_rotateBtn.png"_spr), 100, true, 50.0f, "GJ_button_01.png", 1.25f);
	auto brainrotBtnSprSelected = ButtonSprite::create(CCSprite::createWithSpriteFrameName("MLL_rotateBtn.png"_spr), 100, true, 50.0f, "GJ_button_01.png", 1.25f);
	brainrotBtnSprSelected->setColor({128, 128, 128});

	// </create rotate button sprite>

	// <create scale button sprite>

	auto scaleSpr = ButtonSprite::create(CCSprite::createWithSpriteFrameName("edit_scaleXYBtn_001.png"), 100, true, 50.0f, "GJ_button_01.png", 1.25f);
	auto scaleSprS = ButtonSprite::create(CCSprite::createWithSpriteFrameName("edit_scaleXYBtn_001.png"), 100, true, 50.0f, "GJ_button_01.png", 1.25f);
	scaleSprS->setColor({128, 128, 128});

	// </create scale button sprite>

	// <create hide button sprite>

	auto hideSpr = ButtonSprite::create(CCSprite::createWithSpriteFrameName("MLL_HideBtn.png"_spr), 100, true, 50.0f, "GJ_button_01.png", 1.125f);
	auto hideSprS = ButtonSprite::create(CCSprite::createWithSpriteFrameName("MLL_HideBtn.png"_spr), 100, true, 50.0f, "GJ_button_01.png", 1.125f);
	hideSprS->setColor({128, 128, 128});
	// </create hide button sprite>

	// <create change button sprite>
	auto changeSpr = ButtonSprite::create(CCSprite::createWithSpriteFrameName("MLL_SpriteBtn.png"_spr), 100, true, 50.0f, "GJ_button_01.png", 1.125f);
	// </create change button sprite>

	// </create button sprites>

	// <create main buttons>

	// <create move button>
	selectMove = CCMenuItemToggler::create(moveSprite, moveBtnSelectedSpr, this, menu_selector(LoadingEditorUI::canMoveF));
	buttonArray->addObject(selectMove);
	// </create move button>

	// <create scale button>
	scale = CCMenuItemToggler::create(scaleSpr, scaleSprS, this, menu_selector(LoadingEditorUI::onScale));
	buttonArray->addObject(scale);
	// </create scale button>

	// <create rotate button>
	brainRot = CCMenuItemToggler::create(brainrotBtnSpr, brainrotBtnSprSelected, this, menu_selector(LoadingEditorUI::canRotateF));
	buttonArray->addObject(brainRot);
	// </create rotate button>

	// <create hide button>
	hideBtn = CCMenuItemToggler::create(hideSpr, hideSprS, this, menu_selector(LoadingEditorUI::onHide));
	buttonArray->addObject(hideBtn);
	// </create hide button>

	// <create change sprite button>
	auto idk = CCMenuItemSpriteExtra::create(changeSpr, this, menu_selector(LoadingEditorUI::onChangeSprite));
	buttonArray->addObject(idk);
	// </create change sprite button>

	// </create main buttons>

	// <create editbuttonbar>
	auto buttonBar = ListButtonPage::create(buttonArray, {400, -290}, 15, 15, 25.0f, 25.0f, 25.0f);
	main->addChild(buttonBar);
	// </create editbuttonbar>

	// </create main>

	return true;
}

void LoadingEditorUI::Save(CCObject* sender) {
	saveBtn->setScale(0.4f);
	log::info("hi");
}

void LoadingEditorUI::onSelectBG(CCObject* sender) {
	log::info("|asdasd|");
}

void LoadingEditorUI::onHide(CCObject* sender) {
	if (mllm->currentSelectedNode.empty()) {
		Notification::create("Select a node first!", CCSprite::createWithSpriteFrameName("GJ_deleteIcon_001.png"))->show();
		return;
	}
	canOpacity = !canOpacity;

	if (canOpacity) {
		_rgba = _rgba::create(mllm->currentSelectedNode);
		this->addChild(_rgba);
	} else {
		_rgba->removeFromParent();
		_rgba = nullptr;
	}
}

void LoadingEditorUI::onChangeSprite(CCObject* sender) {
	CCNode* node;
	std::unordered_set<std::string> thefiles;
	thefiles.insert("*.png");
	utils::file::FilePickOptions::Filter idk;
	idk.description = "Pick a file, only PNG works.";
	idk.files = thefiles;
	utils::file::FilePickOptions pick;
	pick.filters = {idk}; // why this is so dumb
	std::filesystem::path path;
	m_pickListener.bind([this, path, &node](Task<Result<std::filesystem::path>>::Event* event) {
		if (event->isCancelled()) {
			Notification::create("Failed to open file.")->show();
			return;
		}
		if (auto result = event->getValue()) {
			if (result->isErr()) {
				Notification::create(fmt::format("Failed to open file. Error: {}", result->err()))->show();
				return;
			}
			auto path = result->unwrap();
			auto targetDir = mllm->temp / (mllm->currentSelectedNode + ".png");

			CCTextureCache::sharedTextureCache()->removeTextureForKey(targetDir.string().c_str());
			
			if (!path.has_extension() || path.extension() != ".png") {
				Notification::create("Only PNGs are supported.");
				return;
			}

			log::info("{}", path.string());
			if (std::filesystem::exists(targetDir)) {
				std::filesystem::remove(targetDir);
			}
			std::filesystem::copy_file(path, targetDir, std::filesystem::copy_options::overwrite_existing);

			texture = CCTextureCache::sharedTextureCache()->addImage(targetDir.string().c_str(), false);
			geode::createQuickPopup(
				"Change sprite or add sprite?",
				"Would you like to change the sprite of\nthe current selected node\n"
				"Or add a new sprite? this will be treated as every other sprite.",
				"Change", "Add",
				[this](auto, bool btn2) {
					if (btn2) {
						auto node = DragNode::create(CCSprite::createWithTexture(texture));
						auto popup = InputPopup::create("my-cool-sprite", node);
						popup->show();
						node->mllm = mllm;
						this->getParent()->addChild(node);
					} else {
							if (mllm->currentSelectedNode.empty()) {
								Notification::create("Select a node first!", CCSprite::createWithSpriteFrameName("GJ_deleteIcon_001.png"))->show();
								return;
							}
						auto node = static_cast<CCSprite*>(CCDirector::sharedDirector()->getRunningScene()->getChildByIDRecursive(mllm->currentSelectedNode)->getChildByID("the-sprite"));
						node->setTextureRect(CCRectMake(0, 0, texture->getContentSize().width, texture->getContentSize().height));
						node->setTexture(texture);
						node->setContentSize(texture->getContentSize());
						node->setDirty(true); // com eon
					}
				}
			);

		}
	});
	m_pickListener.setFilter(file::pick(file::PickMode::OpenFile, pick));
}

void LoadingEditorUI::onScale(CCObject* sender) {
	if (mllm->currentSelectedNode.empty()) {
		Notification::create("Select a node first!", CCSprite::createWithSpriteFrameName("GJ_deleteIcon_001.png"))->show();
		return;
	}
	canScale = !canScale;
	
	if (canScale) {
		scaleInstance = Scale::create(mllm->currentSelectedNode);
		this->addChild(scaleInstance);
	} else {
		scaleInstance->removeFromParent();
		scaleInstance = nullptr;
	}
}

void LoadingEditorUI::canRotateF(CCObject* sender) {
	if (mllm->currentSelectedNode.empty()) {
		Notification::create("Select a node first!", CCSprite::createWithSpriteFrameName("GJ_deleteIcon_001.png"))->show();
		return;
	}
	canRotate = !canRotate;
	if (canRotate) {
		r = Rotation::get(mllm->currentSelectedNode);
		this->addChild(r);
	} else {
		r->removeFromParent();
		r = nullptr;
	}

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
				customloadinglayer->resetRotation();
				customloadinglayer->resetOpacity();
				customloadinglayer->resetScale();
				customloadinglayer->resetSprite();
			}
		}
	);
}

void LoadingEditorUI::Restart(CCObject* sender) {
	if (Mod::get()->getSettingValue<bool>("disable-restart-confirmation")) {
		utils::game::restart();
		return; // will this even do anything
	}
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