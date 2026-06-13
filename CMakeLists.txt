cmake_minimum_required(VERSION 3.16)
project(HeartAttackDiagnostic VERSION 2.0.0 LANGUAGES CXX)

# ── Require C++17 ────────────────────────────────────────────────────────────
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ── Compiler warnings ────────────────────────────────────────────────────────
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ── Executable ───────────────────────────────────────────────────────────────
add_executable(heart_diagnostic heart_attack_diagnostic.cpp)

# ── Threading (needed for std::this_thread on some platforms) ────────────────
find_package(Threads REQUIRED)
target_link_libraries(heart_diagnostic PRIVATE Threads::Threads)

# ── Install ──────────────────────────────────────────────────────────────────
install(TARGETS heart_diagnostic DESTINATION bin)
