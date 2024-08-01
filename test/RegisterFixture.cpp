#include "gtest/gtest.h"

#include "../Register.h"


class RegisterSuite : public ::testing::Test {

protected:
    void SetUp() override {
        r = new Register();
    }
    void TearDown() override{
        delete r;
    }
    Register* r = nullptr;
};


TEST_F(RegisterSuite, AddActivityTest){
    r->addActivity("Palestra", "Allenamento braccia", 16, 30, 18, 30);
    auto activity = r->findActivity("16:30-18:30 | Palestra");
    ASSERT_TRUE(activity!=r->getEnd());

}

TEST_F(RegisterSuite, AddActivityOrderTest){
    r->addActivity("Palestra", "Allenamento braccia", 16, 30, 18, 30);
    r->addActivity("Scuola", "Orario del giovedi'", 8, 30, 13, 30);
    //tests if the activities are ordered by the start hour. If so the first activity in the list should be "Scuola" now even if added later.

    ASSERT_EQ(r->getNActivities(), 2);//how many activities were put in the list.
    auto tempActivity = r->findActivity("8:30-13:30 | Scuola");
    ASSERT_EQ(tempActivity, r->getStart());

    //if activities are ordered correctly this one should be last in the list.
    r->addActivity("Cena", "Cotoletta", 20, 30, 21, 0);
    tempActivity = r->findActivity("20:30-21:0 | Cena");
    auto firstToLastItem = r->getStart();
    advance(firstToLastItem, r->getNActivities()-1);
    ASSERT_EQ(tempActivity, firstToLastItem);

}

TEST_F(RegisterSuite, DeleteActivityOrderTest){
    r->addActivity("Cena", "Cotoletta", 20, 30, 21, 0);
    r->addActivity("Doccia", "Doccia calda", 22, 0, 22, 15);
    ASSERT_EQ(r->getNActivities(), 2);//ensures the activities are added;

    r->removeActivity("20:30-21:0 | Cena");
    ASSERT_EQ(r->getStart()->getActivityName(), "Doccia");//now the first activity should be "Doccia"

}

TEST_F(RegisterSuite, FindActivityTest){
    r->addActivity("Cena", "Cotoletta", 20, 30, 21, 0);
    auto activity = r->findActivity("20:30-21:0 | Cena");
    ASSERT_TRUE(activity!=r->getEnd());
}


TEST_F(RegisterSuite, FindActivityEmptyTest){
    r->addActivity("Cena", "Cotoletta", 20, 30, 21, 0);
    auto activity = r->findActivity("Attivita' non presente");
    ASSERT_EQ(activity, r->getEnd());
}

TEST_F(RegisterSuite, ActivityNumberEmptyTest){
    ASSERT_EQ(0, r->getNActivities());
}

TEST_F(RegisterSuite, ActivityNumberTest){
    r->addActivity("Cena", "Cotoletta", 20, 30, 21, 0);
    ASSERT_EQ(1, r->getNActivities());
    r->addActivity("Doccia", "Doccia calda", 22, 0, 22, 15);
    ASSERT_EQ(2, r->getNActivities());
    r->removeActivity("20:30-21:0 | Cena");
    ASSERT_EQ(1, r->getNActivities());
}