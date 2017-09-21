#ifndef EXP_H
#define EXP_H

#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"
#include <gtest/gtest.h>
#include <list>
#include <iostream>
using namespace std;

TEST (Sort, sortByIncreasingPerimeter) {

    Rectangle r1(0, 0, 4, 3);      
    Circle c1(0, 0, 10);
    vertex v1,v2,v3;
    v1.x = 0;
    v1.y = 0;
    v2.x = 4;
    v2.y = 4;
    v3.x = 9;
    v3.y = 0;
    Triangle t1(v1,v2,v3,"");
    
    std::list<Shape *> *shapes = new std::list<Shape *>();
    shapes->push_back(&r1);
    shapes->push_back(&c1);
    shapes->push_back(&t1);
    
    std::list<Shape *>::iterator it = shapes->begin();
    
    ASSERT_NEAR(14, (*it++)->perimeter(),0.01);
    ASSERT_NEAR(62.83, (*it++)->perimeter(),0.01);
    ASSERT_NEAR(21.05, (*it++)->perimeter(),0.01);
    
    Sort::sortByIncreasingPerimeter(shapes);
    it = shapes->begin();

    ASSERT_NEAR(62.83, (*it++)->perimeter(),0.01);
    ASSERT_NEAR(21.05, (*it++)->perimeter(),0.01);
    ASSERT_NEAR(14, (*it++)->perimeter(),0.01);
}

TEST (Sort, sortByDecreasingPerimeter) {
    
    Rectangle r1(0, 0, 4, 3);      
    Circle c1(0, 0, 10);
    vertex v1,v2,v3;
    v1.x = 0;
    v1.y = 0;
    v2.x = 4;
    v2.y = 4;
    v3.x = 9;
    v3.y = 0;
    Triangle t1(v1,v2,v3,"");
    
    std::list<Shape *> *shapes = new std::list<Shape *>();
    shapes->push_back(&r1);
    shapes->push_back(&c1);
    shapes->push_back(&t1);
    
    std::list<Shape *>::iterator it = shapes->begin();
    
    ASSERT_NEAR(14, (*it++)->perimeter(),0.01);
    ASSERT_NEAR(62.83, (*it++)->perimeter(),0.01);
    ASSERT_NEAR(21.05, (*it++)->perimeter(),0.01);
    
    Sort::sortByDecreasingPerimeter(shapes);
    it = shapes->begin();

    ASSERT_NEAR(14, (*it++)->perimeter(),0.01);
    ASSERT_NEAR(21.05, (*it++)->perimeter(),0.01);
    ASSERT_NEAR(62.83, (*it++)->perimeter(),0.01);

}

TEST (Sort, sortByIncreasingArea) {
    
    Rectangle r1(0, 0, 4, 3);      
    Circle c1(0, 0, 5);
    vertex v1,v2,v3;
    v1.x = 0;
    v1.y = 0;
    v2.x = 4;
    v2.y = 4;
    v3.x = 9;
    v3.y = 0;
    Triangle t1(v1,v2,v3,"");
    
    std::list<Shape *> *shapes = new std::list<Shape *>();
    shapes->push_back(&r1);
    shapes->push_back(&c1);
    shapes->push_back(&t1);
    
    std::list<Shape *>::iterator it = shapes->begin();
    
    ASSERT_NEAR(12, (*it++)->area(),0.01);
    ASSERT_NEAR(78.53, (*it++)->area(),0.01);
    ASSERT_NEAR(18, (*it++)->area(),0.01);
    
    Sort::sortByIncreasingArea(shapes);
    it = shapes->begin();

    ASSERT_NEAR(78.53, (*it++)->area(),0.01);
    ASSERT_NEAR(18, (*it++)->area(),0.01);
    ASSERT_NEAR(12, (*it++)->area(),0.01);

}

TEST (Sort, sortByDecreasingArea) {
    
    Rectangle r1(0, 0, 4, 3);      
    Circle c1(0, 0, 5);
    vertex v1,v2,v3;
    v1.x = 0;
    v1.y = 0;
    v2.x = 4;
    v2.y = 4;
    v3.x = 9;
    v3.y = 0;
    Triangle t1(v1,v2,v3,"");
    
    std::list<Shape *> *shapes = new std::list<Shape *>();
    shapes->push_back(&r1);
    shapes->push_back(&c1);
    shapes->push_back(&t1);
    
    std::list<Shape *>::iterator it = shapes->begin();
    
    ASSERT_NEAR(12, (*it++)->area(),0.01);
    ASSERT_NEAR(78.53, (*it++)->area(),0.01);
    ASSERT_NEAR(18, (*it++)->area(),0.01);
    
    Sort::sortByDecreasingArea(shapes);
    it = shapes->begin();

    ASSERT_NEAR(12, (*it++)->area(),0.01);
    ASSERT_NEAR(18, (*it++)->area(),0.01);
    ASSERT_NEAR(78.53, (*it++)->area(),0.01);

}

TEST (Sort, sortByIncreasingCompactness) {
    
    Rectangle r1(0, 0, 4, 3);      
    Circle c1(0, 0, 10);
    vertex v1,v2,v3;
    v1.x = 0;
    v1.y = 0;
    v2.x = 4;
    v2.y = 4;
    v3.x = 9;
    v3.y = 0;
    Triangle t1(v1,v2,v3,"");
    
    std::list<Shape *> *shapes = new std::list<Shape *>();
    shapes->push_back(&r1);
    shapes->push_back(&c1);
    shapes->push_back(&t1);
    
    std::list<Shape *>::iterator it = shapes->begin();
    
    ASSERT_NEAR(14, (*it++)->perimeter(),0.01);
    ASSERT_NEAR(62.83, (*it++)->perimeter(),0.01);
    ASSERT_NEAR(21.05, (*it++)->perimeter(),0.01);
    
    Sort::sortByIncreasingCompactness(shapes);
    it = shapes->begin();

    ASSERT_NEAR(21.05, (*it++)->perimeter(),0.01);
    ASSERT_NEAR(14, (*it++)->perimeter(),0.01);
    ASSERT_NEAR(62.83, (*it++)->perimeter(),0.01);

}

#endif
