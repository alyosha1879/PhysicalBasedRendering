//
// Created by okn-yu on 2020/10/31.
//
#ifndef PATHTRACING_HIT_H
#define PATHTRACING_HIT_H

#include "vec3.h"

class Sphere;

class Hit {
public:
    double t;
    Vec3 hitPos;
    Vec3 hitNormal;
    const Sphere *hitSphere;

    Hit() {
        t = 10000;
    };
};

#endif //PATHTRACING_HIT_H
