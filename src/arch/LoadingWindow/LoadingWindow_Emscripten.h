#ifndef LOADING_WINDOW_EMSCRIPTEN_H
#define LOADING_WINDOW_EMSCRIPTEN_H

#include "LoadingWindow.h"

class LoadingWindow_Emscripten: public LoadingWindow {
public:
	LoadingWindow_Emscripten() { }
	~LoadingWindow_Emscripten() { }

	void SetText(CString str) { }
	void Paint() { }
};

#endif