#include "math.h"

Math::Math() {};

float Math::clamp(float value, float lower, float upper) {
    return value < lower ? lower : (value > upper ? upper : value);
}