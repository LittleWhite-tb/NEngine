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

#include "NEngine/ImageLoader.h"

#include "NEngine/NEngine.h"
#include "NEngine/IImageLoader.h"
#include "NEngine/Exceptions/FileNotFoundException.h"

#include <cassert>

const NE::Image* NE::ImageLoader::loadImageFromFile(const std::string& fileName, const Colour& transparencyColour, NE::ImageBank& bank)
{
    const NE::Image* pImage = bank.get(fileName);

    if ( pImage == NULL ) // It was not in the bank
    {
        for ( std::list<NE::IImageLoader*>::const_iterator itLoader = m_loaders.begin() ;
            itLoader != m_loaders.end() ;
            ++itLoader )
        {
            pImage = (*itLoader)->loadImageFromFile(fileName,transparencyColour);
            if ( pImage != NULL )  // It is loaded, we can stop
            {
                bank.add(fileName,pImage);
                break;
            }
        }

        // We gone through all loaders, and the Image is not loaded ... so, error
        if ( pImage == NULL )
        {
            NEError << "Fail to load Image '" << fileName << "'\n";
            throw FileNotFoundException(fileName);
        }
    }

    return pImage;
}
