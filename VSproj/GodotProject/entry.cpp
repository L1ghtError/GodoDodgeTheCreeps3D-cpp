// Be sure to download the Godot C++ bindings!
// https://github.com/godotengine/godot-cpp
// In actual projects, consider adding this as a Git submodule.
#include <Godot.hpp>
#include "ScoreLabel.h"
#include "Player.h"
#include "Mob.h"
#include "Main.h"
extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options * o) {
	godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options * o) {
	godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void* handle) {
	godot::Godot::nativescript_init(handle);
	
	
	godot::register_class<Player>();
	godot::register_class<Mob>();
	godot::register_class<Main>();
	godot::register_class<ScoreLabel>();
}

