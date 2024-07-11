//
// Created by Z3X0S on 11/07/24.
//

#ifndef ACTIVITYREGISTER_ACTIVITY_H
#define ACTIVITYREGISTER_ACTIVITY_H

#include <string>
using namespace std;

class Activity {
public:
    Activity(int id, const string &name, const string &desc, int hStart, int mStart, int hEnd, int mEnd){
        this->id=id;
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

    void setDescription(const string &description) {
        Activity::description = description;
    }

    const string &getActivityName() const {
        return activityName;
    }

    void setActivityName(const string &activityName) {
        Activity::activityName = activityName;
    }

    int getId(){
        return id;
    }

    int getHStart() const {
        return hStart;
    }

    void setHStart(int hStart) {
        Activity::hStart = hStart;
    }

    int getMStart() const {
        return mStart;
    }

    void setMStart(int mStart) {
        Activity::mStart = mStart;
    }

    int getHEnd() const {
        return hEnd;
    }

    void setHEnd(int hEnd) {
        Activity::hEnd = hEnd;
    }

    int getMEnd() const {
        return mEnd;
    }

    void setMEnd(int mEnd) {
        Activity::mEnd = mEnd;
    }

private:
    string activityName;
    string description;
    int id;
    int hStart, mStart;
    int hEnd, mEnd;



};
#endif //ACTIVITYREGISTER_ACTIVITY_H
