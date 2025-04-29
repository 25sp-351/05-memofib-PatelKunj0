#ifndef CACHE_H
#define CACHE_H

typedef long long (*cached_fn_t)(int);


void cache_init(cached_fn_t fn, int max_n);

long long cache_call(int n);

void cache_free();

#endif 