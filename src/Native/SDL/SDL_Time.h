#ifndef __NE_SDL_TIME_H__
#define __NE_SDL_TIME_H__

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

#include "NEngine/Time.h"

namespace NE
{
    class SDL_Time : public Time
    {
    public:
        SDL_Time(void):Time() {}
        ~SDL_Time(void) {}

        unsigned int getTime(void);
        void delay(unsigned int msSec);
    };
}

/*! \class NE::SDL_Time SDL_Time.h "NEngine/Native/SDL/SDL_Time.h"
 *  \brief SDL Time implementation
 *
 * Get the time using SDL_GetTicks() in milli seconds
 * The delay using SDL_Delay() have a precision of 10ms
 */

#endif
