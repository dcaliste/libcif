#pragma once

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct Vector3 {
    double x[3];
} Vector3;

static inline void v3_new(Vector3 *const v, double x, double y, double z) {
    v->x[0] = x;
    v->x[1] = y;
    v->x[2] = z;
}

static inline void v3_from_array(Vector3 *const v, double *x) {
    for (int i=0; i<3; i++) v->x[i] = x[i];
}

static inline Vector3 v3_sum(const Vector3 *const v1, const Vector3 *const v2) {
    Vector3 sum;
    for (int i=0; i<3; i++) sum.x[i] = v1->x[i] + v2->x[i];
    return sum;
}

static inline Vector3 v3_diff(const Vector3 *const v1, const Vector3 *const v2) {
    Vector3 diff;
    for (int i=0; i<3; i++) diff.x[i] = v1->x[i] - v2->x[i];
    return diff;
}

static inline double v3_dot(const Vector3 *const v) {
    double dot = 0.0;
    for (int i=0; i<3; i++) dot += pow(v->x[i],2);
    return dot;
}

static inline double v3_len(const Vector3 *const v) {
    return sqrt(v3_dot(v));
}

static inline bool v3_eq(const Vector3 *const v1, const Vector3 *const v2, double tol) {
    bool eq = true; 
    for (int i=0; i<3; i++) {
        eq = abs(v1->x[i] - v2->x[i]) < tol;
        if (!eq) break; 
    }
    return eq;
}
