// Copyright 2024 Moiseev Nikita
#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

TEST(Prime, testSmall) {
    EXPECT_TRUE(checkPrime(1));
    EXPECT_TRUE(checkPrime(3));
    EXPECT_FALSE(checkPrime(12));
    EXPECT_FALSE(checkPrime(13));
}

TEST(Prime, tetsBig) {
    EXPECT_TRUE(checkPrime(1e9 + 4));
    EXPECT_TRUE(checkPrime(123'456'789));
    EXPECT_FALSE(checkPrime(1e9 + 2));
}
TEST(Prime, tetsVeryBig) {
    EXPECT_TRUE(checkPrime(1e12 + 4));
    EXPECT_FALSE(checkPrime(1e13 + 2));
}

TEST(NPrime, testSmall) {
    EXPECT_EQ(nPrime(2), 1);
    EXPECT_EQ(nPrime(3), 2);
    EXPECT_EQ(nPrime(5), 3);
}

TEST(NPrime, testBig) {
    EXPECT_EQ(nPrime(1e9 + 4), 22'232'331);
    EXPECT_EQ(nPrime(123'456'789), 212'312);
}

TEST(NextPrime, testSmall) {
    EXPECT_EQ(nextPrime(4), 5);
    EXPECT_EQ(nextPrime(11), 13);
    EXPECT_EQ(nextPrime(10), 17);
}

TEST(NextPrime, testBig) {
    EXPECT_EQ(nextPrime(1e9 + 4), 1e9 + 9);
    EXPECT_EQ(nextPrime(123'456'789), 123'456'797);
}

TEST(SumPrime, testSmall) {
    EXPECT_EQ(sumPrime(5), 5);
    EXPECT_EQ(sumPrime(8), 18);
}
TEST(SumPrime, testBig) {
    EXPECT_EQ(sumPrime(10'000), 5'736'396);
}

TEST(SumPrime, testSum) {
    int sum1 = sumPrime(5);
    int sum2 = sumPrime(8);
    EXPECT_EQ(sumPrime(sum1+sum2), 23);
}