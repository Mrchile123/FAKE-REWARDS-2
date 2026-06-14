#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

// Mod principal para Fake Rewards
class FakeRewardsMod : public Geode::Mod {
public:
    static FakeRewardsMod* get() {
        static FakeRewardsMod instance;
        return &instance;
    }

    void onModLoad() {
        log::info("Fake Rewards mod cargado correctamente en Android!");
    }
};

GEODE_API bool GEODE_CALL geode_load(Mod*) {
    log::info("✓ Fake Rewards 2 v1.0.0 cargado en Geometry Dash Android!");
    log::info("✓ Recompensas falsas activadas");
    return true;
}

GEODE_API void GEODE_CALL geode_unload() {
    log::info("✓ Fake Rewards 2 descargado");
}
