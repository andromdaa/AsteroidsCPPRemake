//
// Created by Cole on 4/25/2022.
//

#include <cmath>
#include "Util.h"

float Util::normalize(float val) {
    bool neg;
    if(val < 0) neg = true;
    float aVal = std::fabs(val);
    if(aVal < 0.000001) return 0;
    else if(aVal > .9999 && !neg) return 1;
    else if(aVal > .9999 && neg) return -1;
    return val;
}

