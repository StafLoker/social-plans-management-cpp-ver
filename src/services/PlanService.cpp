#include "PlanService.h"

Plan *PlanService::create(const string &name, chrono::system_clock::time_point date, const string &meetingPlace, optional<int> capacity) {
    return nullptr;
}

void PlanService::deletePlan(long planId) {

}

Plan *PlanService::addActivity(long planId, long activityId) {
    return nullptr;
}

Plan *PlanService::enrollSubscriber(long planId) {
    return nullptr;
}

float PlanService::price(long planId) {
    return 0;
}

int PlanService::duration(long planId) {
    return 0;
}

list<Plan *> PlanService::availablePlans() {
    return list<Plan *>();
}

list<Plan *> PlanService::subscribedPlans() {
    return list<Plan *>();
}

list<Plan *> PlanService::priceRangePlans(float price, float range) {
    return list<Plan *>();
}

list<Plan *> PlanService::weekendPlans() {
    return list<Plan *>();
}

list<Plan *> PlanService::plansContainingKeyword(const string &keyword) {
    return list<Plan *>();
}
