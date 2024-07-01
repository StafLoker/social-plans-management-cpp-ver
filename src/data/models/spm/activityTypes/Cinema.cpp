#include "Cinema.h"

Cinema::Cinema(const string &name, const string &description, int duration, float price) : Activity(name,
                                                                                                    description,
                                                                                                    duration,
                                                                                                    price) {}

Cinema::Cinema(const string &name, const string &description, int duration, float price, int capacity) : Activity(
        name, description, duration, price, capacity) {}

float Cinema::getPrice(int age) const {
    return age <= MAX_YOUTH_MOVIE_DISCOUNT_AGE ? Activity::getPrice() - Activity::getPrice() * YOUTH_MOVIE_DISCOUNT : Activity::getPrice();
}