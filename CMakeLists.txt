cmake_minimum_required(VERSION 3.13)
project(FakeRewards)

# Variables del mod
set(MOD_ID "mrchile123.fake_rewards")
set(MOD_NAME "Fake Rewards 2")
set(MOD_VERSION "1.0.0")
set(MOD_DEVELOPER "Mrchile123")
set(MOD_DESCRIPTION "Un mod que muestra recompensas falsas en Geometry Dash")

# Incluir Geode SDK
include($ENV{GEODE_SDK_PATH}/cmake/geode.cmake)

# Crear el mod
create_geode_mod(
    ID "${MOD_ID}"
    NAME "${MOD_NAME}"
    VERSION "${MOD_VERSION}"
    DEVELOPER "${MOD_DEVELOPER}"
    DESCRIPTION "${MOD_DESCRIPTION}"
    
    SOURCES
        src/main.cpp
)
