#pragma once

/*
 * whenever we need to include an SDL library we use this file. This way we can
 * make the program portable as paths might be different depending on the
 * environment we use.
 */

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_net.h>
#include <SDL_ttf.h>

// the RECT macro is used to automatically cast the argument to integer (since
// in GameObject the dimension, position, etc., are of type double
#define RECT(x, y, w, h)                                           \
  {                                                                \
    static_cast<int>(x), static_cast<int>(y), static_cast<int>(w), \
        static_cast<int>(h)                                        \
  }

// the COLOREXP macro is used to expand an SDL_Color variable into its
// components, so instead of writing
//
//    SDL_SetRenderDrawColor(game_->getRenderer(), color.r, color.g, color.b,
//    color.a);
//
// we can simply write
//
// SDL_SetRenderDrawColor(game_->getRenderer(), COLOREXP(color));
#define COLOREXP(color) color.r, color.g, color.b, color.a

// Write colors in an easy way in hex, e.g., 0xaaff12ff. Instead of writing
//
//   { 0x44, 0x11, 0x22, 0x33 }
//
// simply write {COLOR(0x44112233)}
//
#define COLOR(num) \
  (num >> 24) & 0xff, (num >> 16) & 0xff, (num >> 8) & 0xff, num & 0xff
