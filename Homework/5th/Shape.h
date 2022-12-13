class Shape
{
private:
    int X, Y;

public:
    Shape(int x, int y) : X(x), Y(y){};
    ~Shape();
};

Shape::~Shape()
{
}