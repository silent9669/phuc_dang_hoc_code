#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/*
int calculate_power(int n, int e)
{
  if (e == 1) return n;
  return n * calculate_power(n, e - 1);
}
*/

/*
int gcdRecursion(int p, int q)
{
    // BEGIN YOUR IMPLEMENTATION [1]
    if (q == 0) {
        return p;
    }
    return gcdRecursion(q, p % q);
    // END YOUR IMPLEMENTATION [1]
}

int gcdIteration(int p, int q)
{
    // BEGIN YOUR IMPLEMENTATION [2]
    while (q != 0) {
        int r = p % q;
        p = q;
        q = r;
    }
    return p;
    // END YOUR IMPLEMENTATION [2]
}
*/

int strLen(char *str) {
  if (*str == '\0')
    return 0;
  return 1 + strLen(1 + str);
}
