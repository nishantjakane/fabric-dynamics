#pragma once

namespace fd::math
{
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

        Vector3 operator+(Vector3 b) const;
        Vector3 operator-(Vector3 b) const;
        Vector3 operator-() const;
        Vector3 operator*(float b) const;
        Vector3 operator/(float b) const;
        Vector3& operator+=(Vector3 b);
        Vector3& operator-=(Vector3 b);

    };

    float dot(const Vector3 &a,const Vector3 &b){}

    Vector3 cross(const Vector3 &a,const Vector3 &b){}

}
