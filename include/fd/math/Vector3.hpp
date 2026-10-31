#pragma once

namespace fd::math
{
    inline constexpr float EPSILON = 1e-6f;

    struct Vector3
    {
        float x;
        float y;
        float z;

        Vector3()
            : x(0.0f), y(0.0f), z(0.0f)
        {
        }

        Vector3(float x , float y, float z)
            : x(x),y(y),z(z)
        {   
        }

        Vector3 operator+(const Vector3 &b) const;
        Vector3 operator-(const Vector3 &b) const;
        Vector3 operator-() const;
        Vector3 operator*(float scalar) const;
        Vector3 operator/(float scalar) const;
        bool operator==(const Vector3 &b) const;
        bool operator!=(const Vector3 &b) const;
        Vector3& operator+=(const Vector3 &b);
        Vector3& operator-=(const Vector3 &b);

        float lengthSquared() const;
        float length() const;

        Vector3 normalized() const;

        bool isZero() const;
        bool isNormalized() const;
    };

    Vector3 operator*(float scalar,const Vector3 &a);

    bool approximatelyEqual(const float a,const float b);

    float dot(const Vector3 &a,const Vector3 &b);

    Vector3 cross(const Vector3 &a,const Vector3 &b);

    float distance(const Vector3 &a,const Vector3 &b);
    float squaredDistance(const Vector3 &a,const Vector3 &b);
}
