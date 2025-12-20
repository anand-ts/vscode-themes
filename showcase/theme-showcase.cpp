// comment: Mathematical shapes with advanced geometry operations
// Demonstrates: classes, templates, constants, operators, lambdas, ranges

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <regex>
#include <memory>
#include <numeric>
#include <algorithm>
#include <optional>

constexpr double PI = 3.14159265358979323846;
constexpr double E = 2.71828182845904523536;
constexpr double PHI = 1.61803398874989484820; // Golden ratio

// Point structure with operators
struct Point {
    double x, y;

    Point operator+(const Point& other) const {
        return {x + other.x, y + other.y};
    }

    Point operator*(double scalar) const {
        return {x * scalar, y * scalar};
    }

    double distanceTo(const Point& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }

    double magnitude() const {
        return std::sqrt(x * x + y * y);
    }
};

// Abstract Shape interface
class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual Point centroid() const = 0;
    virtual std::string name() const = 0;
};

// Circle class with advanced mathematical operations
class Circle : public Shape {
private:
    Point center_;
    double radius_;

public:
    Circle(const Point& center, double r = 42.0)
        : center_(center), radius_(r) {}

    double area() const override {
        return PI * std::pow(radius_, 2);
    }

    double perimeter() const override {
        return 2.0 * PI * radius_;
    }

    Point centroid() const override {
        return center_;
    }

    std::string name() const override {
        return "Circle";
    }

    // Calculate arc length for given angle in radians
    double arcLength(double angleRadians) const {
        return radius_ * angleRadians;
    }

    // Calculate sector area for given angle in radians
    double sectorArea(double angleRadians) const {
        return 0.5 * std::pow(radius_, 2) * angleRadians;
    }

    // Parse coordinate strings like "x=10 y=20"
    std::vector<std::string> matchPattern(const std::string& input) const {
        std::regex pattern(R"(([A-Za-z_]\w+)\s*=\s*(\d+(?:\.\d+)?))");
        std::vector<std::string> matches;

        auto begin = std::sregex_iterator(input.begin(), input.end(), pattern);
        auto end = std::sregex_iterator();

        for (auto it = begin; it != end; ++it) {
            matches.push_back((*it)[1].str() + "=" + (*it)[2].str());
        }
        return matches;
    }

    double getRadius() const { return radius_; }
};

// Ellipse class with eccentricity calculations
class Ellipse : public Shape {
private:
    Point center_;
    double semiMajorAxis_; // a
    double semiMinorAxis_; // b

public:
    Ellipse(const Point& center, double a, double b)
        : center_(center), semiMajorAxis_(a), semiMinorAxis_(b) {}

    double area() const override {
        return PI * semiMajorAxis_ * semiMinorAxis_;
    }

    // Ramanujan approximation for ellipse perimeter
    double perimeter() const override {
        double a = semiMajorAxis_;
        double b = semiMinorAxis_;
        double h = std::pow(a - b, 2) / std::pow(a + b, 2);
        return PI * (a + b) * (1.0 + (3.0 * h) / (10.0 + std::sqrt(4.0 - 3.0 * h)));
    }

    Point centroid() const override {
        return center_;
    }

    std::string name() const override {
        return "Ellipse";
    }

    // Calculate eccentricity: e = sqrt(1 - (b²/a²))
    double eccentricity() const {
        return std::sqrt(1.0 - std::pow(semiMinorAxis_ / semiMajorAxis_, 2));
    }

    // Focal distance from center
    double focalDistance() const {
        return semiMajorAxis_ * eccentricity();
    }
};

// Rectangle with golden ratio support
class Rectangle : public Shape {
private:
    Point bottomLeft_;
    double width_, height_;

public:
    Rectangle(const Point& bottomLeft, double width, double height)
        : bottomLeft_(bottomLeft), width_(width), height_(height) {}

    // Golden rectangle constructor
    static Rectangle createGoldenRectangle(const Point& bottomLeft, double width) {
        return Rectangle(bottomLeft, width, width / PHI);
    }

    double area() const override {
        return width_ * height_;
    }

    double perimeter() const override {
        return 2.0 * (width_ + height_);
    }

    Point centroid() const override {
        return {bottomLeft_.x + width_ / 2.0, bottomLeft_.y + height_ / 2.0};
    }

    std::string name() const override {
        return "Rectangle";
    }

    double diagonal() const {
        return std::sqrt(std::pow(width_, 2) + std::pow(height_, 2));
    }

    bool isGoldenRectangle() const {
        double ratio = std::max(width_, height_) / std::min(width_, height_);
        return std::abs(ratio - PHI) < 0.01;
    }
};

// Triangle with various centers and properties
class Triangle : public Shape {
private:
    Point a_, b_, c_;

public:
    Triangle(const Point& a, const Point& b, const Point& c)
        : a_(a), b_(b), c_(c) {}

    double area() const override {
        // Using cross product formula
        return 0.5 * std::abs(
            a_.x * (b_.y - c_.y) +
            b_.x * (c_.y - a_.y) +
            c_.x * (a_.y - b_.y)
        );
    }

    double perimeter() const override {
        return a_.distanceTo(b_) + b_.distanceTo(c_) + c_.distanceTo(a_);
    }

    Point centroid() const override {
        return {(a_.x + b_.x + c_.x) / 3.0, (a_.y + b_.y + c_.y) / 3.0};
    }

    std::string name() const override {
        return "Triangle";
    }

    // Calculate circumradius (radius of circumscribed circle)
    double circumradius() const {
        double a = b_.distanceTo(c_);
        double b = c_.distanceTo(a_);
        double c = a_.distanceTo(b_);
        return (a * b * c) / (4.0 * area());
    }

    // Calculate inradius (radius of inscribed circle)
    double inradius() const {
        return (2.0 * area()) / perimeter();
    }

    // Check if triangle is right-angled (Pythagorean theorem)
    bool isRightAngled(double tolerance = 0.01) const {
        double a = b_.distanceTo(c_);
        double b = c_.distanceTo(a_);
        double c = a_.distanceTo(b_);

        std::vector<double> sides = {a, b, c};
        std::sort(sides.begin(), sides.end());

        return std::abs(
            std::pow(sides[2], 2) - (std::pow(sides[0], 2) + std::pow(sides[1], 2))
        ) < tolerance;
    }
};

// Template function for calculating total area
template<typename Container>
double totalArea(const Container& shapes) {
    return std::accumulate(shapes.begin(), shapes.end(), 0.0,
        [](double sum, const auto& shape) {
            return sum + shape->area();
        });
}

// Mathematical utilities namespace
namespace MathUtils {
    // Fibonacci sequence generator
    std::vector<int> fibonacci(int n) {
        std::vector<int> fib(n);
        if (n > 0) fib[0] = 0;
        if (n > 1) fib[1] = 1;
        for (int i = 2; i < n; ++i) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib;
    }

    // Calculate factorial
    long long factorial(int n) {
        return (n <= 1) ? 1 : n * factorial(n - 1);
    }

    // Calculate binomial coefficient C(n, k)
    long long binomial(int n, int k) {
        if (k > n) return 0;
        if (k == 0 || k == n) return 1;
        return factorial(n) / (factorial(k) * factorial(n - k));
    }
}

int main() {
    std::cout << "=== Mathematical Shape Analysis ===\n\n";

    // Create various shapes
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(Point{0, 0}, 42.0));
    shapes.push_back(std::make_unique<Ellipse>(Point{10, 10}, 50.0, 30.0));
    shapes.push_back(std::make_unique<Rectangle>(Point{-5, -5}, 25.0, 15.0));
    shapes.push_back(std::make_unique<Triangle>(Point{0, 0}, Point{10, 0}, Point{5, 8.66}));

    // Golden rectangle
    auto goldenRect = Rectangle::createGoldenRectangle(Point{0, 0}, 100.0);
    shapes.push_back(std::make_unique<Rectangle>(goldenRect));

    // Display shape properties
    for (const auto& shape : shapes) {
        std::cout << shape->name() << ":\n";
        std::cout << "  Area: " << shape->area() << "\n";
        std::cout << "  Perimeter: " << shape->perimeter() << "\n";
        auto c = shape->centroid();
        std::cout << "  Centroid: (" << c.x << ", " << c.y << ")\n\n";
    }

    // Demonstrate Circle-specific features
    Circle myCircle(Point{5, 5}, 10.0);
    std::cout << "Circle Analysis:\n";
    std::cout << "  Sector area (π/4 rad): " << myCircle.sectorArea(PI / 4.0) << "\n";
    std::cout << "  Arc length (π/2 rad): " << myCircle.arcLength(PI / 2.0) << "\n\n";

    // Pattern matching demo
    std::string coords = "x=123 y=456 radius=789";
    auto matches = myCircle.matchPattern(coords);
    std::cout << "Parsed coordinates:\n";
    for (const auto& match : matches) {
        std::cout << "  " << match << "\n";
    }

    // Mathematical constants and relationships
    std::cout << "\n=== Mathematical Constants ===\n";
    std::cout << "π = " << PI << "\n";
    std::cout << "e = " << E << "\n";
    std::cout << "φ (Golden Ratio) = " << PHI << "\n";
    std::cout << "φ² = " << (PHI * PHI) << " ≈ φ + 1\n\n";

    // Fibonacci and golden ratio connection
    auto fib = MathUtils::fibonacci(15);
    std::cout << "Fibonacci sequence: ";
    for (int num : fib) std::cout << num << " ";
    std::cout << "\n\n";

    // Total area calculation using template
    std::cout << "Total area of all shapes: " << totalArea(shapes) << "\n";

    return 0;
}
