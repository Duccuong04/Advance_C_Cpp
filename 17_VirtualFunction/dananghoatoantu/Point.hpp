class Point
{
    private:
        int xVal, yVal;
    public:
        Point(int = 1, int = 1);
        Point(const Point&);
        ~Point();
        void Show();
        friend Point operator+(const Point&, const Point&);
        //p1 - p2
        Point operator-(const Point&);
};