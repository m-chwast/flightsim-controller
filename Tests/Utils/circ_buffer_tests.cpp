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
    char buff[1000];
    CircBuffer a{buff, 1000};
    a.Append('c');
    EXPECT_EQ(a.GetSize(), 1);
    a.Append('a');
    a.Append('b');
    EXPECT_EQ(a.GetSize(), 3);
}
