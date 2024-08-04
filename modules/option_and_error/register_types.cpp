/* register_types.cpp */

#include "register_types.h"
#include "core/object/class_db.h"
#include "binding.h"

void initialize_option_and_error_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
    GDREGISTER_CLASS(OptionInt);
}

void uninitialize_option_and_error_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
   // Nothing to do here in this example.
}