#include "gtest/gtest.h"
#include "Utils/circ_buffer.hpp"

using namespace Utils;

TEST(CircBufferTests, GetCapacityWorks) {
    char buff[1000];
    CircBuffer a{buff, 1000};
    EXPECT_EQ(a.GetCapacity(), 1000);
    CircBuffer b{buff, 10};
    EXPECT_EQ(b.GetCapacity(), 10);
}

TEST(CircBufferTests, GetSizeInitTo0) {
    char buff[1000];
    CircBuffer a{buff, 1000};
    EXPECT_EQ(a.GetSize(), 0);
}

TEST(CircBufferTests, AppendIncreasesSize) {
    char buff[10];
    CircBuffer a{buff, 10};
    a.Append('c');
    EXPECT_EQ(a.GetSize(), 1);
    a.Append('a');
    a.Append('b');
    EXPECT_EQ(a.GetSize(), 3);
}

TEST(CircBufferTests, GetNextReturnsData) {
    char buff[10];
    CircBuffer cb{buff, 10};
    cb.Append('a');
    cb.Append('b');
    
    char a = cb.GetNext();
    char b = cb.GetNext();

    EXPECT_EQ(a, 'a');
    EXPECT_EQ(b, 'b');
}

TEST(CircBufferTests, GetNextLowersSize) {
    char buff[10];
    CircBuffer cb{buff, 10};
    cb.Append('a');
    cb.Append('b');
    
    EXPECT_EQ(cb.GetSize(), 2);
    cb.GetNext();
    EXPECT_EQ(cb.GetSize(), 1);
    cb.GetNext();
    EXPECT_EQ(cb.GetSize(), 0);
}

TEST(CircBufferTests, AppendingAfterGettingDataWorks) {
    char buff[10];
    CircBuffer cb{buff, 10};
    cb.Append('a');
    cb.Append('b');
    cb.GetNext();
    
    cb.Append('c');
    
    EXPECT_EQ(cb.GetSize(), 2);
    char b = cb.GetNext();
    char c = cb.GetNext();
    EXPECT_EQ(b, 'b');
    EXPECT_EQ(c, 'c');
}
