#ifndef SOCIAL_PLANS_MANAGEMENT_PLAN_H
#define SOCIAL_PLANS_MANAGEMENT_PLAN_H


#include "../User.h"
#include "Activity.h"

using namespace std;

#include <list>
#include "chrono"

class Plan {
private:
    static const int MIN_CAPACITY = 1;
    static const int TIME_DISPLACEMENT = 20;

    long id{};
    string name, meetingPlace;
    User *owner;
    chrono::system_clock::time_point date;
    optional<int> capacity;
    list<User*> subscribers;
    list<Activity*> activities;

public:

    Plan() = default;

    Plan(string name, User *owner, string meetingPlace, chrono::system_clock::time_point date);

    Plan(string name, User *owner, string meetingPlace, chrono::system_clock::time_point date, int capacity);

    void addSubscriber(User *user);

    int availableSpots() const;

    void addActivity(Activity *activity);

    float price(User *user) const;

    int duration() const;

    // getters & setters

    long getId() const;

    void setId(long id);

    const string &getName() const;

    void setName(const string &name);

    const string &getMeetingPlace() const;

    void setMeetingPlace(const string &meetingPlace);

    const User *getOwner() const;

    void setOwner(User *owner);

    const chrono::system_clock::time_point &getDate() const;

    void setDate(const chrono::system_clock::time_point &date);

    const optional<int> &getCapacity() const;

    void setCapacity(int capacity);
};


#endif //SOCIAL_PLANS_MANAGEMENT_PLAN_H
