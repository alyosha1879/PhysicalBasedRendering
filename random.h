//
// Created by okn-yu on 2020/11/01.
//

#ifndef PATHTRACING_RANDOM_H
#define PATHTRACING_RANDOM_H

std::random_device rnd_dev;
std::mt19937 mt(rnd_dev());
std::uniform_real_distribution<> dist(0, 1);

inline double rnd() {
    return dist(mt);
}


#endif //PATHTRACING_RANDOM_H
