#ifndef SOCIAL_PLANS_MANAGEMENT_PLANSERVICE_H
#define SOCIAL_PLANS_MANAGEMENT_PLANSERVICE_H


#include "../data/daos/PlanRepository.h"
#include "../data/daos/ActivityRepository.h"
#include "Session.h"

class PlanService {
private:
    PlanRepository *planRepository;
    ActivityRepository *activityRepository;
    Session *session;
public:
    PlanService(PlanRepository *planRepository,
                ActivityRepository *activityRepository,
                Session *session) : planRepository(planRepository), activityRepository(activityRepository), session(session) {}

    Plan *create(const string &name, chrono::system_clock::time_point date, const string &meetingPlace, optional<int> capacity);

    void deletePlan(long planId);

    Plan *addActivity(long planId, long activityId);

    Plan *enrollSubscriber(long planId);

    float price(long planId);

    int duration(long planId);

    list<Plan *> availablePlans();

    list<Plan *> subscribedPlans();

    list<Plan *> priceRangePlans(float price, float range);

    list<Plan*> weekendPlans();

    list<Plan*> plansContainingKeyword(const string &keyword);

private:
    void checkNoTimeCollisionBetweenSubscribedPlans(Plan *plan, User *user);
};


#endif //SOCIAL_PLANS_MANAGEMENT_PLANSERVICE_H
