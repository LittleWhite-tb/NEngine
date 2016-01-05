cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)

project(NEngine)

SET(CMAKE_CXX_WARNING_LEVEL 4)
if (MSVC)
        add_definitions("/W4")
else()
        add_definitions("-Wall -Wextra")
endif ()

include_directories(src/)

set(NEngine_sources

	src/Bank.cpp
        src/Image.cpp
        src/IImageLoader.cpp
        src/ImageFactory.cpp
        src/ImageLoader.cpp
        src/InputManager.cpp
	src/ISoundLoader.cpp
	src/NEngine.cpp
	src/NEngineFactory.cpp
	src/Renderer.cpp
	src/SoundEngine.cpp
	src/SoundLoader.cpp
        src/Sprite.cpp
	
	src/Types/Colour.cpp
	
	src/Native/SDL/SDL_Engine.cpp
        src/Native/SDL/SDL_Image.cpp
        src/Native/SDL/SDL_ImageFactory.cpp
        src/Native/SDL/SDL_ImageLoader.cpp
        src/Native/SDL/SDL_ImageLoaderSDLI.cpp
        src/Native/SDL/SDL_Joy.cpp
	src/Native/SDL/SDL_Keyboard.cpp
	src/Native/SDL/SDL_NThread.cpp
	src/Native/SDL/SDL_Renderer.cpp
	src/Native/SDL/SDL_Semaphore.cpp
	src/Native/SDL/SDL_Sound.cpp
	src/Native/SDL/SDL_SoundEngine.cpp
	src/Native/SDL/SDL_SoundLoader.cpp
	src/Native/SDL/SDL_Time.cpp
	src/Native/SDL/SDL_Window.cpp
)

add_library(
    NEngine
    ${NEngine_sources}
)

# Finding libraries
find_package (SDL QUIET)
if (NOT SDL_FOUND)
  message(STATUS "Manual SDL configuration")
  set(SDL_INCLUDE_DIR "./deps/SDL-1.2.bin/include" "./deps/SDL-1.2.bin/include/SDL")
  if (WIN32)
	set(SDL_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/deps/SDL-1.2.bin/lib/SDL.lib" "${CMAKE_CURRENT_SOURCE_DIR}/deps/SDL-1.2.bin/lib/SDLmain.lib")
  else()
    message(FATAL_ERROR "SDL not found")
  endif()
endif()
include_directories(${SDL_INCLUDE_DIR})
target_link_libraries (NEngine ${SDL_LIBRARY})

find_package (SDL_image QUIET)
if (NOT SDLIMAGE_FOUND)
  message(STATUS "Manual SDL-image configuration")
  set(SDLIMAGE_INCLUDE_DIR "./deps/SDL-image.bin/include")
  if (WIN32)
        set(SDLIMAGE_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/deps/SDL-image.bin/lib/SDL_image.lib")
  else()
    message(FATAL_ERROR "SDL-image not found")
  endif()
endif()
include_directories(${SDLIMAGE_INCLUDE_DIR})
target_link_libraries (NEngine ${SDLIMAGE_LIBRARY})

target_include_directories(NEngine PUBLIC include/)

