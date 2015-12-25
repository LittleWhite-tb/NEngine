#ifndef __NE_SPRITE_H__
#define __NE_SPRITE_H__

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

#include "NEngine/Types/Vec2.h"
#include "NEngine/Types/Size2.h"

#include "NEngine/Image.h"

namespace NE
{
    class Renderer;

    class Sprite
    {
    private:
        const Image* pImage;
        IVec2 orig;
        USize2 size;

    public:
        Sprite(const Image* pImage)
            :pImage(pImage),orig(0,0),size(pImage->getSize()) {}
        Sprite(const Image* pImage, const IVec2& origine, const USize2& size)
            :pImage(pImage),orig(origine),size(size) {}
        ~Sprite() {}

        const IVec2& origine()const { return orig; }
        const USize2& getSize()const { return size; }

        bool draw(const NE::Renderer& r, const IVec2& position);
        bool draw(const NE::Renderer& r, const IVec2& position, const Colour& mask);
    };
}

#endif
