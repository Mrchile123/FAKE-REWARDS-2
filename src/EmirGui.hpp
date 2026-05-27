#pragma once
#include <Geode/Geode.hpp>

using namespace geode::prelude;

namespace EmirGui {
    // Circle Button oluşturucu
    inline CCMenuItemSpriteExtra* createCircleBtn(const char* sprName, CCObject* target, SEL_MenuHandler callback) {
        auto spr = CircleButtonSprite::createWithSpriteFrameName(sprName);
        return CCMenuItemSpriteExtra::create(spr, target, callback);
    }

    // Text Button oluşturucu
    inline CCMenuItemSpriteExtra* createTextBtn(const char* text, CCObject* target, SEL_MenuHandler callback) {
        auto spr = ButtonSprite::create(text);
        return CCMenuItemSpriteExtra::create(spr, target, callback);
    }

    // Menüye güvenli ekleme ve hizalama (Layout)
    inline void addToMenu(CCMenu* menu, CCNode* node) {
        if (menu && node) {
            menu->addChild(node);
            menu->updateLayout();
        }
    }
}
