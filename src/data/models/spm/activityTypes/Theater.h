#ifndef SOCIAL_PLANS_MANAGEMENT_THEATER_H
#define SOCIAL_PLANS_MANAGEMENT_THEATER_H


#include "../Activity.h"

class Theater : public Activity {
private:
    constexpr static const float YOUTH_THEATER_DISCOUNT = 0.50;
    constexpr static const float SENIOR_CITIZEN_THEATER_DISCOUNT = 0.70;

    static const int MAX_YOUTH_THEATER_DISCOUNT_AGE = 25;
    static const int MIN_SENIOR_CITIZEN_THEATER_DISCOUNT_AGE = 65;
public:
    Theater() : Activity() {};

    Theater(const string &name, const string &description, int duration, float price, int capacity);

    Theater(const string &name, const string &description, int duration, float price);

    float getPrice(int age) const;
};


#endif //SOCIAL_PLANS_MANAGEMENT_THEATER_H
