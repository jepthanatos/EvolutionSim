//============================================================================
// Name        : Vector.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description :
//============================================================================

#include "Vector.h"
#include "LogManager.h"

#include <math.h>
#include <sstream>

//==============================================================================
/* Vector */
//==============================================================================

namespace tnt
{
    /*------------------------------------------------------------------------------
     * Create Vector with (x,y).
     */
    Vector::Vector(float initX, float initY)
    {
        x = initX;
        y = initY;
    }

    /*------------------------------------------------------------------------------
     * Default 2d (x,y) is (0,0).
     */
    Vector::Vector(void)
    {
        x = y = 0;
    }

    /*------------------------------------------------------------------------------
     * Set horizontal component.
     */
    void Vector::setX(float newX)
    {
        x = newX;
    }

    /*------------------------------------------------------------------------------
     * Get horizontal component.
     */
    float Vector::getX() const
    {
        return x;
    }

    /*------------------------------------------------------------------------------
     * Set vertical component.
     */
    void Vector::setY(float newY)
    {
        y = newY;
    }

    /*------------------------------------------------------------------------------
     * Get vertical component.
     */
    float Vector::getY() const
    {
        return y;
    }

    /*------------------------------------------------------------------------------
     * Return magnitude of vector.
     */
    float Vector::getMagnitude() const
    {
        float mag = sqrt(x * x + y * y);
        return mag;
    }

    /*------------------------------------------------------------------------------
     * Set horizontal & vertical components.
     */
    void Vector::setXY(float newX, float newY)
    {
        x = newX;
        y = newY;
    }

    /*------------------------------------------------------------------------------
     * Normalize vector.
     */
    void Vector::normalize()
    {
        float length = getMagnitude();
        if (length > 0)
        {
            x = x / length;
            y = y / length;
        }
    }

    /*------------------------------------------------------------------------------
     * Scale vector.
     */
    void Vector::scale(float s)
    {
        x = x * s;
        y = y * s;
    }

    /*------------------------------------------------------------------------------
     * Add two Vectors, return new Vector.
     */
    Vector Vector::operator+(const Vector &other) const
    {
        Vector v;
        v.x = x + other.x;
        v.y = y + other.y;
        return v;
    }

    /*------------------------------------------------------------------------------
     * Subtract two Vectors, return new Vector.
     */
    Vector Vector::operator-(const Vector &other) const
    {
        Vector v;
        v.x = x - other.x;
        v.y = y - other.y;
        return v;
    }

    /*------------------------------------------------------------------------------
     * Compare two Vectors.
     */
    bool Vector::operator==(const Vector &other) const
    {
        return x == other.x and y == other.y;
    }

    /*------------------------------------------------------------------------------
     * Compare two Vectors.
     */
    bool Vector::operator!=(const Vector &other) const
    {
        return !operator==(other);
    }

    /*------------------------------------------------------------------------------
     * Print for debug.
     */
    std::string Vector::print()
    {
        std::ostringstream message;
        message << "(x= " << x << ", y= " << y << ")";
        return message.str();
    }
}
