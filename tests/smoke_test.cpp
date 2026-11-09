#include <gtest/gtest.h>
#include <Eigen/Dense>

// Two springs in a chain, wall on the left, load F at node 2.
// K = [[k1 + k2, -k2], [-k2, k2]]

// k1 = 1, k2 = 1 N/mm, F = 10 N  ->  u = (10, 20) mm
TEST(SpringChain, EqualSprings) {
    Eigen::Matrix2d K;
    K << 2, -1,
        -1,  1;
    Eigen::Vector2d f(0, 10);
    Eigen::Vector2d u = K.ldlt().solve(f);
    EXPECT_NEAR(u(0), 10.0, 1e-12);
    EXPECT_NEAR(u(1), 20.0, 1e-12);
}

// k1 = 2, k2 = 1 N/mm, F = 10 N  ->  u = (5, 15) mm
TEST(SpringChain, StifferFirstSpring) {
    Eigen::Matrix2d K;
    K << 3, -1,
        -1,  1;
    Eigen::Vector2d f(0, 10);
    Eigen::Vector2d u = K.ldlt().solve(f);
    EXPECT_NEAR(u(0), 5.0, 1e-12);
    EXPECT_NEAR(u(1), 15.0, 1e-12);
}