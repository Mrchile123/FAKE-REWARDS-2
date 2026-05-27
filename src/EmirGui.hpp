#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;

namespace EmirGui {
    // Sürükle-bırak panel
    class EmirMenu : public Popup<std::string> {
    protected:
        bool setup(std::string title) override {
            this->setTitle(title);
            auto menu = CCMenu::create();
            menu->setPosition({0, 0});
            this->m_mainLayer->addChild(menu);

            // Noclip Toggle
            auto noclip = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(EmirMenu::onToggle), false);
            noclip->setPosition({100, 150});
            menu->addChild(noclip);

            // ESP Toggle
            auto esp = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(EmirMenu::onToggle), false);
            esp->setPosition({100, 100});
            menu->addChild(esp);
            
            return true;
        }
        void onToggle(CCObject* sender) { /* Toggle mantığı */ }
    public:
        static EmirMenu* create() {
            auto ret = new EmirMenu();
            if (ret && ret->initAnchored(300, 200, "Emir Menu")) {
                ret->autorelease();
                return ret;
            }
            CC_SAFE_DELETE(ret);
            return nullptr;
        }
    };
}
