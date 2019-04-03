#if __linux__
#	include "font.addon.h"
#	include "led-matrix.addon.h"
#	include <napi.h>

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	LedMatrixAddon::Init(env, exports);
	FontAddon::Init(env, exports);
	return exports;
}

NODE_API_MODULE(rpi_led_matrix, Init)
#else
#	pragma GCC diagnostic ignored "-Wunused-private-field"
#	pragma GCC diagnostic ignored "-Wunused-variable"
#	ifdef __GNUC__
#		warning "Local machine is not a Raspberry Pi; skipping compilation of full addon module."
#	elif
#		pragma message("Local machine is not a Raspberry Pi; skipping compilation of full addon module.")
#	endif

#	include <napi.h>

Napi::Value Throw(const Napi::CallbackInfo& info) {
	throw Napi::Error::New(info.Env(), "Can't instantiate the LED Matrix addon because this isn't a Raspberry Pi.");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	exports.Set("LedMatrix", Napi::Function::New(env, Throw));
	exports.Set("Font", Napi::Function::New(env, Throw));
	return exports;
}

NODE_API_MODULE(rpi_led_matrix, Init)

#endif