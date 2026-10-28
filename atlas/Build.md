# Build — Atlas

## Requisitos

Atlas utiliza C++20 y SDL3, descargada mediante CMake FetchContent.

## Configurar y compilar

Ejecutar desde la raíz del proyecto, donde se encuentra `CMakeLists.txt`:

```bash
cmake -S . -B build
cmake --build build
```

## Ejecutar

```bash
./build/engine/Atlas
```

Si no encuentras el ejecutable:

```bash
find build -type f -executable -name Atlas
```

## Reconstruir desde cero

```bash
rm -rf build
cmake -S . -B build
cmake --build build
```

**Nota:** `build/` se genera automáticamente. No ejecutes CMake desde `engine/`; utiliza siempre la raíz del proyecto.
