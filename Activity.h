//
// Created by Z3X0S on 11/07/24.
//

#ifndef ACTIVITYREGISTER_ACTIVITY_H
#define ACTIVITYREGISTER_ACTIVITY_H

#include <string>
using namespace std;

class Activity {
public:
    Activity(const string &name, const string &desc, int hStart, int mStart, int hEnd, int mEnd){
        if (name.empty())
            throw invalid_argument("Name can't be empty.");

        if(!checkHour(hStart) || !checkHour(hEnd) || !checkMinute(mStart) || !checkMinute(mEnd) || hStart>hEnd)
            throw invalid_argument("Invalid activity hour or minute.");

        this->activityName=name;
        this->description=desc;
        this->hStart=hStart;
        this->mStart=mStart;
        this->hEnd=hEnd;
        this->mEnd=mEnd;
    }

    const string &getDescription() const {
        return description;
    }

    const string &getActivityName() const {
        return activityName;
    }

    int getHStart() const {
        return hStart;
    }

    int getMStart() const {
        return mStart;
    }

    int getHEnd() const {
        return hEnd;
    }

     int getMEnd() const {
        return mEnd;
    }

    //checks if an activity starts before a given other one
    bool startsBefore(const Activity & otherActivity) const{
        if((otherActivity.getHStart()>hStart) || (otherActivity.getHStart()==hStart && otherActivity.getMStart()>mStart)) {
            return true;
        }
        return false;
    }

    string toString() const{
        string s;
        return s.append(to_string(hStart)).append(":").append(to_string(mStart)).append("-").append(to_string(hEnd)).append(":").append(
                to_string(mEnd)).append(" | ").append(activityName);
    }
private:
    string activityName;
    string description;
    int hStart, mStart;
    int hEnd, mEnd;

    static bool checkHour(int h) {
        if (h<24 && h>=0)
            return true;
        return false;
    }

    static bool checkMinute(int m) {
        if (m>=0 and m<60)
            return true;
        return false;
    }
};
#endif //ACTIVITYREGISTER_ACTIVITY_H
