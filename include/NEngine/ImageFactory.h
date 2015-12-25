#ifndef __IMAGEFACTORY_H__
#define __IMAGEFACTORY_H__

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

#include <map>

#include "NEngine/Types/Colour.h"
#include "NEngine/Types/Size2.h"

namespace NE
{
    class Image;

    class ImageFactory
    {
    private:

        std::map<std::pair<USize2, Colour>, Image*> imagesBank; /*<! Bank of Sprite already created */

    protected:

        virtual Image* createImage(const Colour& colour, const USize2& imageSize)=0;

    public:
        virtual ~ImageFactory(void);

        Image* createImageFromColour(const Colour& colour, const USize2& imageSize);
    };
}

bool operator< (const std::pair<USize2, Colour>& p1, const std::pair<USize2, Colour>& p2);

/*! \class NE::ImageFactory ImageFactory.h "NEngine/ImageFactory.h"
 *  \brief ImageFactory interface to create Images
 *
 * The ImageFactory creates Image from a colour and a size
 * This class use a bank of Image to not create to times the same sprite
 */

 /*! \fn virtual NE::Sprite* NE::ImageFactory::createImage(const Colour& colour, const USize2& imageSize)=0;
  * \brief Create a Image from a colour and a size
  * \param colour The colour of the Image
  * \param imageSize the size of the Image
  * \return the Image created.
  */

 /*! \fn NE::Sprite* NE::ImageFactory::createImageFromColour(const Colour& colour, const USize2& imageSize);
  * \brief Create a Image from a colour and a size
  * \param colour The colour of the Image
  * \param imageSize the size of the Image
  * \return the Image created.
  */

#endif
