#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "EmirGui.hpp" 

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // "bottom-menu" düğümünü bul
        auto menu = static_cast<CCMenu*>(this->getChildByID("bottom-menu"));

        // Kütüphane üzerinden butonu oluştur
        auto btn = EmirGui::createCircleBtn(
            "GJ_likeBtn_001.png", 
            this, 
            menu_selector(MyMenuLayer::onEmirClick)
        );

        btn->setID("emir-buton"_spr);

        // Kütüphane üzerinden menüye ekle ve hizala
        EmirGui::addToMenu(menu, btn);

        return true;
    }

    void onEmirClick(CCObject* sender) {
        FLAlertLayer::create(
            "Başarılı!", 
            "EmirGui kütüphanesi sorunsuz çalışıyor.", 
            "Tamam"
        )->show();
    }
};
