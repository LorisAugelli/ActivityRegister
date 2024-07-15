#include "gtest/gtest.h"

#include "../Activity.h"

TEST(Activity, Constructor) {
    Activity test(1,"Palestra", "Allenamento gambe", 15, 30, 17, 30);
    ASSERT_EQ(test.getId(), 1);
    ASSERT_EQ(test.getActivityName(), "Palestra");
    ASSERT_EQ(test.getDescription(), "Allenamento gambe");
    ASSERT_EQ(test.getHStart(), 15);
    ASSERT_EQ(test.getMStart(), 30);
    ASSERT_EQ(test.getHEnd(), 17);
    ASSERT_EQ(test.getMEnd(), 30);
}


TEST(Activity, TestStartsBefore) {
    Activity test1(1,"Palestra", "Allenamento gambe", 15, 30, 17, 30);
    Activity test2(2,"Pulizie di casa", "Pulire bagno", 13, 30, 15, 00);
    ASSERT_FALSE(test1.startsBefore(test2));
    ASSERT_TRUE(test2.startsBefore(test1));
}

TEST(Activity, TestToSting){
    Activity test(1,"Verifica", "Verifica di matematica", 10, 15, 12, 15);
    ASSERT_EQ(test.toString(), "10:15-12:15 | Verifica");
}