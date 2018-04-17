/**
* @file mvdmconfig.h
*
* @brief The mvdmconfig header file.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <string>

#define SWIDTH 1920 ///< The screen width
#define SHEIGHT 1080 ///< The screen height

#define FULLSCREEN 0 ///< Fullscreen (0=off, 1=on)

#define WINDOWNAME "MvdM" ///< The name of the window

#define CLEARCOLOR_RED 0.1f ///< The red component of the color of the window
#define CLEARCOLOR_GREEN 0.1f ///< The green component of the color of the window
#define CLEARCOLOR_BLUE 0.1f ///< The blue component of the color of the window

#define VSYNC 0 ///< vsync (0=off, 1=on)

#endif /* CONFIG_H */