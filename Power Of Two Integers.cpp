#include <cmath>
int Solution::isPower(int A) {
if (A == 1) {
// << "Inside if A == 1";
return 1;
}
int limit = sqrt(A);
for (int a = 2; a <= limit; a++) {
for (int p = 2; p<=32; p++) {
int powerResult = pow(a, p);
if (powerResult == A) {
return 1;
}
if (powerResult < A) {
continue;
}
break;
}
}
return 0;
}
