#include "font.addon.h"
#include "node-led-matrix.h"
#include <napi.h>

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	NodeLedMatrix::Init(env, exports);
	FontAddon::Init(env, exports);
	return exports;
}

NODE_API_MODULE(spi, Init)
