#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    // Constructor
    Shape() {}

    // Virtual destructor
    virtual ~Shape() {}

    // Pure virtual functions
    virtual std::string to_string() const = 0;
    virtual void centre_at(double x, double y) = 0;
};

class Circle : public Shape {
public:
    // Constructor
    Circle(double x, double y, double r);

    // Implementations of virtual functions
    std::string to_string() const override;
    void centre_at(double x, double y) override;

private:
    double x_;
    double y_;
    double r_;
};

class Rectangle : public Shape {
public:
    // Constructor
    Rectangle(double x0, double y0, double x1, double y1);

    // Implementations of virtual functions
    std::string to_string() const override;
    void centre_at(double x, double y) override;

private:
    double x0_;
    double y0_;
    double x1_;
    double y1_;
};

// Triangle class
class Triangle: public Shape{
private:
    double x0;
    double y0;
    double x1;
    double y1;
    double x2;
    double y2;
public:
    Triangle(double x0, double y0, double x1, double y1, double x2, double y2);
    std::string to_string() const override;
    void centre_at(double x, double y) override;

};

#endif // SHAPE_H