#include "gtest/gtest.h"

#include "../Register.h"


class RegisterSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        r = new Register();

    }
    void TearDown() override{
        delete r;
    }
    Register* r = nullptr;
};


TEST_F(RegisterSuite, AddActivityTest){
    r->addActivity("Palestra", "Allenamento braccia", 16, 30, 18, 30);
    ASSERT_EQ(r->getIdActivities(), 1);
    ASSERT_EQ(r->getActivities().begin()->getActivityName(), "Palestra");
    ASSERT_EQ(r->getActivities().begin()->getDescription(), "Allenamento braccia");
    ASSERT_EQ(r->getActivities().begin()->getHStart(), 16);
    ASSERT_EQ(r->getActivities().begin()->getMStart(), 30);
    ASSERT_EQ(r->getActivities().begin()->getHEnd(), 18);
    ASSERT_EQ(r->getActivities().begin()->getMEnd(), 30);

}

TEST_F(RegisterSuite, AddActivityOrderTest){
    r->addActivity("Palestra", "Allenamento braccia", 16, 30, 18, 30);
    r->addActivity("Scuola", "Orario del giovedi'", 8, 30, 13, 30);
    //tests if the activities are ordered by the start hour. If so the first activity in the list should be "Scuola" now even if added later.

    ASSERT_EQ(r->getIdActivities(), 2); //how many activities were put in the list, not the actual number of the current ones. In this case they should be equal, though.
    ASSERT_EQ(r->getActivities().begin()->getActivityName(), "Scuola");
    ASSERT_EQ(r->getActivities().begin()->getDescription(), "Orario del giovedi'");
    ASSERT_EQ(r->getActivities().begin()->getHStart(), 8);
    ASSERT_EQ(r->getActivities().begin()->getMStart(), 30);
    ASSERT_EQ(r->getActivities().begin()->getHEnd(), 13);
    ASSERT_EQ(r->getActivities().begin()->getMEnd(), 30);

    //if activities are ordered correctly this one should be last in the list.
    r->addActivity("Cena", "Cotoletta", 20, 30, 21, 0);
    ASSERT_EQ(r->getIdActivities(), 3);
    ASSERT_EQ(r->getActivities().rbegin()->getActivityName(), "Cena");
    ASSERT_EQ(r->getActivities().rbegin()->getDescription(), "Cotoletta");
    ASSERT_EQ(r->getActivities().rbegin()->getHStart(), 20);
    ASSERT_EQ(r->getActivities().rbegin()->getMStart(), 30);
    ASSERT_EQ(r->getActivities().rbegin()->getHEnd(), 21);
    ASSERT_EQ(r->getActivities().rbegin()->getMEnd(), 0);

}

TEST_F(RegisterSuite, DeleteActivityOrderTest){
    r->addActivity("Cena", "Cotoletta", 20, 30, 21, 0);
    r->addActivity("Doccia", "Doccia calda", 22, 0, 22, 15);
    ASSERT_EQ(r->getIdActivities(), 2);//ensures the activities are added;

    r->removeActivity("20:30-21:0 | Cena");
    ASSERT_EQ(r->getActivities().begin()->getActivityName(), "Doccia");//now the first activity should be "Doccia"

}