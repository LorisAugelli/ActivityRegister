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
    Register(){
        this->idActivities=0;
    };

    void addActivity(const string &name, const string &desc, int hStart, int mStart, int hEnd, int mEnd);
    void removeActivity(int id);
    int getIdActivities();
    void incrementIdActivities();

private:
   list<Activity> activities;
   int idActivities;
};
#endif //ACTIVITYREGISTER_REGISTER_H
