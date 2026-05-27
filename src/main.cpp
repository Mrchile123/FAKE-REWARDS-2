#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class FloatingMenu : public cocos2d::CCLayer {
protected:
    cocos2d::CCLayer* m_mainGui;
    bool m_dragging = false;

    bool init() override {
        // 1. Ana GUI (Gizli başlar)
        m_mainGui = CCLayer::create();
        m_mainGui->setVisible(false);
        this->addChild(m_mainGui, 10);

        // 2. Sürüklenen Daire Buton
        auto circleSprite = CCSprite::create("circle_button.png"); // Kendi daire görselini ekle
        auto toggleBtn = CCMenuItemSprite::create(circleSprite, circleSprite, this, menu_selector(FloatingMenu::onToggle));
        auto menu = CCMenu::create(toggleBtn, nullptr);
        menu->setPosition({50, 50});
        this->addChild(menu);

        // Dokunmatik olaylarını dinle
        this->setTouchEnabled(true);
        return true;
    }

    void onToggle(CCObject*) {
        m_mainGui->setVisible(!m_mainGui->isVisible());
    }

    // Sürükleme Mantığı
    void ccTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) override {
        auto pos = pTouch->getLocation();
        this->setPosition(pos); // Daireyi sürükle
    }
};

// Hem Menu hem PlayLayer'da çalışması için
class $modify(MyPlayLayer, PlayLayer) {
    bool init() override {
        if (!PlayLayer::init()) return false;
        this->addChild(FloatingMenu::create(), 100);
        return true;
    }
};
