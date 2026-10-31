#include "fd/math/Vector3.hpp"
#include <cmath>
#include <stdexcept>

namespace fd::math{

    // Member Functions
    Vector3 Vector3::operator+(const Vector3 &b) const{
        return Vector3(x+b.x,y+b.y,z+b.z);
    }

    Vector3 Vector3::operator-(const Vector3 &b) const{
        return Vector3(x-b.x,y-b.y,z-b.z);
    }

    Vector3 Vector3::operator-() const{
        return Vector3(-1*x,-1*y,-1*z);
    }

    Vector3 Vector3::operator*(float scalar) const{
        return Vector3(x*scalar,y*scalar,z*scalar);
    }

    Vector3 operator*(float scalar,const Vector3 &a){
        return Vector3(a.x*scalar,a.y*scalar,a.z*scalar);
    }
    
    Vector3 Vector3::operator/(float scalar) const{
        if(scalar==0){
            throw std::invalid_argument("Division by zero");
        }else{
            return Vector3(x/scalar,y/scalar,z/scalar);
        }
    }

    bool Vector3::operator==(const Vector3 &b) const{
        return(approximatelyEqual(x,b.x) && approximatelyEqual(y,b.y) && approximatelyEqual(z,b.z));
    }

    bool Vector3::operator!=(const Vector3 &b) const{
        return !(*this == b);
    }

    Vector3& Vector3::operator+=(const Vector3 &b){
        x = x + b.x;
        y = y + b.y;
        z = z + b.z;

        return *this;
    }

    Vector3& Vector3::operator-=(const Vector3 &b){
        x = x - b.x;
        y = y - b.y;
        z = z - b.z;

        return *this;
    }

    float Vector3::lengthSquared() const{
        return ((x*x) + (y*y) + (z*z));
    }

    float Vector3::length() const{
       return std::sqrt(lengthSquared()); 
    }

    Vector3 Vector3::normalized() const{
        float l = length();
        if(isZero()){
            return Vector3();
        }else{
            return (*this/l);
        }
    }

    bool Vector3::isZero() const{
        return(approximatelyEqual(length(),0.0f));
    }

    bool Vector3::isNormalized() const{
        return(approximatelyEqual(length(),1.0f));
    }


    // Free functions

    bool approximatelyEqual(const float a,const float b){
        return (std::abs(a-b)<=EPSILON);
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


    float distance(const Vector3 &a,const Vector3 &b){
        return ((a - b).length());
    }

    float squaredDistance(const Vector3 &a,const Vector3 &b){
        return ((a - b).lengthSquared());
    }

}

