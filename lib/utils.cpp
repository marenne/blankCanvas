#include "utils.h"
#include <iostream>
#include <vector>
#include <cmath>


namespace part1{
    
    bool isInRange(double x, double lim1, double lim2){
        auto withinRange =(x < lim1 ^ x < lim2 ) && (x > lim1  ^ x > lim2 );
        auto equalLimit = (x == lim1) || (x ==lim2);
        return withinRange || equalLimit;
    };
    
    
    Rectangle::Rectangle(Point aa, Point bb): a(aa), b(bb){
    };
    
    bool Rectangle::pointInRectangle(Point p){
        return isInRange(p.x,a.x,b.x) && isInRange(p.y,a.y,b.y);
    }
    
    bool doOverlap(Rectangle r1, Rectangle r2){
        auto anyXInRange = isInRange(r1.a.x,r2.a.x,r2.b.x) || isInRange(r1.b.x,r2.a.x,r2.b.x);
        auto anyYInRange = isInRange(r1.a.y,r2.a.y,r2.b.y) || isInRange(r1.b.y,r2.a.y,r2.b.y);
        return anyXInRange&&anyYInRange;
    }
}

namespace part2{
    
    bool isInRange(int x, int lim1, int lim2){
        auto withinRange =(x < lim1 ^ x < lim2 ) && (x > lim1  ^ x > lim2 );
        auto equalLimit = (x == lim1) || (x ==lim2);
        return withinRange || equalLimit;
    };
    
    bool Rectangle::pointInRectangle(Point p){
        return isInRange(p.x,a.x,b.x) && isInRange(p.y,a.y,b.y);
    }
    
    bool isInRange(double x, int lim1, int lim2){
        auto withinRange =  (x < static_cast<double>(lim1) ^ x < static_cast<double>(lim2) ) && (x > static_cast<double>(lim1) ^ x > static_cast<double>(lim2));
        auto equalLimit = (x == static_cast<double>(lim1)) || (x ==static_cast<double>(lim2));
        return withinRange || equalLimit;
    };
    
    bool Rectangle::pointInRectangle(std::array<double,2> p){
        return isInRange(p[0],a.x,b.x) && isInRange(p[1],a.x,b.x);
    }
    
    bool doOverlap(Rectangle r1, Rectangle r2){
        auto anyXInRange = isInRange(r1.a.x,r2.a.x,r2.b.x) || isInRange(r1.b.x,r2.a.x,r2.b.x);
        auto anyYInRange = isInRange(r1.a.y,r2.a.y,r2.b.y) || isInRange(r1.b.y,r2.a.y,r2.b.y);
        return anyXInRange&&anyYInRange;
    }
    
    bool doOverlap(part1::Rectangle r1, Rectangle r2){
        auto anyXInRange = isInRange(r1.a.x,r2.a.x,r2.b.x) || isInRange(r1.b.x,r2.a.x,r2.b.x);
        auto anyYInRange = isInRange(r1.a.y,r2.a.y,r2.b.y) || isInRange(r1.b.y,r2.a.y,r2.b.y);
        return anyXInRange&&anyYInRange;
    }
    
    void addToArray(std::vector<std::array<double,2> > &array, double x, double y){
        std::array<double,2> pt = {x,y} ;
        array.push_back(pt);}

    
    double Array2d::sumWithinRectangle(Rectangle r){
        double sum = 0.0;
        for (auto point: _array){
            if (r.pointInRectangle(point)){
                sum += point[0] + point[1];
            }
        }
        
        return sum;
    }
    
    
    EfficientArray2d::EfficientArray2d(std::vector<std::array<double,2> > array): _array(array){
        // get bounds of cloud array
        double minX = array[0][0];
        double maxX = array[0][0];
        double minY = array[0][1];
        double maxY = array[0][1];
        
        for (auto point: _array){
            minX = std::min(minX,point[0]);
            minY = std::min(minY,point[1]);
            maxX = std::max(maxX,point[0]);
            maxY = std::max(maxY,point[1]);
        }
        
        // Divide into rectangles:
        // to be the most efficient, I want to have approximately n rectangles containing each n points
        // I will be making a grid of m by m rectangles (m^2 = n, n^2 = number of points in the point cloud)
        
        auto n_divisions = static_cast<int>(std::ceil(std::pow(_array.size(), 0.25)));
        std::cout<<"Size of array: "<<_array.size()<<std::endl;
        std::cout<<"Number of divisions: "<<n_divisions<<std::endl;
        
        // I am assuming that we have indeed a point cloud, not a point line or a bunch of identical points
        auto xChunk = (maxX - minX) / static_cast<double>(n_divisions);
        auto yChunk = (maxY - minY) / static_cast<double>(n_divisions);
        for (auto ii =0 ; ii< n_divisions; ++ii){
            auto x0 = minX + ii*xChunk;
            auto x1 = minX + (ii+1)*xChunk;
            for (auto jj = 0; jj < n_divisions; ++jj){
                auto y0 = minY + jj*yChunk;
                auto y1 = minY + (jj+1)*yChunk;
                auto r = part1::Rectangle(part1::Point(x0,y0), part1::Point(x1,y1));
                _cloudRectangles.push_back(r);
                _cloudRectanglesCollections.push_back(std::vector<int>());
            }
        }
        
        // Now sort all the points into their rectangles
        
        for (auto ii =0 ; ii<_array.size(); ++ii){
            auto pt = part1::Point(_array[ii][0],_array[ii][1]);
            for (auto jj=0; jj<_cloudRectangles.size(); ++jj ){
                auto rectangle =_cloudRectangles[jj];
                if (rectangle.pointInRectangle(pt)){
                    _cloudRectanglesCollections[jj].push_back(ii);
                    break;
                }
            }
        }
        
    };
    
    double EfficientArray2d::sumWithinRectangle(Rectangle r){
        double sum = 0.0;
        for (auto ii =0 ; ii< _cloudRectangles.size(); ++ii){
            auto rectangle= _cloudRectangles[ii];
            if (doOverlap(rectangle,r)){
                for (auto idx: _cloudRectanglesCollections[ii]){
                    auto point = _array[idx];
                    if (r.pointInRectangle(point)){
                        sum += point[0] + point[1];}
                }
            }
            
        }
        return sum;
    }
}
