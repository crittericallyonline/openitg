#include "global.h"
#include "RageSurface.h"
#include "RageSurfaceUtils.h"
#include "RageSurface_Save_JPEG.h"

#include "RageUtil.h"
#include "RageFile.h"


#include <emscripten/emscripten.h>

#undef FAR /* fix for VC */
namespace jpeg
{
	extern "C"
	{
	}
}

bool RageSurfaceUtils::SaveJPEG( RageSurface *surface, RageFile &f, bool bHighQual ) {
	RageSurface *dst_surface;
	if( RageSurfaceUtils::ConvertSurface( surface, dst_surface,
		surface->w, surface->h, 24, Swap24BE(0xFF0000), Swap24BE(0x00FF00), Swap24BE(0x0000FF), 0 ) )
		surface = dst_surface;
	int res = EM_ASM_INT({
		try
		{
			let iwidth = HEAPU32[$1>>2];
			let iheight = HEAPU32[$2>>2];
			let iBPP = HEAPU32[$3>>2];
			const jpegSize = iwidth * iheight * iBPP;
			let pixels = new Uint8ClampedArray(iwidth * iheight * 4);
			let pixelbuffer = new Uint8ClampedArray(HEAPU8.buffer);
			pixels.fill(255);
			for(let i=0; i < jpegSize; i+=4){
				pixels.set(HEAPU8.slice(($0 + i) - Math.floor(i/4), ($0 + i) - Math.floor(i/4) + 3), i); // R
			};
			const img = new ImageData(pixels, iwidth, iheight);
			
			let canv = document.createElement('canvas');
			canv.width = iwidth;
			canv.height = iheight;
			let ctx = canv.getContext('2d');
			ctx.putImageData(imageData, 0, 0);

			let a = document.createElement('a');
			a.setAttribute('download', new Date().toDateString().replaceAll(' ', '-') + '.jpeg');
			a.href = canv.toDataURL('image/jpeg');
			a.style.display = 'none';
			a.click();
			a.remove();
			return true;
		}
		catch(e)
		{
			console.error("Failed to save screenshot.\n" + e.message);
			return false;
		}
		
	}, dst_surface->pixels, dst_surface->w, dst_surface->h, 3 /* bytes per pixel (RGB) = 3 */);
	delete dst_surface;
	return (res == 1);
}

/*
 * (c) 2004 Chris Danford
 * All rights reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, and/or sell copies of the Software, and to permit persons to
 * whom the Software is furnished to do so, provided that the above
 * copyright notice(s) and this permission notice appear in all copies of
 * the Software and that both the above copyright notice(s) and this
 * permission notice appear in supporting documentation.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF
 * THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS
 * INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
