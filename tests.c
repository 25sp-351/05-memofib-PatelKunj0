#include <assert.h>
#include <stdio.h>
#include "fib_raw.h"
#include "cache.h"
#include "fib.h"

const int MAX_N = 91;

int main(void) {
    cache_init(fib_raw, MAX_N);

    assert(fib(0) == 0);
    assert(fib(1) == 1);
    assert(fib(2) == 1);
    assert(fib(10) == 55);
    assert(fib(20) == 6765);


    long long prev = fib(0);
    
    for (int i = 1; i <= MAX_N; ++i) {
        long long curr = fib(i);
        assert(curr >= prev);
        prev = curr;
    }

    cache_free();
    printf("Passed\n");
    return 0;
}
