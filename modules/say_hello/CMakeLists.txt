# Check if SAY_HELLO is set in Kconfig
if (CONFIG_SAY_HELLO)
    
    # Add your source file directory
    zephyr_include_directories(.)

    # Add your source files you want to compile 
    zephyr_library_sources(say_hello.c)
    
endif()