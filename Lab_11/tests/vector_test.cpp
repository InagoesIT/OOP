#include "gtest/gtest.h"
#include "../src/vector.cpp"

class VectorTest : public testing::Test {
protected: 
    Vector<int> v1;
};

TEST_F(VectorTest, SortareVida)
{
    v1.Sortare();
    EXPECT_STREQ("", v1.GetArrayString().c_str());
}

TEST_F(VectorTest, Sortare1Elem) 
{
    v1.Adauga(3);
    v1.Sortare();
    EXPECT_STREQ("3 ", v1.GetArrayString().c_str());
}

TEST_F(VectorTest, SortareObisnuita)
{
    v1.Adauga(4); v1.Adauga(200); v1.Adauga(20); v1.Adauga(1); v1.Adauga(55);
    v1.Sortare();
    EXPECT_STREQ("1 4 20 55 200 ", v1.GetArrayString().c_str());
}

TEST_F(VectorTest, SortareDescr)
{
    v1.Adauga(5); v1.Adauga(4); v1.Adauga(3); v1.Adauga(2); v1.Adauga(1); v1.Adauga(0);
    v1.Sortare();
    EXPECT_STREQ("0 1 2 3 4 5 ", v1.GetArrayString().c_str());
}

TEST_F(VectorTest, SortareCresc)
{
    v1.Adauga(0); v1.Adauga(1); v1.Adauga(2); v1.Adauga(3); v1.Adauga(4); v1.Adauga(5);
    v1.Sortare();
    EXPECT_STREQ("0 1 2 3 4 5 ", v1.GetArrayString().c_str());
}

TEST_F(VectorTest, SortareNegativa)
{
    v1.Adauga(-10); v1.Adauga(-8); v1.Adauga(-9); v1.Adauga(-11);
    v1.Sortare();
    EXPECT_STREQ("-11 -10 -9 -8 ", v1.GetArrayString().c_str());
}