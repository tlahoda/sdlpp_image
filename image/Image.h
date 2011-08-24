/**
 * @file Image.h
 * Contains the Image class.
 *
 * Copyright (C) 2005 Thomas P. Lahoda
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
#ifndef SDL_IMAGE_IMAGE_H
#define SDL_IMAGE_IMAGE_H

#include <stdexcept>

#include <SDL.h>
#include <SDL_image.h>

#include "sdlpp/video/Surface.h"

namespace sdl {
namespace image {
    using namespace std;
    using namespace video;

    /**
     * @struct Image
     * @brief Represents an image.
     */
    struct Image {
        /**
         * Constructs an Image.
         *
         * @param file The name of the image file.
         */
        Image (const string& file) : file_ (file), surface_ (IMG_Load (file_.c_str ())) {
            if (surface_ == NULL)
                throw runtime_error ("Failed to load image " + fileName);
        };

        /**
         * Enable RLE acceleration.
         */
        void enableRLEAcceleration () { SDL_SetColorKey(surface_.to_c (), SDL_RLEACCEL, surface_.to_c ()->format->colorkey); };

        /**
         * Determines if the image is of the specified type.
         *
         * @tparam Comparator, The comparison function.
         *
         * @param fileName, The name of the image file.
         * @param comparator, The comparison function.
         *
         * @return True if is, false otherwise.
         */
        template<typename Comparator>
        static bool is (const string& fileName, Comparator comparator) {
            SDL_RWops* ops = SDL_RWFromFile (fileName.c_str (), "rb");
            if (ops == NULL)
                throw runtime_error ("Failed to open " + fileName);
            return comparator (ops) == 1;
        };

        private:
            /**
             * The name of the image file.
             */
            string file_;

            /**
             * The Surface containg the image.
             */
            Surface surface_;
    }; //Image
}; //image
}; //sdl

#endif //SDL_IMAGE_IMAGE_H

