# Fake Rewards 2

Un mod de **Geode** para **Geometry Dash** que muestra recompensas falsas.

## 📋 Requisitos

- **Geometry Dash 2.2081** (Windows, Android, Mac, iOS)
- **Geode Loader** instalado
- **Node IDs v1.23.3** o superior

## 🚀 Características

- ✨ Recompensas personalizadas falsas
- 🎮 Compatible con Android y otras plataformas
- 🔧 Totalmente integrado con Geode SDK
- 📱 Interfaz fácil de usar

## 💾 Instalación

1. Descargar el archivo `.geode` del mod
2. Colocar en la carpeta `Geode/mods/` de Geometry Dash
3. Reiniciar el juego

## 🛠️ Compilación

### Requisitos previos

```bash
# Clonar el Geode SDK
git clone https://github.com/geode-sdk/geode.git
export GEODE_SDK_PATH=/ruta/a/geode
```

### Compilar el mod

```bash
# Crear directorio de build
mkdir build && cd build

# Configurar CMake
cmake ..

# Compilar
cmake --build . --config Release
```

## 📄 Estructura del Proyecto

```
FAKE-REWARDS-2/
├── src/
│   └── main.cpp          # Código principal del mod
├── CMakeLists.txt        # Configuración de compilación
├── mod.json              # Metadatos del mod
└── README.md             # Este archivo
```

## 👨‍💻 Autor

**Mrchile123** - Desarrollador

## 📜 Licencia

Bajo la comunidad de Geode Loader.

---

**¡Disfruta de tus recompensas falsas en Geometry Dash!** 🎉
