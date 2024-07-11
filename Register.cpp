//
// Created by Z3X0S on 11/07/24.
//
#include "Register.h"
using namespace std;

int Register::getIdActivities() {
    return idActivities;
}

void Register::incrementIdActivities() {
    idActivities++;
}



void Register::addActivity(const string &name, const string &desc, int hStart, int mStart, int hEnd, int mEnd) {
    Activity tempActivity = Activity(getIdActivities(), name, desc, hStart, mStart, hEnd, mEnd);
    activities.push_back(tempActivity);
    incrementIdActivities();
}

void Register::removeActivity(int id) {

    for (auto it = activities.begin(); it != activities.end(); ++it){
        if (it->getId()==id)
            activities.erase(it);
    }

}