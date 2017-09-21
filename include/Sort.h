#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include "Shapes.h"
#include <list>
#include <stdio.h>
#include <algorithm>

class Sort {
public:
    static void sortByIncreasingPerimeter(std::list<Shape *> * shapeList);
    static void sortByDecreasingPerimeter(std::list<Shape *> * shapeList);
    static void sortByIncreasingArea(std::list<Shape *> * shapeList);
    static void sortByDecreasingArea(std::list<Shape *> * shapeList);
    static void sortByIncreasingCompactness(std::list<Shape *> * shapeList);
    //static bool comp(const Shape * num1,const Shape * num2);
    static bool compByIncreasingPerimeter(const Shape * num1,const Shape * num2);
    static bool compByDecreasingPerimeter(const Shape * num1,const Shape * num2);
    static bool compByIncreasingArea(const Shape * num1,const Shape * num2);
    static bool compByDecreasingArea(const Shape * num1,const Shape * num2);
    static bool compByIncreasingCompactness(const Shape * num1,const Shape * num2);
};




#endif