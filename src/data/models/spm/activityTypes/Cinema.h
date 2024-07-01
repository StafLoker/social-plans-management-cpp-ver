#ifndef SOCIAL_PLANS_MANAGEMENT_CINEMA_H
#define SOCIAL_PLANS_MANAGEMENT_CINEMA_H


#include "../Activity.h"

class Cinema : public Activity{
private:
    constexpr static const float YOUTH_MOVIE_DISCOUNT = 0.50;

    static const int MAX_YOUTH_MOVIE_DISCOUNT_AGE = 21;
public:
    Cinema() : Activity() {};

    Cinema(const string &name, const string &description, int duration, float price, int capacity);

    Cinema(const string &name, const string &description, int duration, float price);

    float getPrice(int age) const;
};


#endif //SOCIAL_PLANS_MANAGEMENT_CINEMA_H
