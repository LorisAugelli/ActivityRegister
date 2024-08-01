//
// Created by Z3X0S on 11/07/24.
//
#include "Register.h"
#include <chrono>

using namespace std;

void Register::addActivity(const string &name, const string &desc, int hStart, int mStart, int hEnd, int mEnd){
    Activity tempActivity = Activity(name, desc, hStart, mStart, hEnd, mEnd);
    if (activities.empty()){
        activities.push_back(tempActivity);
    }
    else{
        for (auto it = activities.begin(); it != activities.end(); ++it){
            if (tempActivity.startsBefore(*it)) {
                activities.insert(it, tempActivity);
                return;
            }
        }
        activities.push_back(tempActivity);
    }
}

void Register::removeActivity(const string &activity) {
    auto actToRemove =  findActivity(activity);
    if(actToRemove!=activities.end())
        activities.erase(actToRemove);
}

list<Activity>::const_iterator Register::getStart() const{
    return activities.begin();
}

list<Activity>::const_iterator Register::getEnd() const{
    return activities.end();
}

int Register::getNActivities() const{
    return activities.size();
}

list<Activity>::const_iterator Register::getIncomingActivities() const{
    auto now = std::chrono::system_clock::now();
    time_t tt = std::chrono::system_clock::to_time_t(now);
    tm local_tm = *localtime(&tt);
    int hour = local_tm.tm_hour;
    int minute = local_tm.tm_min;
    for (auto it = activities.begin(); it!=activities.end(); ++it){
        if((it->getHStart()>hour) || (it->getHStart()==hour && it->getMStart()>minute)){
            return it;
        }
    }
    return activities.end();
}

list<Activity>::const_iterator Register::findActivity(const string &activity) const{
    for(auto it=activities.begin(); it!=activities.end(); ++it){
        if (it->toString()==activity)
            return it;
    }
    return activities.end();
}