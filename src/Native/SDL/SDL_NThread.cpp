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

#include "SDL_NThread.h"

#include <SDL/SDL_thread.h>

void NE :: SDL_NThread :: start(void)
{
    pThread = SDL_CreateThread(fct,data);
}

void NE :: SDL_NThread :: stop(void)
{
    if ( pThread != NULL )
    {
        SDL_KillThread(pThread);
        pThread = NULL;
    }
}

void NE :: SDL_NThread :: wait(void)
{
    SDL_WaitThread(pThread, NULL);
}
