#pragma once
#include <Geode/Geode.hpp>
#include <Geode/ui/BasedButtonSprite.hpp>

using namespace geode::prelude;

namespace EmirGui {

    // Daire sprite buton
    inline CCMenuItemSpriteExtra* createCircleBtn(
        const char* sprName,
        CCObject* target,
        SEL_MenuHandler callback
    ) {
        auto spr = CircleButtonSprite::createWithSpriteFrameName(sprName);
        return CCMenuItemSpriteExtra::create(spr, target, callback);
    }

    // Yazı buton — 3 argümanlı overload kullanıyoruz (non-inline, güvenli)
    inline CCMenuItemSpriteExtra* createTextBtn(
        const char* text,
        CCObject* target,
        SEL_MenuHandler callback
    ) {
        // caption, font, texture — inline olmayan güvenli overload
        auto spr = ButtonSprite::create(text, "bigFont.fnt", "GJ_button_01.png");
        return CCMenuItemSpriteExtra::create(spr, target, callback);
    }

    // Toggle (açık/kapalı) buton
    inline CCMenuItemToggler* createToggleBtn(
        const char* labelOn,
        const char* labelOff,
        CCObject* target,
        SEL_MenuHandler callback
    ) {
        auto sprOn  = ButtonSprite::create(labelOn,  "bigFont.fnt", "GJ_button_02.png");
        auto sprOff = ButtonSprite::create(labelOff, "bigFont.fnt", "GJ_button_04.png");
        return CCMenuItemToggler::create(sprOff, sprOn, target, callback);
    }

} // namespace EmirGui
