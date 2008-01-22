#include "cairo-render.h"

#include <stdlib.h>
#include <cairo.h>

cairo_t *cairo_create_context (int iWidth, int iHeight, int iChannels, cairo_surface_t *pSurface, unsigned char **pucBuffer)
{
	cairo_t* pCairoContext = NULL;
	*pucBuffer = calloc (iChannels * iWidth * iHeight, sizeof (unsigned char));
	*pSurface = cairo_image_surface_create_for_data (*pucBuffer, CAIRO_FORMAT_ARGB32, iWidth, iHeight, iChannels * iWidth);
}
