#include <gtest/gtest.h>
#include "pricingutil.h"

TEST(sampleTest, sample) {
    EXPECT_EQ(4, 4);
}

TEST(sampleTest2, sample){
    EXPECT_EQ(1, 1);
}

TEST(testPricingUtil, testFormula ){
    PricingUtil PU = PricingUtil();
    EXPECT_NEAR(PU.calcVal(2, 0.1, 10), 20, 1e-4);
    EXPECT_NEAR(PU.getVal(), 20, 1e-4);
    EXPECT_NEAR(PU.calcVal(100, 0.1, 10), 1000, 1e-4);
    EXPECT_NEAR(PU.getVal(), 1000, 1e-4);
    EXPECT_NEAR(PU.calcVal(1000, 1, 10), 19000, 1e-4);
    EXPECT_NEAR(PU.getVal(), 19000, 1e-4);
}

TEST(testPricingUtil, zeroInitial){
    PricingUtil PU = PricingUtil();
    EXPECT_EQ(PU.calcVal(0, 0.1, 10), 0.0);
    EXPECT_EQ(PU.getVal(), 0.0);
    EXPECT_EQ(PU.calcVal(0, 2.1, 100), 0.0);
    EXPECT_EQ(PU.getVal(), 0.0);
}

TEST(testPricingUtil, negativeInitial){
    PricingUtil PU = PricingUtil();
    EXPECT_NEAR(PU.calcVal(-5, 0.1, 10), -50, 1e-4);
    EXPECT_NEAR(PU.getVal(), -50, 1e-4);
    EXPECT_NEAR(PU.calcVal(-1, 0.1, 100), -100, 1e-4);
    EXPECT_NEAR(PU.getVal(), -100, 1e-4);
}