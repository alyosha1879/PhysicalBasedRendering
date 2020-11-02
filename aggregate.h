//
// Created by okn-yu on 2020/10/31.
//

#ifndef PATHTRACING_AGGREGATE_H
#define PATHTRACING_AGGREGATE_H

#include <memory>
#include <vector>
#include "ray.h"
#include "hit.h"
#include "sphere.h"

class Aggregate {
public:
    std::vector<std::shared_ptr<Sphere>> spheres;

    Aggregate() {};
    Aggregate(const std::vector<std::shared_ptr<Sphere>>& _spheres) : spheres(_spheres) {};


    void add(const std::shared_ptr<Sphere>& s) {
        spheres.push_back(s);
    };

    bool intersect(const Ray& ray, Hit& res) const {
        bool hit = false;
        for(auto s : spheres) {
            Hit res_temp;
            if(s->intersect(ray, res_temp)) {
                if(res_temp.t < res.t) {
                    hit = true;
                    res = res_temp;
                }
            }
        }
        return hit;
    };
};

#endif //PATHTRACING_AGGREGATE_H
