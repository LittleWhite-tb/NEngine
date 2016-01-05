#ifndef __NE_IIMAGELOADER_H__
#define __NE_IIMAGELOADER_H__

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
#include <string>

#include "NEngine/Types/Colour.h"

namespace NE
{
    class Image;

    class IImageLoader
    {
    public:
        virtual ~IImageLoader(void) {}

        virtual Image* loadImageFromFile(const std::string& fileName)=0;
    };
}

/*! \class NE::ImageLoader ImageLoader.h "NEngine/ImageLoader.h"
 *  \brief ImageLoader interface
 *
 * The ImageLoader class gives an interface to implement new platform specific Image loading functions.
 * To save loading time, the loader is using a bank to keep the Image already loaded. The second advantage of this, is that the memory deallocation has not to be done by the user.
 */

/*! \fn virtual Image* NE::ImageLoader::loadImage(const std::string& fileName)=0
 * \brief load a Image from a file
 * \param fileName the name of the file to load
 * \return a pointer to the newly loaded Image
*/

/*! \fn virtual NE::ImageLoader::~ImageLoader(void)
 */

/*! \fn virtual Image* NE::ImageLoader::loadImageFromFile(const std::string& fileName)=0
 * \brief load a Image from a file, or return the corresponding Image if already loaded
 * \param fileName the name of the file to load
 * \return a pointer to the newly loaded Image
*/

#endif
