#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

typedef struct rectangle_t {
    int x, y, width, height;
} rectangle;

rectangle intersection(rectangle r1, rectangle r2) {
    rectangle r;
    r.x = max(r1.x, r2.x);
    r.y = max(r1.y, r2.y);
    r.width = min(r1.width, r2.width);
    r.height = min(r1.height, r2.height);
    return r;
}

rectangle canonicalize(rectangle r) {
    rectangle r_new;
    r_new.x = r.x;
    r_new.y = r.y;
    r_new.width = r.width;
    r_new.height = r.height;
    if (r.width < 0) {
        r_new.x += r.width;
        r_new.width = -r.width;
    }
    if (r.height < 0) {
        r_new.y += r.height;
        r_new.height = -r.height;
    }
    return r_new;
}
