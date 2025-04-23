//add
#ifdef SMART_SLOT_INFO
	PyModule_AddIntConstant(poModule, "SMART_SLOT_INFO", 1);
#else
	PyModule_AddIntConstant(poModule, "SMART_SLOT_INFO", 0);
#endif