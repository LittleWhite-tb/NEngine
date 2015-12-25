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

#include "NEngine/ImageFactory.h"

#include "NEngine/Image.h"

#include "NEngine/NEngine.h"

NE::ImageFactory :: ~ImageFactory(void)
{
    for( std::map<std::pair<USize2, Colour>, NE::Image*>::const_iterator itImage = imagesBank.begin() ; itImage != imagesBank.end() ; ++itImage )
	{
        delete (itImage->second);
	}
    imagesBank.clear();
}

NE::Image* NE::ImageFactory::createImageFromColour(const Colour& colour, const USize2& ImageSize)
{
    std::pair<USize2, Colour> requiredPair(ImageSize,colour);
    if ( imagesBank.find(requiredPair) == imagesBank.end() ) // Not found
    {
        Image* pImage = createImage(colour,ImageSize);
        if ( pImage == NULL )
        {
            NEError << "NE::ImageFactory (Fail to create the Image " << colour << "\n";
            return NULL;
        }

        imagesBank[requiredPair] = pImage;
        return pImage;
    }
    else
    {
        return imagesBank[requiredPair];
    }
}

bool operator< (const std::pair<USize2, Colour>& p1, const std::pair<USize2, Colour>& p2)
{
    if ( p1.second < p2.second && p1.first < p2.first )
    {
        return true;
    }
    return false;
}
