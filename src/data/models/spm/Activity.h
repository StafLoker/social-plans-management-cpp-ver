#ifndef SOCIAL_PLANS_MANAGEMENT_ACTIVITY_H
#define SOCIAL_PLANS_MANAGEMENT_ACTIVITY_H

#include <string>
#include <optional>

using namespace std;

class Activity {
private:
    static const int MIN_CAPACITY = 1;

    long id{};
    string name, description;
    int duration;
    float price;
    optional<int> capacity;

public:
    Activity() = default;

    Activity(string name, string description, int duration, float price);

    Activity(string name, string description, int duration, float price, int capacity);

    float getPrice(int age) const;

    // getters & setters

    void setId(long id);

    void setCapacity(int capacity);

    long getId() const;

    const string &getName() const;

    const string &getDescription() const;

    int getDuration() const;

    float getPrice() const;

    const optional<int> &getCapacity() const;

    // operators

    bool operator==(const Activity &rhs) const;

    bool operator!=(const Activity &rhs) const;
};


#endif //SOCIAL_PLANS_MANAGEMENT_ACTIVITY_H
