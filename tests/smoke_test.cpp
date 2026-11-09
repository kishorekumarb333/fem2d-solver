#include <gtest/gtest.h>
#include <Eigen/Dense>

TEST(Setup, EigenSolvesLinearSystem) {
    Eigen::Matrix2d K;
    K << 3, -1,
        -1,  1;
    Eigen::Vector2d f(0, 10);
    Eigen::Vector2d u = K.ldlt().solve(f);
    EXPECT_NEAR(u(0), 5.0, 1e-12);
    EXPECT_NEAR(u(1), 15.0, 1e-12);
}
