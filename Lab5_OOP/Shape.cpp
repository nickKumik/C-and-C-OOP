#include "Shape.h"
#include <sstream>
#include <algorithm>
#include <cmath>

// Circle constructor
Circle::Circle(double x, double y, double r) : x_(x), y_(y), r_(r) {}

// Circle toString() implementation
std::string Circle::to_string() const {
    std::stringstream ss;
    ss << "Circle centred at (" << x_ << ", " << y_ << ") with radius " << r_;
    return ss.str();
}

// Circle centreAt() implementation
void Circle::centre_at(double x, double y) {
    x_ = x;
    y_ = y;
}

// Rectangle constructor
Rectangle::Rectangle(double x0,  double y0, double x1, double y1)
    : x0_(x0), y0_(y0), x1_(x1), y1_(y1) {}


// Rectangle toString() implementation
std::string Rectangle::to_string() const {
    std::stringstream ss;
    ss << "Rectangle at [(" << x0_ << ", " << y0_ << "), (" << x1_ << ", " << y1_ << ")] with width "
       << (x1_ - x0_) << ", height " << (y1_ - y0_);
    return ss.str();
}

// Rectangle centreAt() implementation
void Rectangle::centre_at(double x, double y) {
    double width = x1_ - x0_;
    double height = y1_ - y0_;
    x0_ = x - width / 2;
    y0_ = y - height / 2;
    x1_ = x + width / 2;
    y1_ = y + height / 2;
}

Triangle::Triangle(double x0, double y0, double x1, double y1, double x2, double y2) : x0(x0), y0(y0), x1(x1), y1(y1), x2(x2), y2(y2){}

// Triangle functions
// to_String function
std::string Triangle::to_string() const {

    double l1 = std::sqrt((x1-x0)*(x1-x0)+(y1-y0)*(y1-y0));
    double l2 = std::sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    double l3 = std::sqrt((x0-x2)*(x0-x2)+(y0-y2)*(y0-y2));

    std::stringstream sstr;
    sstr << "Triangle at [(" << x0 << ", " << y0 << "), (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")] with side lengths "
         << l1 << ", " << l2 << " and " << l3 << std::endl;
    std::string str = sstr.str();

    return str;

}
// centre_at function
void Triangle::centre_at(double x_coordinate, double y_coordinate) {

    double centroidX = (x0+x1+x2)/3;
    double centroidY = (y0+y1+y2)/3;

    double centroidDiffX = x_coordinate-centroidX;
    double centroidDiffY = y_coordinate-centroidY;

    this->x0 = x0+centroidDiffX;
    this->y0 = y0+centroidDiffY;
    this->x1 = x1+centroidDiffX;
    this->y1 = y1+centroidDiffY;
    this->x2 = x2+centroidDiffX;
    this->y2 = y2+centroidDiffY;

}
