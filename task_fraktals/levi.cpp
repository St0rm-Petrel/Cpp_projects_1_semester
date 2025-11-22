#include <exception>
#include <iostream>
#include <list>
#include <Graph.h>
#include <Simple_window.h>
#include <poly.h>
#include <vec2d.h>

using namespace Graph_lib;

void levi_fractal_step (std::list<Vec2d>& curve) // why does it work?
{
    auto prev = curve.begin();
    auto curr = prev;
    curr++;
    for (;curr != curve.end(); ++curr)
    {
        auto b = *curr - *prev;
        b /= 2.;
        auto p = *prev + b; 
        auto m = rotated(M_PI/2., *curr, p);
        curve.insert(curr, m);
        prev = curr;
    }
}

auto max_edge_length (const std::list<Vec2d>& curve)
{
    double d = 0.;  // maximum edge length
    auto prev = curve.begin();
    auto curr = prev;
    curr++;
    for (auto curr = curve.begin(); curr != curve.end(); ++curr)
    {
        d = std::max(d, length(*curr - *prev));
        prev = curr;
    }
    return d;
}


void draw_levi_curve(int w, int iterations) 
{
    Simple_window win{Point{100, 100}, w, w, "Levi curve"};
    
    Vec2d start{w * 0.3, w * 0.3};
    Vec2d end{w * 0.75, w * 0.3};
    
    std::list<Vec2d> curve = {start, end};
    
    
    Text n_steps{as_point(Vec2d{w * 0.525, w * 0.4}), "0"};
    n_steps.set_color(Color::blue);
    win.attach(n_steps);
    
    for (int i = 0; i < iterations; ++i) 
    {

        Open_polyline current_curve;
        for (const auto& point : curve) // const auto& point : curve - объявление итератора - ссылки на элемент константного вектора
        { 
            current_curve.add(Point(std::round(point.x), std::round(point.y)));
        }
        current_curve.set_color(Color::blue);
        
        levi_fractal_step(curve);
        
        win.attach(current_curve);
        win.wait_for_button();
        win.detach(current_curve);
        
        n_steps.set_label(std::to_string(i + 1)); // std::to_string - преобразует число в строку

        if (max_edge_length(curve) < 2.0) 
        {
            n_steps.set_color(Color::red);
            break;
        }
    }
    Open_polyline final_curve;
    for (const auto& point : curve) 
    {
    final_curve.add(Point(std::round(point.x), std::round(point.y)));
    }
    final_curve.set_color(Color::red);
    win.attach(final_curve);
    win.wait_for_button();
}

int main()
{
    try
    {
        draw_levi_curve(1000, 20);
    }
    catch (std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
        return 0;
