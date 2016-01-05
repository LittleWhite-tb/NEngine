#ifndef __NE_IMAGE_H__
#define __NE_IMAGE_H__

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

#include "NEngine/Types/Size2.h"
#include "NEngine/Types/Colour.h"

#include "NEngine/Bank.h"

namespace NE
{
    class Image
    {
    protected:
        Colour m_transparencyColour;


        virtual void* getNativeImage(void)const=0;

        virtual ~Image(void) {}

        virtual void updateTransparencyColour()const;

    public:
        Image(void) {}

        virtual USize2 getSize(void)const=0;

        void setTransparencyColour(const Colour& colour);
        const Colour& getTransparencyColour()const { return m_transparencyColour; }

        friend class Renderer;

        // To have only the image loader able to delete a Image
        friend class Bank<const Image>;
        friend class ImageFactory;
    };
}

/*! \class NE::Image Image.h "NEngine/Image.h"
 *  \brief Image interface
 *
 * The Image class gives an interface to implement new platform specific Image functions.
 * An image is an array of pixels than can be load through disk using ImageLoader, or even
 * created on the fly through ImageFactory.
 */

/*! \fn NE::Image::Image(void)
 */

/*! \fn virtual NE::Image::~Image(void)
 */

/*! \fn virtual void* NE::Image::getNativeImage(void)const = 0;
 *  \brief return a pointer to the native image handle
 *  \return a pointer to the native image handler
 *  The use of a void* is done to avoid specific code
 */

/*! \fn virtual USize2 NE::Image::getSize(void)const=0
 * \brief Get the size of the Image
 * \return the size of the Image
 */

#endif
