//============================================================================
// Name        : Vector.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Class to define a vector.
//============================================================================

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <string>

//==============================================================================
/* Vector */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define a vector.
 */
namespace tnt
{
    class Vector
    {
    private:
        float x; // Horizontal component .
        float y; // Vertical component .

    public:
        // Create Vector with (x,y).
        Vector(float initX, float initY);

        // Default 2d (x,y) is (0,0).
        Vector();

        // Get/set horizontal component.
        void setX(float newX);
        float getX() const;

        // Get/set vertical component.
        void setY(float newY);
        float getY() const;

        // Set horizontal & vertical components.
        void setXY(float newX, float newY);

        // Return magnitude of vector.
        float getMagnitude() const;

        // Normalize vector.
        void normalize();

        // Scale vector.
        void scale(float s);

        // Add two Vectors, return new Vector.
        Vector operator+(const Vector &other) const;

        // Subtract two Vectors, return new Vector.
        Vector operator-(const Vector &other) const;

        // Compare two Vectors.
        bool operator==(const Vector &other) const;

        // Compare two Vectors.
        bool operator!=(const Vector &other) const;

        // Print for debug.
        std::string print();

        /* TODO (and test)
        Vector operator*(const Vector &other) const;
        Vector operator/(const Vector &other) const;
        Vector operator!(const Vector &other) const;
        */
    };
}
//------------------------------------------------------------------------------
#endif /* __VECTOR_H__ */
