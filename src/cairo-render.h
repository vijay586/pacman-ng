#ifndef __CAIRO_RENDER
#define __CAIRO_RENDER

#include <cairo.h>

cairo_t *cairo_create_context (int iWidth, int iHeight, int iChannels, cairo_surface_t *pSurface, unsigned char **pucBuffer);

#endif
