#include <vector>
#include <array>

namespace part1{
    
    class Point{
    public:
        Point(double xx,double yy):x(xx), y(yy){};
        double x;
        double y;
        
    };
    
    class Rectangle{
    public:
        Rectangle(Point aa, Point bb);
        // a, b refer to opposing points of the rectangle like in the diagram
        bool pointInRectangle(Point p);
        Point a;
        Point b;
        
    };
    
    bool doOverlap(Rectangle r1, Rectangle r2);
}
namespace part2{
    
    struct Point{
        Point(int xx,int yy):x(xx), y(yy){};
        int x;
        int y;
        
    };
    
    struct Rectangle{
        Rectangle(Point aa, Point bb): a(aa), b(bb){};
        // a, b refer to opposing points of the rectangle like in the diagram
        bool pointInRectangle(Point p);
        bool pointInRectangle(std::array<double,2> p);
        Point a;
        Point b;
        
    };
    
    
    void addToArray(std::vector<std::array<double,2> > &array, double x, double y);

    
    bool doOverlap(Rectangle r1, Rectangle r2);
    
    class Array2d{
        // assumption: in the underlying array, _array[i][0] represents the x coordinate and _array[i][1] represents the x coordinate and the y coordinate
    public:
        Array2d(std::vector<std::array<double,2> > array): _array(array){};
        std::vector<std::array<double,2> > getArray(){return _array;};
        double sumWithinRectangle(Rectangle r);
    private:
        std::vector<std::array<double,2> > _array;
    };
    
    
    class EfficientArray2d{
        // assumption: in the underlying array, _array[i][0] represents the x coordinate and _array[i][1] represents the x coordinate and the y coordinate
    public:
        EfficientArray2d(std::vector<std::array<double,2> > array);
        std::vector<std::array<double,2> > getArray(){return _array;};
        double sumWithinRectangle(Rectangle r);
    private:
        std::vector<std::array<double,2> > _array;
        std::vector<part1::Rectangle> _cloudRectangles;
        std::vector<std::vector<int> > _cloudRectanglesCollections;
    };
}
