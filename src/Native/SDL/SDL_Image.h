#ifndef __NE_SDL_IMAGE_H__
#define __NE_SDL_IMAGE_H__

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

#include "NEngine/Image.h"

#include "NEngine/Types/Vec2.h"
#include "NEngine/Types/Colour.h"

struct SDL_Surface;

namespace NE
{
    class SDL_Image : public Image
    {
    private:

        SDL_Surface* pSurface;

    protected:
         void* getNativeImage(void)const { return pSurface; }

        ~SDL_Image(void);

    public:
        SDL_Image(SDL_Surface* pImage);

        void updateTransparencyColour()const;

        USize2 getSize(void)const;
    };
}

/*! \class NE::SDL_Image SDL_Image.h "NEngine/Native/SDL/SDL_Image.h"
 *  \brief SDL implementation for Image
 */

/*! \fn NE::SDL_Image::SDL_Image(SDL_Surface* pImage)
 * \param pImage Native surface to use as Image
 */


#endif
