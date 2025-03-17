#include <iostream>
#include <string>

using namespace std;

class Shape
{
    protected:
        string color;

    public:
        Shape(const string &color_ = "black") : color(color_) {}

        virtual void draw() const
        {
            cout << "Drawing a generic shape" << endl;
        }

        virtual double calculateArea() const
        {
            return 0.0;
        }
};

// Specific Shapes
class Circle : public Shape
{
    private:
        double radius;

    public:
        Circle(double r, const string &color_ = "black")
            : radius(r), Shape(color_) {}

        void draw() const override
        {
            cout << "Drawing a Circle in color " << color << endl;
        }

        double calculateArea() const override
        {
            return 3.14 * radius * radius;
        }
};

class ShapeDecorator : public Shape
{
    protected:
        Shape *decoratedShape;

    public:
        ShapeDecorator(Shape *shape) : decoratedShape(shape){}

        virtual void draw() const override
        {
            decoratedShape->draw();
        }

        virtual double calculateArea() const override
        {
            return decoratedShape->calculateArea();
        }
};

// Concrete Decorators
class BorderDecorator : public ShapeDecorator
{
    private:
        double borderWidth;

    public:
        BorderDecorator(Shape *shape, double width)
            : ShapeDecorator(shape), borderWidth(width) {}

        void draw() const override
        {
            decoratedShape->draw();
            cout << "   with border width of " << borderWidth << endl;
        }
};

class ShadowDecorator : public ShapeDecorator
{
    private:
        string shadowColor;

    public:
        ShadowDecorator(Shape *shape, const string &color)
            : ShapeDecorator(shape), shadowColor(color) {}

        void draw() const override
        {
            decoratedShape->draw();
            cout << "   with shadow color " << shadowColor << endl;
        }
};


int main(int argc, char const *argv[])
{
    Shape *shape = new Circle(5, "red");                // 0x01

    shape = new ShadowDecorator(shape, "yellow");       // 0xc3

    shape = new BorderDecorator(shape, 2);              // 0xb2

    shape->draw();

    cout << "Area: " << shape->calculateArea() << endl;

    delete shape;

    return 0;
}
