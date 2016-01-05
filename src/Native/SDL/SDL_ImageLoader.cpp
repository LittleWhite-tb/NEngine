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

#include "SDL_ImageLoader.h"

#include <SDL/SDL.h>

#include <string>

#include "NEngine/NEngine.h"
#include "SDL_Image.h"

NE::Image* NE::SDL_ImageLoader :: loadImageFromFile(const std::string& fileName)
{
    SDL_Surface* pSurface = SDL_LoadBMP(fileName.c_str());
    if ( pSurface != NULL )
    {
        // We optimise the texture to match the Screen surface
        SDL_Surface* pOptimisedSurface = SDL_DisplayFormat(pSurface);
        if ( pOptimisedSurface != NULL )
        {
            // We clean old surface
            SDL_FreeSurface(pSurface);

            // We replace the pointer to the new optimised surface
            pSurface = pOptimisedSurface;
        }
        else
        {
            NEError << "Fail to optimise Image '" << fileName << "'\n";
        }

        NE::SDL_Image* pImage = new NE::SDL_Image(pSurface);
        if ( pImage == NULL )
        {
            NEError << "Fail to allocate memory for a SDL_Image\n";
        }

        return pImage;
    }

    // NEError << "Fail to load a Image from file: " << SDL_GetError() << "\n";
    return NULL;
}
