#define MAX_SIZE_X 10
#define MAX_SIZE_Y 10

/**
 * Determination of operation system
 * Fully supported supported only GNU GCC/G++, partially on Clang/LLVM
 */
#if defined(_WIN32)
    #define PLATFORM_NAME_USED "windows" // Windows	
#elif defined(unix)
    #define PLATFORM_NAME_USED "unix" // unix
#else
    #define PLATFORM_NAME_USED NULL
#endif