//
// Created by okn-yu on 2020/10/31.
//

#ifndef PATHTRACING_UTIL_H
#define PATHTRACING_UTIL_H

template <typename T>
T clamp(T x, T xmin, T xmax){
    if(x < xmin) return xmin;
    else if(x > xmax) return xmax;
    else return x;
}

#endif //PATHTRACING_UTIL_H
