#include "utils.h"

const double Utils::m_pi = 3.14159265358979323846;

float Utils::DegreesToRadians(float deg) {
    return static_cast<float>(deg * (m_pi / 180.0));
}

float  Utils::RadiansToDegrees(float rad) {
    return static_cast<float>(rad * (180.0 / m_pi));
}