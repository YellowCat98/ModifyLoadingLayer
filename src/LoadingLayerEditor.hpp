#pragma once

class LoadingLayerEditor : public cocos2d::CCLayer {
    public:

    void onExit(CCObject* sender);
    void onBG(CCObject* sender);
    void onGJLogoSpr(CCObject* sender);
    void onRobert(CCObject* sender);
    void onFMod(CCObject* sender);
    void onCocos(CCObject* sender);
    void onErase(CCObject* sender);
    void onReload(CCObject* sender);
    void onRestart(CCObject* sender);


    static LoadingLayerEditor* create();
    private:
    bool init() override;
};