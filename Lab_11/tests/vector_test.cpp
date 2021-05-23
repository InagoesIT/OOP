#include "gtest/gtest.h"
#include "../src/vector.cpp"

class VectorTest : public testing::Test {
protected: 
    Vector<int> v1; // cazul vid
    //Vector<int> v2; // un element
    //Vector<int> v3; // un vector aleator
    //Vector<int> v4; // un vector descrescator
    //Vector<int> v5; // un vector crescator
    //Vector<int> v6; // un vector cu numere negative

    virtual void SetUp() 
    {
       // v2.Adauga(3);
       // v3.Adauga(4); v3.Adauga(200); v3.Adauga(20); v3.Adauga(1); v3.Adauga(55);
       // v4.Adauga(5); v4.Adauga(4); v4.Adauga(3); v4.Adauga(2); v4.Adauga(1); v4.Adauga(0);
        //v5.Adauga(0); v5.Adauga(1); v5.Adauga(2); v5.Adauga(3); v5.Adauga(4); v5.Adauga(5);
        //v6.Adauga(-10); v6.Adauga(-8); v6.Adauga(-9); v6.Adauga(-11);
    }
};

TEST_F(VectorTest, SortareVida)
{
    v1.Sortare();
    EXPECT_STREQ("", v1.GetArrayString().c_str());
}

TEST_F(VectorTest, Sortare1Elem) 
{
    //v1.Adauga(3);
    v1.Sortare();
    EXPECT_STREQ("3 ", v1.GetArrayString().c_str());
}

/*TEST_F(VectorTest, SortareObisnuita)
{
    v3.Sortare();
    EXPECT_STREQ("1 4 20 55 200 ", v3.GetArrayString().c_str());
}

TEST_F(VectorTest, SortareDescr)
{
    v4.Sortare();
    EXPECT_STREQ("0 1 2 3 4 5 ", v4.GetArrayString().c_str());
}

TEST_F(VectorTest, SortareCresc)
{
    v5.Sortare();
    EXPECT_STREQ("0 1 2 3 4 5 ", v5.GetArrayString().c_str());
}

TEST_F(VectorTest, SortareNegativa)
{
    v6.Sortare();
    EXPECT_STREQ("-11 -10 -9 -8 ", v6.GetArrayString().c_str());
}*/