#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"
#include "list"
#ifndef epsilon
    #define epsilon 0.00001
#endif // epsilon

TEST (Sort, sortByIncreasingPerimeter) {
     Rectangle r1(2, 7, 11,12);
     Rectangle r2(0, 0, 10,11);
     Rectangle r3(3, 8, 12, 21);

     std::list<Shape *> shapeList;
     //std::vector<Shape *>shapes;
     shapeList.push_back(&r1);
     shapeList.push_back(&r2);
     shapeList.push_back(&r3);

     Sort::sortByIncreasingPerimeter(&shapeList);
     std::list<Shape *>::iterator i = shapeList.begin();
     ASSERT_NEAR(42,(*i)->perimeter(), epsilon);
     i++;
     ASSERT_NEAR(46,(*i)->perimeter(), epsilon);
     i++;
     ASSERT_NEAR(66,(*i)->perimeter(), epsilon);
     i++;
}

TEST (Sort, sortByDecreasingPerimeter) {

     Rectangle r1(2, 7, 11,12);
     Rectangle r2(0, 0, 10,11);
     Rectangle r3(3, 8, 12, 21);

     std::list<Shape *> shapeList;
     //std::vector<Shape *>shapes;
     shapeList.push_back(&r1);
     shapeList.push_back(&r2);
     shapeList.push_back(&r3);

     Sort::sortByDecreasingPerimeter(&shapeList);
     std::list<Shape *>::iterator i = shapeList.begin();

     ASSERT_NEAR(66,(*i)->perimeter(), epsilon);
     i++;
     ASSERT_NEAR(46,(*i)->perimeter(), epsilon);
     i++;
     ASSERT_NEAR(42,(*i)->perimeter(), epsilon);
     i++;
     //ASSERT_NEAR(12,(*shapeList)->perimeter(), epsilon);
}

TEST (Sort, sortByIncreasingArea) {
     Rectangle r1(2, 7, 11,12);
     Rectangle r2(0, 0, 10,11);
     Rectangle r3(3, 8, 12, 21);

     std::list<Shape *> shapeList;
     //std::vector<Shape *>shapes;
     shapeList.push_back(&r1);
     shapeList.push_back(&r2);
     shapeList.push_back(&r3);

     Sort::sortByIncreasingArea(&shapeList);
     std::list<Shape *>::iterator i = shapeList.begin();

     ASSERT_NEAR(110,(*i)->area(), epsilon);
     i++;
     ASSERT_NEAR(132,(*i)->area(), epsilon);
     i++;
     ASSERT_NEAR(252,(*i)->area(), epsilon);
     i++;
}

TEST (Sort, sortByDecreasingArea) {
     Rectangle r1(2, 7, 11,12);
     Rectangle r2(0, 0, 10,11);
     Rectangle r3(3, 8, 12, 21);

     std::list<Shape *> shapeList;
     //std::vector<Shape *>shapes;
     shapeList.push_back(&r1);
     shapeList.push_back(&r2);
     shapeList.push_back(&r3);

     Sort::sortByDecreasingArea(&shapeList);
     std::list<Shape *>::iterator i = shapeList.begin();

     ASSERT_NEAR(252,(*i)->area(), epsilon);
     i++;
     ASSERT_NEAR(132,(*i)->area(), epsilon);
     i++;
     ASSERT_NEAR(110,(*i)->area(), epsilon);
     i++;
}

TEST (Sort, sortByIncreasingCompactness) {
     Rectangle r1(2, 7, 11,12);
     Rectangle r2(0, 0, 10,11);
     Rectangle r3(3, 8, 12, 21);

     std::list<Shape *> shapeList;
     //std::vector<Shape *>shapes;
     shapeList.push_back(&r1);
     shapeList.push_back(&r2);
     shapeList.push_back(&r3);

     Sort::sortByIncreasingCompactness(&shapeList);
     std::list<Shape *>::iterator i = shapeList.begin();

     ASSERT_NEAR(252,(*i)->area(), epsilon);
     i++;
     ASSERT_NEAR(132,(*i)->area(), epsilon);
     i++;
     ASSERT_NEAR(110,(*i)->area(), epsilon);
     i++;
}

#endif

