#include <vector>
#include <gtest/gtest.h>
#include "../lib/utils.h"
#include <random>

TEST(pointInTriangle, part1){
    // Question 1.a
    part1::Point a(1,1);
    part1::Point b(5,5);
    part1::Rectangle r(a,b);
    
    part1::Point p0(1,0);
    part1::Point p1(2,2);
    part1::Point p2(2,0);
    part1::Point p3(4,2);
    
    // the pointInRectangle function checks if x is between a.x and b.x and y is between a.y and b.y
    EXPECT_FALSE(r.pointInRectangle(p0));
    EXPECT_TRUE(r.pointInRectangle(p1));
    EXPECT_FALSE(r.pointInRectangle(p2));
    EXPECT_TRUE(r.pointInRectangle(p3));
    
}

TEST(rectanglesOverlap, part1){
    // Question 1.b
    part1::Point a(3,3);
    part1::Point b(5,5);
    part1::Rectangle r(a,b);
    
    part1::Point p0(1,0);
    part1::Point p1(2,2);
    part1::Point p2(2,0);
    part1::Point p3(4,3.5);
    
    part1::Rectangle r1(p0,p1);
    part1::Rectangle r2(p2,p3);
    
    // the doOverlap function uses the same logic as 1.a to see whether any of the points of one rectangle lie within the other rectangle
    EXPECT_TRUE(part1::doOverlap(r,r2));
    EXPECT_FALSE(part1::doOverlap(r,r1));
}

TEST(pointCloud, part2){
    // Question 2.a
    // Apologies for the clumsy intialization, I am on my personal computer. The compiler is a bit unflexible with std arrays.
    std::vector<std::array<double,2> > array2d;
    part2::addToArray(array2d, 0.5, 0.2);
    part2::addToArray(array2d, 2.5, 1.2);
    part2::addToArray(array2d, 1.5, 0.2);
    part2::addToArray(array2d, 3.5, 3.2);
    
    auto pointCloud = part2::Array2d(array2d);
    
    auto r = part2::Rectangle(part2::Point(0,0),part2::Point(2,2));
    
    EXPECT_EQ(pointCloud.getArray().size(),4);
    EXPECT_EQ(pointCloud.sumWithinRectangle(r),2.4);
    
    // Question 2.b
    // Running time complexity of the function: O(N), N being the number of points in the cloud
    // Memory complexity: O(1), it creates only one variable (the sum) and aggregates directly into it
    
    // Question 2.c
    // Preprocess the cloud of points: we can divide it up into a collection of "cloud" rectangles
    // When doing the sum, we can loop over the "cloud" rectangles.
    // If the rectangle r intersects our cloud rectangle, then we call the function on all points within the cloud rectangle.
    
    std::vector<std::array<double,2> > array2d_2;
    auto nPoints = 100;
    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution(0.0, 10.0);
    
    for (int ii = 0; ii< nPoints; ++ii){
        part2::addToArray(array2d_2, distribution(generator),  distribution(generator));
    }
    
    auto efficientPointCloud = part2::EfficientArray2d(array2d_2);
    auto standardPointCloud = part2::Array2d(array2d_2);
    
    EXPECT_EQ(efficientPointCloud.sumWithinRectangle(r),standardPointCloud.sumWithinRectangle(r));
    
    // Question 2.d: we would be storing an additional array of integers of size N and sqrt(N) rectangles. So we would actually be using O(N) memory (but the client code has a structure of the same size, so this constructor is not creating something bigger than what is already handled by memory). We would decrease the run time complexity to O(sqrt(N)).
    
    // Question 2.e: The function will be overall faster. The constructor will take about as long as the unmodified version of rectangleSum, but each call of rectangleSum will take O(sqrt(N)) time. This means we "win" by using the modified class if there are more than two calls to rectangleSum (assuming the number of points is big enough for this to be the significant time consumer).
    
}
