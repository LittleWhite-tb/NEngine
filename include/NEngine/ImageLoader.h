#ifndef NE_IMAGELOADER_H
#define NE_IMAGELOADER_H

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

#include <list>

#include "NEngine/Types/Colour.h"
#include "NEngine/Loader.h"
#include "NEngine/IImageLoader.h"

#include "Bank.h"

namespace NE
{
    class IImageLoader;
    class Image;

    typedef Bank<const Image> ImageBank;

    class ImageLoader : public Loader<NE::IImageLoader>
    {
    public:
        const Image* loadImageFromFile(const std::string& fileName, const Colour& transparencyColour, ImageBank& bank);
    };
}

/*! \class NE::ImageLoader ImageLoader.h "NEngine/ImageLoader.h"
 *  \brief ImageLoader interface
 *
 * The ImageLoader class gives an interface to implement new platform specific Image loading functions.
 * To save loading time, the loader is using a bank to keep the Image already loaded. The second advantage of this, is that the memory deallocation has not to be done by the user.
 */

/*! \fn const Image* NE::ImageLoader::loadImageFromFile(const std::string& fileName, const Colour& transparencyColour, ImageBank& bank)=0
 * \brief load a Image from a file, or return the corresponding Image if already loaded
 * \param fileName the name of the file to load
 * \param transparencyColour the transparency colour to apply on the loaded image
 * \param bank the bank where to put the \a Image
 * \return a pointer to the newly loaded \a Image
*/

#endif
