#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "EmirGui.hpp"

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    struct Fields {
        EmirGui::Window* guiWindow = nullptr;
    };

    bool init() {
        if (!MenuLayer::init()) return false;

        auto menu = this->getChildByID("bottom-menu");
        if (!menu) return true;

        // Toggle ile GUI penceresini aç/kapat
        auto toggle = EmirGui::createToggle("GUI AÇ", "GUI AÇ", this, menu_selector(MyMenuLayer::onToggleGUI));
        toggle->setID("gui-toggle"_spr);
        menu->addChild(toggle);
        menu->updateLayout();

        return true;
    }

    void onToggleGUI(CCObject*) {
        if (m_fields->guiWindow) {
            m_fields->guiWindow->removeFromParent();
            m_fields->guiWindow = nullptr;
        } else {
            m_fields->guiWindow = EmirGui::Window::create(CCSize(400, 350), "Emir GUI Kütüphanesi");
            
            // İçerik menüsü
            auto contentMenu = CCMenu::create();
            
            // Label
            auto lbl = EmirGui::Label::create("Mükemmel GUI Demo", 0.7f);
            lbl->setPosition(200, 280);
            contentMenu->addChild(lbl);
            
            // TextBox
            auto textBox = EmirGui::TextBox::create(CCSize(200, 30), "İsmini yaz...");
            textBox->setPosition(100, 230);
            textBox->setCallback([](const std::string& text) {
                log::info("Girilen isim: {}", text);
                Notification::create(fmt::format("Merhaba, {}!", text), NotificationIcon::Success)->show();
            });
            contentMenu->addChild(textBox);
            
            // Slider
            auto sliderLbl = EmirGui::Label::create("Ses Seviyesi:", 0.5f);
            sliderLbl->setPosition(30, 170);
            contentMenu->addChild(sliderLbl);
            
            auto slider = EmirGui::Slider::create(0, 100, 50, CCSize(200, 30), [](float val) {
                log::info("Slider değeri: {:.0f}", val);
            });
            slider->setPosition(180, 170);
            contentMenu->addChild(slider);
            
            // Checkbox
            auto check = EmirGui::Checkbox::create(false, [](bool checked) {
                log::info("Checkbox: {}", checked);
                Notification::create(checked ? "Açıldı" : "Kapatıldı", NotificationIcon::Info)->show();
            });
            check->setPosition(30, 120);
            contentMenu->addChild(check);
            
            auto checkLbl = EmirGui::Label::create("Hitbox'ları göster", 0.5f);
            checkLbl->setPosition(60, 120);
            contentMenu->addChild(checkLbl);
            
            // Dropdown
            auto dropdown = EmirGui::Dropdown::create({"Seçenek 1", "Seçenek 2", "Seçenek 3"}, 0, [](int idx, const std::string& val) {
                log::info("Seçildi: {} - {}", idx, val);
            });
            dropdown->setPosition(250, 120);
            contentMenu->addChild(dropdown);
            
            // Progress Bar
            auto progress = EmirGui::ProgressBar::create(CCSize(200, 20), EmirGui::Theme::success());
            progress->setPosition(100, 60);
            contentMenu->addChild(progress);
            
            // Buton ile progress artır
            auto btn = EmirGui::createButton("Artır", this, menu_selector(MyMenuLayer::onIncreaseProgress));
            btn->setPosition(200, 20);
            contentMenu->addChild(btn);
            
            // Slider'ı progress'e bağlamak için
            struct { EmirGui::Slider* slider; EmirGui::ProgressBar* progress; } data{slider, progress};
            slider->setCallback([data](float val) {
                data.progress->setProgress(val / 100.0f);
            });
            
            m_fields->guiWindow->setContent(contentMenu);
            m_fields->guiWindow->setPosition(CCDirector::sharedDirector()->getWinSize().width / 2 - 200, 
                                           CCDirector::sharedDirector()->getWinSize().height / 2 - 175);
            this->addChild(m_fields->guiWindow);
        }
    }
    
    void onIncreaseProgress(CCObject*) {
        // Progress bar örneği için dummy
    }
};
        m_fields->guiMenu->addChild(m_fields->toggle);

        this->setTouchEnabled(true);
    }

    bool ccTouchBegan(CCTouch* touch, CCEvent* event) {
        auto pos = m_fields->guiMenu->convertToNodeSpace(touch->getLocation());

        CCRect rect = CCRect(-70.f, -35.f, 140.f, 70.f);

        return rect.containsPoint(pos);
    }

    void ccTouchMoved(CCTouch* touch, CCEvent* event) {
        auto delta = touch->getDelta();

        auto current = m_fields->guiMenu->getPosition();
        m_fields->guiMenu->setPosition({
            current.x + delta.x,
            current.y + delta.y
        });
    }

    void onToggle(CCObject*) {
        g_hitboxEnabled = !g_hitboxEnabled;

        updateOverlayState();

        Notification::create(
            g_hitboxEnabled
                ? "Real hitbox overlay enabled"
                : "Real hitbox overlay disabled",
            NotificationIcon::Success
        )->show();
    }
};
