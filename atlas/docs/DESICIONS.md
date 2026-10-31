# Technical Decisions

## 1. Architecture

- Atlas follows a modular architecture based on clear responsibilities and low coupling.
- `Application` coordinates the application lifecycle.
- `Window` encapsulates SDL3 window management and event processing.
- `Timer` and `Logger` remain independent of SDL3.
- `Workspace`, `Renderer`, `Simulation`, and `AI` remain future components.

## 2. Platform and Dependencies

- SDL3 is the current window and event management dependency.
- SDL3 initialization is coordinated by `Application`.
- Platform-specific functionality must remain isolated from the core services and models.
- No additional abstraction layers are introduced without a concrete requirement.

## 3. Resource Management

- `Application` coordinates subsystem initialization and shutdown.
- `Window` is responsible for destroying its SDL window.
- Initialization failures must be handled without leaving acquired resources unmanaged.
- RAII and automatic resource management are preferred for future resource ownership improvements.

## 4. Build System

- CMake is used as the project's build system.
- SDL3 is integrated through CMake FetchContent.
- Configuration and compilation are performed from the repository root.
- The current build configuration is centralized rather than split into unnecessary module-level CMake files.

## 5. Deferred Decisions

The following decisions are intentionally postponed:

- Physical separation of Core and Platform into independent build targets.
- Introduction of abstract interfaces such as `IWindow`.
- Renderer architecture and graphics API selection.
- Workspace data model and spatial representation.
- XR and OpenXR integration.
- Simulation and AI subsystem architecture.

These decisions will be revisited when concrete implementation requirements justify them.

## 6. Rationale

The Sprint prioritizes establishing a reliable application foundation while avoiding premature architectural complexity.

The decisions above provide a direction for future development without requiring the implementation of components that do not yet deliver functional value.
