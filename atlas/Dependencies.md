# Dependencias de Atlas

Atlas está diseñado bajo la filosofía _Less, but better_, minimizando dependencias externas y priorizando la portabilidad y la comprensión técnica.

## Requisitos del Sistema

- **Compilador C++:** Compatible con **C++20** (GCC 11+ o Clang 13+).
- **Sistema de Build:** **CMake** versión 3.20 o superior (recomendado 3.28.3+).

## Dependencias Externas

### 1. Simple DirectMedia Layer (SDL3)

- **Propósito:** Gestión de ventanas, eventos de plataforma y futuros contextos gráficos.
- **Método de integración:** Gestionado automáticamente mediante CMake (`FetchContent`) o enlazado desde el sistema según la configuración del entorno.
- **Versión:** SDL3 (rama estable / release oficial).
