#pragma once

extern "C" {

#define NAN (0.0/0.0)

/**
 * Returns the absolute value of x.
 */
inline double fabs(double x)
{
    return __builtin_fabs(x);
}

/**
 * Returns the absolute value of x.
 */
inline float fabsf(float x)
{
    return __builtin_fabs(x);
}

} // extern "C"