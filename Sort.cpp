#include "include/Sort.h"
using namespace std;
#include <list>
#include <algorithm>
#include <iostream>

void Sort::sortByIncreasingPerimeter(std::list<Shape *> * shapeList){
    shapeList->sort(compByIncreasingPerimeter);
}
void Sort::sortByDecreasingPerimeter(std::list<Shape *> * shapeList){
    shapeList->sort(compByDecreasingPerimeter);
}
void Sort::sortByIncreasingArea(std::list<Shape *> * shapeList){
    shapeList->sort(compByIncreasingArea);
}
void Sort::sortByDecreasingArea(std::list<Shape *> * shapeList){
    shapeList->sort(compByDecreasingArea);
}
void Sort::sortByIncreasingCompactness(std::list<Shape *> * shapeList){
    shapeList->sort(compByIncreasingCompactness);
}

bool Sort::compByIncreasingPerimeter(const Shape * num1,const Shape * num2) {
    return num1->perimeter() < num2->perimeter();
}

bool Sort::compByDecreasingPerimeter(const Shape * num1,const Shape * num2) {
    return num1->perimeter() > num2->perimeter();
}

bool Sort::compByIncreasingArea(const Shape * num1,const Shape * num2) {
    return num1->area() < num2->area();
}

bool Sort::compByDecreasingArea(const Shape * num1,const Shape * num2) {
    return num1->area() > num2->area();
}

bool Sort::compByIncreasingCompactness(const Shape * num1,const Shape * num2) {
    return (num1->area()/num1->perimeter()) < (num2->area()/num2->perimeter());
}