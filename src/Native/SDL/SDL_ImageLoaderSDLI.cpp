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

#include "SDL_ImageLoaderSDLI.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <string>

#include "SDL_Image.h"

#include "NEngine/Exceptions/ConstructionFailedException.h"
#include "NEngine/NEngine.h"

NE :: SDL_ImageLoaderSDLI :: SDL_ImageLoaderSDLI(const int flags)
{
    int initIMG = IMG_Init(flags);

    // Starting SDL_image
    if ( (initIMG & flags) != flags )
    {
        NEError << "Fail to init the SDL_image with PNG support (" << IMG_GetError() << ")\n";
        throw ConstructionFailedException("SDL_ImageLoaderSDLI");
    }
}

NE :: SDL_ImageLoaderSDLI :: ~SDL_ImageLoaderSDLI(void)
{
    IMG_Quit();
}

NE :: Image* NE :: SDL_ImageLoaderSDLI :: loadImageFromFile(const std::string& fileName, const Colour& transparencyColour)
{
    (void)transparencyColour;

    SDL_Surface* pSurface = IMG_Load(fileName.c_str());

    // No optimisation is possible for these kind of surface

    if ( pSurface != NULL )
    {
        NE::SDL_Image* pImage = new NE::SDL_Image(pSurface);
        if ( pImage == NULL )
        {
            NEError << "Fail to allocate memory for a SDL_Image\n";
        }

        return pImage;
    }

    // LError << "Fail to load a Image from file: " << IMG_GetError();
    return NULL;
}
