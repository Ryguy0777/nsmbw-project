// m_vec.cpp
// NSMBW .text: 0x80170AC0 - 0x80170D90
// NSMBW .bss: 0x803780C8 - 0x803780F8

#include "m_vec.h"

/**
 * The null vector.
 */
[[address_data(0x803780C8)]]
mVec3_c mVec3_c::Zero;

/**
 * The unit vector for the X axis.
 */
[[address_data(0x803780D4)]]
mVec3_c mVec3_c::Ex;

/**
 * The unit vector for the Y axis.
 */
[[address_data(0x803780E0)]]
mVec3_c mVec3_c::Ey;

/**
 * The unit vector for the Z axis.
 */
[[address_data(0x803780EC)]]
mVec3_c mVec3_c::Ez;

/**
 * Normalizes the vector.
 * @return The vector's magnitude.
 */
[[address(0x80170AC0)]]
float mVec3_c::normalize();

/**
 * Normalizes the vector.
 * @return If the operation was successful.
 */
[[address(0x80170B40)]]
bool mVec3_c::normalizeRS();

/**
 * Rotates the vector on the X axis by the given angle.
 */
[[address(0x80170BD0)]]
void mVec3_c::rotX(mAng angle);

/**
 * Rotates the vector on the Y axis by the given angle.
 */
[[address(0x80170C80)]]
void mVec3_c::rotY(mAng angle);

// 0x80170D30: __sinit_\m_vec_cpp
