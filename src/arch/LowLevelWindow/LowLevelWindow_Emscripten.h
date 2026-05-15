#ifndef LOW_LEVEL_WINDOW_EMSCRIPTEN_H
#define LOW_LEVEL_WINDOW_EMSCRIPTEN_H

#include "LowLevelWindow.h"


#include <emscripten/html5_webgl.h>

class LowLevelWindow_Emscripten: public LowLevelWindow
{
public:
	LowLevelWindow_Emscripten();
	~LowLevelWindow_Emscripten();
	void *GetProcAddress(CString s);
	CString TryVideoMode( RageDisplay::VideoModeParams p, bool &bNewDeviceOut );
	void SwapBuffers();
	void Update(float fDeltaTime);

	RageDisplay::VideoModeParams GetVideoModeParams() const { return CurrentParams; }

private:
	RageDisplay::VideoModeParams CurrentParams;
	EmscriptenWebGLContextAttributes Attrs;
	EMSCRIPTEN_WEBGL_CONTEXT_HANDLE Context;

	static EM_BOOL KeyboardEvent(int eventType, const EmscriptenKeyboardEvent *event, void *userData);
	static EM_BOOL ResizeEvent(int eventType, const EmscriptenUiEvent *event, void *userData);
};

#ifdef ARCH_LOW_LEVEL_WINDOW
#error "More than one LowLevelWindow selected!"
#endif
#define ARCH_LOW_LEVEL_WINDOW LowLevelWindow_Emscripten

#endif