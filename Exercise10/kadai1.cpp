//学籍番号:4619023 加藤零
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Polygon {
   protected:
    std::vector<int> edges;
    template <class... Edges>
    void set_sides(Edges... params) {
        for (int i : std::initializer_list<int>{params...}) {
            edges.emplace_back(i);
        }
    }

   public:
    virtual void perimeter() = 0;
    virtual void area() = 0;
};

class Triangle : public Polygon {
   public:
    void set_sides(int a, int b, int c) { Polygon::set_sides(a, b, c); }

    void perimeter() {
        cout << "Triangle:perimeter: "
             << std::accumulate(edges.begin(), edges.end(), 0) << endl;
    }

    void area() {
        double s = std::accumulate(edges.begin(), edges.end(), 0) / 2.0;
        cout << "Triangle:area: "
             << sqrtl(s * (s - edges[0]) * (s - edges[1]) * (s - edges[2]))
             << endl;
    }
};

class Rectangle : public Polygon {
   public:
    void set_sides(int a, int b) { Polygon::set_sides(a, b); }
    void perimeter() {
        cout << "Rectangle:perimeter: "
             << std::accumulate(edges.begin(), edges.end(), 0) * 2 << endl;
    }
    void area() { cout << "Rectangle:area: " << edges[0] * edges[1] << endl; }
};

int main(void) {
    Triangle sankaku;
    Rectangle tyohokei;
    sankaku.set_sides(4, 5, 6);
    sankaku.perimeter();
    sankaku.area();
    tyohokei.set_sides(5, 7);
    tyohokei.perimeter();
    tyohokei.area();
    return 0;
}
