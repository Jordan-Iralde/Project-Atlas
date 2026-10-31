# Atlas Architecture — Design Decisions

## 1. Philosophy

Atlas follows the _Less, but better_ philosophy.

The architecture prioritizes clear responsibilities, loose coupling, explicit resource management, and technical understanding of the system. Abstractions and subsystems will not be introduced without a concrete need.

The architecture must allow Atlas to evolve without turning initial decisions into unnecessary constraints.

## 2. Conceptual Architecture

The conceptual architecture describes the system's current and future responsibilities. It does not imply that every component must be implemented during the current sprint.

```text
Atlas
├── Application
│   └── Lifecycle coordination
├── Core
│   ├── Timer
│   ├── Logger
│   └── Workspace (future)
├── Platform
│   └── SDL3
│       └── Window
├── Renderer (future)
├── Simulation (future)
└── AI (future)
```

### Application

Coordinates initialization, the main execution loop, updates, rendering, and application shutdown.

It must not take over the internal responsibilities of the subsystems it coordinates.

### Core

Contains Atlas's fundamental services and models that do not need to depend on the graphics platform.

`Timer` and `Logger` are considered services independent of SDL3.

The future `Workspace` will represent the elements, states, and relationships that make up the Atlas environment.

### Platform

Encapsulates interactions with the operating system and platform-specific libraries.

In the current implementation, SDL3 provides window management and event processing.

Global SDL3 initialization remains coordinated by `Application` until a concrete need justifies introducing an additional component.

### Renderer (Future)

Will be responsible for visually presenting the environment's state.

Its implementation should prevent the `Workspace` model from becoming unnecessarily dependent on the details of a specific graphical interface.

### Simulation (Future)

Will represent simulation capabilities when concrete requirements justify introducing this subsystem.

### AI (Future)

Will group the artificial intelligence capabilities that Atlas needs to integrate. Its design will depend on the use cases and the boundaries of responsibility those use cases require.

## 3. Architectural Principles

### 3.1. Platform Isolation

`Core` services and models must not directly depend on SDL3.

Platform-specific code must remain confined to the components responsible for that integration.

Platform independence does not require introducing abstract interfaces before they are needed.

### 3.2. Resource Ownership and Lifecycle

Every resource must have a clearly defined owner responsible for its initialization and release.

`Application` coordinates the overall lifecycle. Components that own resources must ensure their safe release, even when initialization fails partially.

RAII and automatic resource management in C++ will be preferred where appropriate.

### 3.3. Separation of Model and Presentation

The `Workspace` model must not depend unnecessarily on the visual representation used by a client.

A desktop interface and a future XR interface may present the same state through different representations.

This separation does not prevent the model from incorporating spatial properties when they are part of its domain.

### 3.4. Avoidance of Premature Abstraction

Interfaces, adaptation layers, and generic systems will not be created without a demonstrable need.

Any new abstraction must solve a concrete problem or enable an evolution supported by actual requirements.

### 3.5. Incremental Evolution

Future components are evolution targets, not automatic requirements for the current sprint.

The directory structure must reflect the actual needs of the code rather than being required to reproduce the conceptual diagram.

## 4. Current Scope

The current implementation focuses on establishing the foundations of the application lifecycle, SDL3-based window management, event logging, and time measurement.

The following are outside the current scope: a complete `Workspace` implementation, the final renderer, simulation, AI integration, and XR compatibility.

These components will be introduced when concrete use cases and acceptance criteria have been defined.

## 5. Architectural Definition of Done

The architectural decisions are considered sufficiently established for the current stage when:

- `Timer` and `Logger` can operate without depending on SDL3.
- `Window` encapsulates window management and event processing.
- Resource initialization and release have clearly defined owners.
- Initialization failures do not cause incorrect resource cleanup or leave acquired resources unmanaged.
- The responsibilities of `Workspace` and `Renderer` are defined without requiring their premature implementation.
- No unnecessary dependencies exist between the environment model and its future visual representation.
- Introduced abstractions address concrete needs.

The architecture must be reviewed as Atlas gains new capabilities and requirements emerge that justify additional decisions.
