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
        Sprite()
            :pImage(NULL),orig(0,0),size(0,0) {}
        Sprite(const Image* pImage)
            :pImage(pImage),orig(0,0),size(pImage->getSize()) {}
        Sprite(const Image* pImage, const IVec2& origin, const USize2& size)
            :pImage(pImage),orig(origin),size(size) {}
        ~Sprite() {}

        const IVec2& origin()const { return orig; }
        const USize2& getSize()const { return size; }

        bool draw(const NE::Renderer& r, const IVec2& position)const;
        bool draw(const NE::Renderer& r, const IVec2& position, const Colour& mask)const;
    };
}

/*! \class NE::Sprite Sprite.h "NEngine/Sprite.h"
 *  \brief Sprite
 *
 * The Sprite class gives a way to get subpart of a \a Image to be rendered. Subpart
 * is defined with an origin and a size. This class just point a \a Image, but does not
 * contain it.
 */

/*! \fn NE::Sprite::Sprite(void)
 *  \brief Invalid Sprite
 *
 * Nothing can be done with it.
 */

/*! \fn NE::Sprite::Sprite(const Image* pImage)
 *  \brief Create \a Sprite from a full \a Image
 *  \param pImage the source \a Image
 */

/*! \fn NE::Sprite::Sprite(const Image* pImage, const IVec2& origin, const USize2& size)
 *  \brief Create \a Sprite from a subpart of a \a Image
 *  \param pImage the source \a Image
 *  \param origin the origin point for the subpart
 *  \param size the size of the \a Sprite
 */

/*! \fn virtual NE::Sprite::~Sprite(void)
 */

/*! \fn const IVec2& NE::Sprite::origin(void)const;
 *  \brief Get the origin point
 *  \return the origin point
 */

/*! \fn const USize2& NE::Sprite::getSize(void)const;
 *  \brief Get the size
 *  \return the size
 */

/*! \fn bool NE::Sprite::draw(const NE::Renderer& r, const IVec2& position)const;
 *  \brief Draw the \a Sprite
 *  \param r the \a Renderer used to draw
 *  \param position the position where to draw
 *  \bool true if everything goes well
 */

/*! \fn bool NE::Sprite::draw(const NE::Renderer& r, const IVec2& position, const Colour& mask)const;
 *  \brief Draw the \a Sprite
 *  \param r the \a Renderer used to draw
 *  \param position the position where to draw
 *  \param mask additional mask used when drawing
 *  \bool true if everything goes well
 */

#endif
