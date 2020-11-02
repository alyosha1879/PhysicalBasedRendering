//
// Created by okn-yu on 2020/10/30.
//

#ifndef PATHTRACING_RAY_H
#define PATHTRACING_RAY_H

#include <istream>
#include "vec3.h"

class Ray {
public:
    Vec3 origin;
    Vec3 direction;
    double tmin = 0.001;

    Ray(const Vec3&  _origin, const Vec3& _direction)
    : origin(_origin), direction(_direction){};

    Vec3 operator()(double t) const{
        return origin + t * direction;
    };

};

std::ostream& operator << (std::ostream& stream, const Ray& ray){
    stream << "origin: " << ray.origin << " direction: " << ray.direction;
    return stream;
}


#endif //PATHTRACING_RAY_H
