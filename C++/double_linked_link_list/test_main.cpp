#include <gtest/gtest.h>
#include "dl_src/d_ll.h"

DoubleLinkedList<int> *test_dl = new DoubleLinkedList<int>();

TEST(LinkedList, Insert)
{
    EXPECT_EQ(true, test_dl -> insert(1));
    EXPECT_EQ(true, test_dl -> insert(2));
    EXPECT_EQ(true, test_dl -> insert(3));
    EXPECT_EQ(true, test_dl -> insert(4));
    EXPECT_EQ(true, test_dl -> insert(5));
}
TEST(LinkedList, Remove)
{
    EXPECT_EQ(false, test_dl -> remove(100));
    EXPECT_EQ(true, test_dl -> remove(1));
    EXPECT_EQ(true, test_dl -> remove(5));
    EXPECT_EQ(true, test_dl -> remove(3));
    EXPECT_EQ(true, test_dl -> remove(4));
    EXPECT_EQ(true, test_dl -> remove(2));
    EXPECT_EQ(true, test_dl -> remove(400));
}

TEST(LinkedList, Display)
{
    EXPECT_EQ(false, test_dl -> display_list());

    test_dl -> insert(1);
    test_dl -> insert(2);
    test_dl -> insert(3);

    EXPECT_EQ(true, test_dl -> display_list());
}

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    int tester = RUN_ALL_TESTS();
    delete test_dl;
    test_dl = nullptr;
    return tester;
}