cmake_minimum_required(VERSION 3.26)
project(Minecraft2D)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror=return-type -Werror=parentheses -Werror=vla -Werror=array-bounds -Wcast-qual -Wmaybe-uninitialized )

# Windows specific config
# To możecie zmienić jeśli zainstalujecie SFML-a w innym miejscu
IF (WIN32)
    # Include local sfml cmake config
    set(SFML_DIR "C:/lib/SFML-2.5.1/lib/cmake/SFML")
    # Link sfml statically (Optional)
    set(SFML_STATIC_LIBRARIES TRUE)
ENDIF()

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add source files from src and src/Blocks
file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/Blocks/*.cpp"
)

# Add the executable
#add_executable(${PROJECT_NAME} ${SOURCES})

add_executable(Minecraft2D
        "${PROJECT_SOURCE_DIR}/src/main.cpp"
        "${PROJECT_SOURCE_DIR}/src/GameFont.cpp"
        "${PROJECT_SOURCE_DIR}/src/Button.cpp"
        "${PROJECT_SOURCE_DIR}/src/Block.cpp"
        "${PROJECT_SOURCE_DIR}/src/Blocks/Chest.cpp"
        "${PROJECT_SOURCE_DIR}/src/Blocks/Crafting.cpp"
        "${PROJECT_SOURCE_DIR}/src/Blocks/Dirt.cpp"
        "${PROJECT_SOURCE_DIR}/src/Blocks/Grass.cpp"
        "${PROJECT_SOURCE_DIR}/src/Blocks/Leaves.cpp"
        "${PROJECT_SOURCE_DIR}/src/Blocks/Stone.cpp"
        "${PROJECT_SOURCE_DIR}/src/Blocks/Wood.cpp"
        "${PROJECT_SOURCE_DIR}/src/World.cpp"
        "${PROJECT_SOURCE_DIR}/src/Player.cpp"
        "${PROJECT_SOURCE_DIR}/src/Controller.cpp"
        "${PROJECT_SOURCE_DIR}/src/Equipment.cpp"
        "${PROJECT_SOURCE_DIR}/src/SFMLView.cpp"
        "${PROJECT_SOURCE_DIR}/src/SFMLCtrl.cpp")

# Set the working directory to the project's root directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# Copy assets to the binary directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)