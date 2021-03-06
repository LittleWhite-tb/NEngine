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

#include "SDL_Image.h"

#include <SDL/SDL.h>

NE::SDL_Image::SDL_Image(SDL_Surface* pImage)
    :Image(),pSurface(pImage)
{
}

NE::SDL_Image::~SDL_Image(void)
{
	SDL_FreeSurface(this->pSurface);
}

USize2 NE::SDL_Image::getSize(void)const
{
    return USize2(pSurface->w,pSurface->h);
}

void NE::SDL_Image::updateTransparencyColour()const
{
    // We set the color
    Uint32 colorkey = SDL_MapRGB(pSurface->format, m_transparencyColour.r, m_transparencyColour.g, m_transparencyColour.b);
    if ( SDL_SetColorKey(pSurface, SDL_SRCCOLORKEY, colorkey ) == -1 )
    {
        NEWarning << "Fail to set transparency colour !'\n";
    }
}
