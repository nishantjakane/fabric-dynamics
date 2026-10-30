#include "fd/math/Vector3.hpp"

namespace fd::math{

    Vector3 Vector3::operator+(Vector3 b) const{
        return Vector3(x+b.x,y+b.y,z+b.z);
    }

    Vector3 Vector3::operator-(Vector3 b) const{
        return Vector3(x-b.x,y-b.y,z-b.z);
    }

    Vector3 Vector3::operator-() const{
        return Vector3(-1*x,-1*y,-1*z);
    }

    Vector3 Vector3::operator*(float b) const{
        return Vector3(x*b,y*b,z*b);
    }
    
    Vector3 Vector3::operator/(float b) const{
        return Vector3(x/b,y/b,z/b);
    }

    Vector3& Vector3::operator+=(Vector3 b){
        x = x + b.x;
        y = y + b.y;
        z = z + b.z;

        return *this;
    }

    Vector3& Vector3::operator-=(Vector3 b){
        x = x - b.x;
        y = y - b.y;
        z = z - b.z;

        return *this;
    }

    float dot(const Vector3 &a,const Vector3 &b) {
        return ((a.x * b.x)+(a.y * b.y)+(a.z * b.z));
    }

    Vector3 cross(const Vector3 &a,const Vector3 &b){
        float x = (a.y*b.z) - (a.z*b.y);
        float y = (a.z*b.x) - (a.x*b.z);
        float z = (a.x*b.y) - (a.y*b.x);

        return Vector3(x,y,z);
    }

}

