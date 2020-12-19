#ifndef _ZG_HEAP_H
#define _ZG_HEAP_H

#include "stdint.h"
#include "stdlib.h"


// #define USE_CUSTOMIZE_HEAP  //使用自定义的内存管理算法
#ifdef USE_CUSTOMIZE_HEAP
#else

#define zg_Malloc   malloc
#define zg_Free     free

#endif



#endif
