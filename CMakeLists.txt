cmake_minimum_required(VERSION 3.0.0)
project(Pong VERSION 0.1.0)

include(FetchContent)
set(BUILD_SHARED_LIBS  OFF)
FetchContent_Declare(
 SFML
 GIT_REPOSITORY https://github.com/SFML/SFML.git
 GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

include(CTest)
enable_testing()

add_executable(Pong
    src/main.cpp
    src/math/math.h src/math/math.cpp
    src/game/game.h src/game/game.cpp
    src/background/background.h src/background/background.cpp
    src/player/player.h src/player/player.cpp
    src/enemy/enemy.h src/enemy/enemy.cpp
    src/ball/ball.h src/ball/ball.cpp
)

target_link_libraries(Pong sfml-graphics)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
