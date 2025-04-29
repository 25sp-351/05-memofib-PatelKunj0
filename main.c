#include <stdio.h>
#include "fib_raw.h"
#include "cache.h"
#include "fib.h"

const int MAX_N = 91;

int main(void) {
    cache_init(fib_raw, MAX_N);

    for (int ii = 0; ii <= 20; ++ii) {
        printf("%lld\n", fib(ii));
    }

    cache_free();
    return 0;
}
