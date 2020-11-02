//
// Created by okn-yu on 2020/11/01.
//

#ifndef PATHTRACING_LIGHT_H
#define PATHTRACING_LIGHT_H

#include "vec3.h"

class Light {
public:
    Vec3 color;

    Light(const Vec3 &_color) : color(_color) {};

    Vec3 Le() const {
        return color;
    }
};

#endif //PATHTRACING_LIGHT_H
