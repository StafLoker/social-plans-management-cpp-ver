#ifndef SOCIAL_PLANS_MANAGEMENT_THEATER_H
#define SOCIAL_PLANS_MANAGEMENT_THEATER_H


#include "../Activity.h"

class Theater : public Activity {
    constexpr static const double YOUTH_THEATER_DISCOUNT = 0.50;
    constexpr static const double SENIOR_CITIZEN_THEATER_DISCOUNT = 0.70;

    static const int MAX_YOUTH_THEATER_DISCOUNT_AGE = 25;
    static const int MIN_SENIOR_CITIZEN_THEATER_DISCOUNT_AGE = 65;
public:
    Theater() : Activity() {};

    Theater(const string &name, const string &description, int duration, double price, int capacity);

    Theater(const string &name, const string &description, int duration, double price);

    double getPrice(int age) const;
};


#endif //SOCIAL_PLANS_MANAGEMENT_THEATER_H
