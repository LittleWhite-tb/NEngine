#ifndef DOXYGEN_IGNORE_TAG
/**
NEngine: Native Engine abstracts multimedia libraries such as SDL, SFML, Allegro
Copyright (C) 2010-2015  Alexandre LAURENT

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

website: https://github.com/LittleWhite-tb/NEngine
e-mail: lw.demoscene@gmail.com
**/
#endif

#include "SDL_Engine.h"

#include <SDL/SDL.h>

#include "SDL_Window.h"
#include "SDL_Renderer.h"
#include "SDL_Keyboard.h"
#include "SDL_Joy.h"
#include "SDL_Time.h"
#include "SDL_Image.h"
#include "SDL_ImageLoader.h"
#include "SDL_ImageLoaderSDLI.h"
#include "SDL_ImageFactory.h"
#include "SDL_SoundLoader.h"
#include "SDL_SoundEngine.h"

#include "NEngine/Exceptions/InputNotFoundException.h"
#include "NEngine/Exceptions/ConstructionFailedException.h"
#include "NEngine/NEngine.h"
#include "NEngine/ImageLoader.h"
#include "NEngine/SoundLoader.h"

bool NE :: SDL_Engine :: initAPI(void)
{
    if ( SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        NEError << "Error while initializing SDL -> SDL_INIT_VIDEO\n";
        return false;
    }

    pWin = new NE::SDL_Window();
    pRenderer = new NE::SDL_Renderer(pWin);
    pTime = new NE::SDL_Time();

    pSoundEngine = new NE::SDL_SoundEngine(pSoundLoader);

    try
    {
        pImageLoader->registerLoader(new NE::SDL_ImageLoader());
        pImageLoader->registerLoader(new NE::SDL_ImageLoaderSDLI(SDL_ImageLoaderSDLI::PNG));

        pSoundLoader->registerLoader(new NE::SDL_SoundLoader());
    }
    catch ( ConstructionFailedException cfe )
    {
        NEError << cfe.what() << "\n";
        pImageLoader = NULL;
        pSoundEngine = NULL;
    }

    pImageFactory = new NE::SDL_ImageFactory();

    if ( pWin == NULL || pRenderer == NULL || pTime == NULL || pImageLoader == NULL || pImageFactory == NULL )
    {
        NEError << "Fail to allocate memory for SDL_Engine components\n";
        return false;
    }

    if ( pSoundLoader == NULL || pSoundEngine == NULL )
    {
		NEWarning << "Fail to start sound endine\n";
	}

    pInputManager->registerController(new SDL_Keyboard());

    SDL_Joy* pJoystick;
    try
    {
         pJoystick = new SDL_Joy();
    }
    catch  (InputNotFoundException& infe)
    {
        NEWarning << "No joystick found '" << infe.what() << "'\n";
        pJoystick = NULL;
    }

    if ( pJoystick != NULL )
    {
        pInputManager->registerController(pJoystick);
    }

    NEDebug << "Native Engine SDL started\n";
    return true;
}

bool NE :: SDL_Engine :: stopAPI(void)
{
	delete pSoundEngine; pSoundEngine = NULL;
    delete pSoundLoader; pSoundLoader = NULL;
    delete pImageFactory; pImageFactory = NULL;
    delete pImageLoader; pImageLoader = NULL;
    delete pTime; pTime = NULL;
    delete pRenderer; pRenderer = NULL;
    delete pWin; pWin = NULL;

    SDL_Quit();

    NEDebug << "Native Engine SDL stopped\n";

    return true;
}
