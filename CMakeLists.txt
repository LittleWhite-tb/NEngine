cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)

project(NEngine)

SET(CMAKE_CXX_WARNING_LEVEL 4)
if (DEFINED MSYS)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif ()

if (DEFINED CMAKE_COMPILER_IS_GNUCC OR DEFINED CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif ()

include_directories(include/)
include_directories(src/)

set(NEngine_sources

	src/Bank.cpp
	src/InputManager.cpp
	src/ISoundLoader.cpp
	src/ISpriteLoader.cpp
	src/NEngine.cpp
	src/NEngineFactory.cpp
	src/Renderer.cpp
	src/SoundEngine.cpp
	src/SoundLoader.cpp
	src/SpriteFactory.cpp
	src/SpriteLoader.cpp
	
	src/Types/Colour.cpp
	
	src/Native/SDL/SDL_Engine.cpp
	src/Native/SDL/SDL_Joy.cpp
	src/Native/SDL/SDL_Keyboard.cpp
	src/Native/SDL/SDL_NThread.cpp
	src/Native/SDL/SDL_Renderer.cpp
	src/Native/SDL/SDL_Semaphore.cpp
	src/Native/SDL/SDL_Sound.cpp
	src/Native/SDL/SDL_SoundEngine.cpp
	src/Native/SDL/SDL_SoundLoader.cpp
	src/Native/SDL/SDL_Sprite.cpp
	src/Native/SDL/SDL_SpriteFactory.cpp
	src/Native/SDL/SDL_SpriteLoader.cpp
	src/Native/SDL/SDL_SpriteLoaderSDLI.cpp
	src/Native/SDL/SDL_Time.cpp
	src/Native/SDL/SDL_Window.cpp
)

add_library(
    NEngine
	SHARED
	${NEngine_sources}
)

add_library(
    NEngine-static
	STATIC
	${NEngine_sources}
)
# Since the static compilation will have same root name, with have to do some "hacky" thing
# This is coming from CMake FAQ
SET_TARGET_PROPERTIES(NEngine-static PROPERTIES OUTPUT_NAME "NEngine")
# Now the library target "foo-static" will be named "foo.lib" with MS tools.
# This conflicts with the "foo.lib" import library corresponding to "foo.dll",
# so we add a "lib" prefix (which is default on other platforms anyway):
SET_TARGET_PROPERTIES(NEngine-static PROPERTIES PREFIX "lib")

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

install(DIRECTORY ./include/NEngine/
        DESTINATION include/NEngine )

install(TARGETS NEngine NEngine-static
		ARCHIVE DESTINATION lib/
        LIBRARY DESTINATION lib/ )
