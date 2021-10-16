#define MAX_SIZE_X 10
#define MAX_SIZE_Y 10


/**
 * Determination of operation system
 * Fully supported supported only GNU GCC/G++, partially on Clang/LLVM
 */
#define PLATFORM_NAME_WINDOWS 0

#if defined(_WIN32)
    #define PLATFORM_NAME_USED 0 // Windows
	
#elif defined(unix)
    #define PLATFORM_NAME_USED 1 // unix
#else
    #define PLATFORM_NAME_USED NULL
#endif
