#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>
using namespace geode::prelude;
class ModernMenu : public CCLayer {
protected:
    CCMenu* m_buttonMenu = nullptr;
    CCMenuItemSpriteExtra* m_floatButton = nullptr;
    CCLayerColor* m_panel = nullptr;
    CCScale9Sprite* m_background = nullptr;
    bool m_open = false;
    bool m_dragging = false;
    CCPoint m_dragOffset;
    float m_savedX = 80.f;
    float m_savedY = 160.f;
public:
    static ModernMenu* create() {
        auto ret = new ModernMenu();
        if (ret && ret->init()) {
            ret->autorelease();
            return ret;
        }
        delete ret;
        return nullptr;
    }
    bool init() override {
        if (!CCLayer::init())
            return false;
        auto winSize = CCDirector::sharedDirector()->getWinSize();
        this->setTouchEnabled(true);
        this->setTouchMode(kCCTouchesOneByOne);
        this->setKeypadEnabled(true);
