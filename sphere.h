//
// Created by okn-yu on 2020/10/31.
//

#ifndef PATHTRACING_SPHERE_H
#define PATHTRACING_SPHERE_H

#include <cmath>
#include <memory>
#include "vec3.h"
#include "ray.h"
#include "hit.h"
#include "material.h"
#include "light.h"

class Sphere {
public:
    Vec3 center;
    double radius;
    std::shared_ptr<Material> material;
    std::shared_ptr<Light> light;

    Sphere(const Vec3 &_center, double _radius, const std::shared_ptr<Material> &_material,
           const std::shared_ptr<Light> &_light) : center(_center), radius(_radius), material(_material),
                                                   light(_light) {};

    bool intersect(const Ray &ray, Hit &res) {
        {
            double b = dot(ray.direction, ray.origin - center);
            double c = (ray.origin - center).length2() - radius * radius;
            double D = b * b - c;

            double t1 = -b - std::sqrt(D);
            double t2 = -b + std::sqrt(D);

            if (t1 > 10000 | t2 < 0) return false;
            double t = t1;
            if (t < ray.tmin) {
                t = t2;
                if (t2 > 10000) return false;
            }

            res.t = t;
            res.hitPos = ray(t);
            res.hitNormal = normalize(res.hitPos - center);
            res.hitSphere = this;

            return true;
        }
    }
};

#endif //PATHTRACING_SPHERE_H
