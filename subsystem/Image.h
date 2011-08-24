/**
 * @file Image.h
 * Contains the Image subsystem class.
 *
 * Copyright (C) 2011 Thomas P. Lahoda
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
#ifndef SDL_SUBSYSTEM_IMAGE_H
#define SDL_SUBSYSTEM_IMAGE_H

#include <stdexcept>

#include <SDL_image.h>

namespace sdl {
namespace subsystem {
    /**
     * @struct Image
     * @brief Represents the image subsystem.
     */
    struct Image {
        /**
         * Returns an instance of the Image subsystem.
         *
         * @return A reference to the Image subsystem.
         */
        static Image& instance () {
            static Image instance_;
            return instance_;
        };

        protected:
            /**
             * Opens the Image subsystem.
             */
            void open (int flags) { 
                if (IMG_Init (flags) == -1) 
                    throw runtime_error (IMG_GetError ());
            };

            /**
             * Closes the Image subsystem.
             */
            void close () { quit (); };

        private:
            /**
             * Quits the Image subsystem.
             */
            void quit () { IMG_Quit (); };

            /**
             * Constructs the Image subsystem.
             */
            Image () {};

            /**
             * Destroys the Image subsystem.
             */
            ~Image () { quit (); };
    }; //Image
}; //subsystem
}; //sdl

#endif //SDL_SUBSYSTEM_IMAGE_H

