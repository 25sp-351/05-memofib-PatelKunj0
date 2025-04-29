#include "cache.h"
#include <stdlib.h>
#include <limits.h>


static cached_fn_t fn_ptr;
static long long *cache_arr;
static int cache_size;


void cache_init(cached_fn_t fn, int max_n) {
    fn_ptr = fn;
    cache_size = max_n + 1;
    
    cache_arr = malloc(sizeof(long long) * cache_size);
    for (int i = 0; i < cache_size; ++i) {
        cache_arr[i] = LLONG_MIN;
    }
}

long long cache_call(int num) {

    if (num < 0 || num >= cache_size) {
        return fn_ptr(num);
    }

    if (cache_arr[num] != LLONG_MIN) {
        return cache_arr[num];
    }

    long long result = fn_ptr(num);
    cache_arr[num] = result;

    return result;
}

void cache_free() {
    free(cache_arr);
}
