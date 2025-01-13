cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DXYZENGINE_EXPORTS)

add_library (XYZEngine SHARED
#Cycle-made classes
"src/Game.cpp"
"src/GameWorld.cpp"

#Component system core
"src/GameObject.cpp" 
"src/Component.cpp"
"src/TransformComponent.cpp"

#Systems
"src/RenderSystem.cpp"
"src/ResourceSystem.cpp"
"src/PhysicsSystem.cpp"

#Internal components
"src/ColliderComponent.cpp" 
"src/SpriteColliderComponent.cpp"
"src/RigidbodyComponent.cpp"
"src/SpriteRendererComponent.cpp"
"src/CameraComponent.cpp"
"src/AudioComponent.cpp" 

#Sample components
"src/DestroySelfComponent.cpp"
"src/DelayActionComponent.cpp"
"src/FPSCountComponent.cpp"
"src/InputComponent.cpp"
"src/DummyComponent.cpp"
)

target_include_directories(XYZEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(XYZEngine sfml-graphics sfml-window sfml-system sfml-audio)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set_target_properties(XYZEngine PROPERTIES
    OUTPUT_NAME "XYZEngine"
    VERSION 1.0
    SOVERSION 1
)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(DLL_FILES
        "${CMAKE_SOURCE_DIR}/SFML/bin/sfml-system-2.dll"
        "${CMAKE_SOURCE_DIR}/SFML/bin/sfml-graphics-2.dll"
        "${CMAKE_SOURCE_DIR}/SFML/bin/sfml-window-2.dll"
        "${CMAKE_SOURCE_DIR}/SFML/bin/sfml-audio-2.dll"
    )
else()
    set(DLL_FILES
        "${CMAKE_SOURCE_DIR}/SFML/bin/sfml-system-d-2.dll"
        "${CMAKE_SOURCE_DIR}/SFML/bin/sfml-graphics-d-2.dll"
        "${CMAKE_SOURCE_DIR}/SFML/bin/sfml-window-d-2.dll"
        "${CMAKE_SOURCE_DIR}/SFML/bin/sfml-audio-d-2.dll"
    )
endif()
set(OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}")

set(INCLUDE_LIB_DIR "${CMAKE_SOURCE_DIR}/XYZEngine/include")
set(BUILD_INCLUDE_LIB_DIR "${OUTPUT_DIR}")
file(COPY ${INCLUDE_LIB_DIR} DESTINATION ${BUILD_INCLUDE_LIB_DIR})

foreach(DLL_PATH ${DLL_FILES})
    get_filename_component(DLL_NAME ${DLL_PATH} NAME)
    add_custom_command(TARGET XYZEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${DLL_PATH}"
        "${OUTPUT_DIR}/${DLL_NAME}"
    )
endforeach()