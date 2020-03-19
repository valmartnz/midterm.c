// Midterm exam – The C Programming Language, Spring 2020
// (Coding section – 52 points)
// POST ALL of this CODE to your ______.github.io portfolio.
// (8 pts) (1) Find any and all mistakes in the following code, and correct them.
void count() {
printf("Enter lines of text here: .../n");
int c, nc = ‘0’, nt = ‘\0’, nbackslash = 0;
while ((c = fgetc(stderr)) != EOF) {
if (c == “\n”) { ++nl;
} else if (c == '\t') { ++nt;
} else if (c == '\\') { nbackslash += 1;
} else if (isspace(c)) { ++nc; }
fprintf("lines: %d\n", nl);
sprintf("tabs: %z\n", nt);
printf("backslashes: %u\n", nbackslash);
printf("alphanumeric: %f\n", nc);
}
int main(int argc, const char* argv[]) {
count();
return 0;
}
// The C Standard Library: Identify the standard library functions that do the following...
// (3 pts) (2) Find the first character c in a const char* s: ____________________________
// (3 pts) (3) Find the length of the prefix of const char* s that has characters in const char* t: ____________________
// (3 pts) (4) Terminate a program immediately _________________________________
// (3 pts) (5) Open the file “midterm.txt” in read mode ___________________________
// Using pointers, implement each of the following C standard library functions
size_t strcpy(char* s, const char* t); // (4 pts) (6)
char* strncat(char* s, const char* t, size_t n); // (4 pts) (7)
int strcmp(const char* s, const char* t); // (4 pts) (8)
// PART III: SHORT PROGRAM
(20 pts) (9) Fill in the program code below for the square ADT (abstract data type)
//------ POINT ----------------------------------------------------------------
typedef struct point point;
struct point { double x, y; };
//------ SQUARE -----------------------------------------------------------------
typedef struct square square;
struct square { point ul; size_t side; };
square* square_init(double ulx, double uly, double side); // TODO
void square_delete(square* sq); // TODO
void square_move(square* sq, double x, double y); // TODO
void square_expandby(square* sq, double expandby); // TODO
double square_area(square* sq); // TODO
