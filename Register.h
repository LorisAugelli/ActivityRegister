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
    Register()=default;
    void addActivity(const string &name, const string &desc, int hStart, int mStart, int hEnd, int mEnd);
    void removeActivity(const string &activity);
    int getNActivities() const;
    list<Activity>::const_iterator getIncomingActivities() const;
    list<Activity>::const_iterator getStart() const;
    list<Activity>::const_iterator getEnd() const;
    list<Activity>::const_iterator findActivity(const string &activity) const;
private:
   list<Activity> activities;
};
#endif //ACTIVITYREGISTER_REGISTER_H
