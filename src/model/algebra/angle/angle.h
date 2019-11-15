#ifndef EVE_ANGLE_H
#define EVE_ANGLE_H

#include "../algebra_conf.h"

#include <cmath>

/* Guaranteed to be between 0 and 2 PI */
struct Angle {
private:
    double a;

    static double normalise (double angle);
    static int normalise (int angle);

public:
    explicit Angle (double angle);
    explicit Angle (int angle);

    [[nodiscard]] double radians() const;
    [[nodiscard]] int degrees() const;

    void update (double angle);
    void update (int angle);

    static double toRadians (int angle);
    static int toDegrees (double angle);

    /* Overloaded operators */
    Angle & operator = (double val);

    double  operator - () const;

    double  operator +  (const Angle & angle) const;
    double  operator +  (double val)          const;

    double  operator -  (const Angle & angle) const;
    double  operator -  (double val)          const;

    double  operator *  (const Angle & angle) const;
    double  operator *  (double val)          const;

    double  operator /  (const Angle & angle) const;
    double  operator /  (double val)          const;

    bool    operator == (const Angle & angle) const;
    bool    operator == (double val)          const;

    bool    operator <  (const Angle & angle) const;
    bool    operator <  (double val)          const;

    bool    operator >  (const Angle & angle) const;
    bool    operator >  (double val)          const;

    bool    operator ! () const;
};

#endif //EVE_ANGLE_H
