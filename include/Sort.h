#include <list>
#include "Shapes.h"

bool sortIncreasingPerimeter(Shape * c,Shape *r){
    return c->perimeter() < r->perimeter();
}
bool sortDecreasingPerimeter(Shape * c,Shape *r){
    return c->perimeter() > r->perimeter();
}
bool sortIncreasingArea(Shape * c,Shape *r){
    return c->perimeter() < r->perimeter();
}
bool sortDecreasingArea(Shape * c,Shape *r){
    return c->perimeter() > r->perimeter();
}
bool sortIncreasingCompactness(Shape * c,Shape *r){
    return (c->area()/c->perimeter()) > (r->area()/r->perimeter());
}
class Sort {

  public :static void sortByIncreasingPerimeter(std::list<Shape *> * shapeList){
      shapeList->sort(sortIncreasingPerimeter);
  }

  public :static void sortByDecreasingPerimeter(std::list<Shape *> * shapeList){
      shapeList->sort(sortDecreasingPerimeter);
  }

  public :static void sortByIncreasingArea(std::list<Shape *> * shapeList){
      shapeList->sort(sortIncreasingArea);
  }

  public :static void sortByDecreasingArea(std::list<Shape *> * shapeList){
      shapeList->sort(sortDecreasingArea);
  }

  public :static void sortByIncreasingCompactness(std::list<Shape *> * shapeList){
      shapeList->sort(sortIncreasingCompactness);
  }

};
