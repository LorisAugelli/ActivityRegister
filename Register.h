//
// Created by Z3X0S on 11/07/24.
//
#include "Activity.h"
#include <list>
using namespace std;

#ifndef ACTIVITYREGISTER_REGISTER_H
#define ACTIVITYREGISTER_REGISTER_H
class Register{
public:
    Register();

    void addActivity(const string &name, const string &desc, int hStart, int mStart, int hEnd, int mEnd);
    void removeActivity(string activity);
    int getIdActivities();
    void incrementIdActivities();
    list<Activity> & getActivities();


private:
   list<Activity> activities;
   int idActivities;
};
#endif //ACTIVITYREGISTER_REGISTER_H
