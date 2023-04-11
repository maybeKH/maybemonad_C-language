#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int is_null;
    void* value;
} Maybe;

Maybe* just(void* value) {
    Maybe* maybe = malloc(sizeof(Maybe));
    maybe->is_null = 0;
    maybe->value = value;
    return maybe;
}

Maybe* nothing(void* value) {
    Maybe* maybe = malloc(sizeof(Maybe));
    maybe->is_null = 1;
    maybe->value = value;
    return maybe;
}

Maybe* bind(Maybe* maybe, Maybe* (*f)(void*)) {
    if (maybe->is_null) {
        return nothing(NULL);
    } else {
        return f(maybe->value);
    }
}

Maybe* ret(void* value) {
    return just(value);
}

char* from_just(Maybe* maybe) {
    if (maybe->is_null) {
        return maybe->value;
    } else {
        return maybe->value;
    }
}

int main(void) {
    Maybe* maybe1 = just("Hello");
    Maybe* maybe2 = nothing(NULL);

    Maybe* maybe3 = bind(maybe1, ret);
    Maybe* maybe4 = bind(maybe2, ret);

     printf("%s\n",from_just(maybe3));
     printf("%s\n",from_just(maybe4));

    return 0;
}


