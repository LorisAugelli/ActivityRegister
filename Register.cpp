//
// Created by Z3X0S on 11/07/24.
//
#include "Register.h"
using namespace std;

Register::Register() {
    this->idActivities=0;
}



int Register::getIdActivities() {
    return idActivities;
}

void Register::incrementIdActivities() {
    idActivities++;
}



void Register::addActivity(const string &name, const string &desc, int hStart, int mStart, int hEnd, int mEnd) {
    Activity tempActivity = Activity(getIdActivities(), name, desc, hStart, mStart, hEnd, mEnd);
    if (activities.empty()){
        activities.push_back(tempActivity);
    }
    else{
        int last = true;
        for (auto it = activities.begin(); it != activities.end(); ++it){
            if (tempActivity.startsBefore(*it)) {
                activities.insert(it, tempActivity);
                last = false;
            }
        }
        if (last)
            activities.push_back(tempActivity);
    }

    incrementIdActivities();
}

void Register::removeActivity(int id) {

    for (auto it = activities.begin(); it != activities.end(); ++it){
        if (it->getId()==id)
            activities.erase(it);
    }

}

list<Activity> & Register::getActivities(){
    return Register::activities;
}