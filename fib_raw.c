#include "fib_raw.h"
#include "cache.h"


long long fib_raw(int num) {
    if (num < 2) return num;
    
    return cache_call(num - 1) + cache_call(num - 2);
}
