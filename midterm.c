// Midterm exam – The C Programming Language, Spring 2020
// (Coding section – 52 points)
// POST ALL of this CODE to your ______.github.io portfolio.
// (8 pts) (1) Find any and all mistakes in the following code, and correct them.

void count() {
 printf("Enter lines of text here: .../n");
 int c, nc = 0, nt = 0, nbackslash = 0, nl = 0;
 while ((c = getchar()) != EOF) {
 if (c == '\n') { ++nl;
 } else if (c == '\t') { ++nt;
 } else if (c == '\\') { ++nbackslash;
 } else if (isalnum(c)) { ++nc; }
 printf("lines: %d\n", nl);
 printf("tabs: %d\n", nt);
 printf("backslashes: %d\n", nbackslash);
 printf("alphanumeric: %d\n", nc);
}
int main(int argc, const char* argv[]) {
 count();
 return 0;
}


// The C Standard Library: Identify the standard library functions that do the following…
// (3 pts) (2) Find the first character c in a const char* s: char *strchr(const char* s, char c);
// (3 pts) (3) Find the length of the prefix of const char* s that has characters in const char* t: size_t strspn(const char* s,cconst char* t);
// (3 pts) (4) Terminate a program immediately: exit();
// (3 pts) (5) Open the file “midterm.txt” in read mode: fopen("midterm.txt", "r");


// Using pointers, implement each of the following C standard library functions

char* strcpy(char* s, const char* t) { // (4 pts) (6)
  char* p = s;
  while((*s++ = *t++) != '\0') { }
  return p;
}

char* strncat(char* s, const char* t, size_t n) { // (4 pts) (7)
  char* p = s;
  while(*s != '\0') { ++s; }
  while(n-- > 0 && *t != '\0') { *s++ = *t++; }
  *s = '\0';
  return p;
}

int strcmp(const char* s, const char* t) { // (4 pts) (8)
  while(*s != '\0' && *t != '\0' && *s == *t) {
    ++s;
    ++t;
  }
  return *s - *t;
}


// PART III: SHORT PROGRAM
//(20 pts) (9) Fill in the program code below for the square ADT (abstract data type)
//------ POINT ----------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct point point;
struct point { double x, y; };
//------ SQUARE -----------------------------------------------------------------
typedef struct square square;
struct square { point ul; size_t side; };

square* square_init(double ulx, double uly, double side);
void square_delete(square* sq);
void square_move(square* sq, double x, double y);
void square_expandby(square* sq, double expandby);
double square_area(square* sq);
double square_perimeter(square* r);

// print location, side, area and perimeter
void square_print(const char* msg, square* sq);

square* square_init(double ulx, double uly, double side) {
  point* pt1 = (point*)malloc(sizeof(point));
  point* pt2 = (point*)malloc(sizeof(point));

  pt1->x = ulx;
  pt2->y = uly;

  square* square_;
  square_->ul = (*pt1);
  square_->side = side;

  return square_;
}

void square_delete(square* sq) { free(sq); }

void square_move(square* sq, double x, double y) {
  pt->x = x;
  sq->ul = y;
}

void square_expandby(square* sq, double expandby) {
  sq->side *= 10;
}

double square_area(square* sq) {
  double side_ = sq->side;
  return (side_ * side_);
}

double square_perimeter(square* r){
  double side_ = r->side;
  return (4 * side_);
}

void square_print(const char* msg, square* sq) {
  printf("%s\n", msg);
  printf("Location: lf\nSide: %zu\nArea: %lf\nPerimeter: %lf\n", sq->side, square_area(sq), square_perimeter(sq));
}


void test_square(double ulx, double uly, double side) {
 square* sq = square_init(ulx, uly, side);
 square_print("sq is: ", sq);
 square_move(sq, 2, 2);
 square_print("sq is now: ", sq);
 square_expandby(sq, 10);
 square_print("sq has expanded to: ", sq);
 square_delete(sq);
 printf("\n\n");
}

void tests_square() {
 test_square(0, 0, 10);
 test_square(1, 1, 5);
}
int main(int argc, const char* argv[]) {
 tests_square();
 return 0;
}
