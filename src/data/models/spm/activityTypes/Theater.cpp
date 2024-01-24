#include "Theater.h"

Theater::Theater(const string &name, const string &description, int duration, float price) : Activity(name,
                                                                                                       description,
                                                                                                       duration,
                                                                                                       price) {}

Theater::Theater(const string &name, const string &description, int duration, float price, int capacity) : Activity(
        name, description, duration, price, capacity) {}

float Theater::getPrice(int age) const {
    if (age <= MAX_YOUTH_THEATER_DISCOUNT_AGE) {
        return Activity::getPrice() - Activity::getPrice() * YOUTH_THEATER_DISCOUNT;
    } else if (age >= MIN_SENIOR_CITIZEN_THEATER_DISCOUNT_AGE) {
        return Activity::getPrice() - Activity::getPrice() * SENIOR_CITIZEN_THEATER_DISCOUNT;
    }
    return Activity::getPrice();
}