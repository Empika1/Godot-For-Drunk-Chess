/* register_types.cpp */

#include "register_types.h"

#include "core/object/class_db.h"
#include "binding.h"
#include "error.h"

void initialize_drunk_chess_logic_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	ClassDB::register_class<Point>();
    ClassDB::register_class<DCError>();
}

void uninitialize_drunk_chess_logic_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
   // Nothing to do here in this example.
}