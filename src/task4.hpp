#ifndef TASK4_HPP
#define TASK4_HPP

#include<vector>

int abs(int t);
int max(int a, int b);
int min(int a, int b);
void fill(int* arr, int len);
void arrcopy(int* src, int* dst, int len);
void task4(int num_row, int num_column, std::vector<std::vector<int> >& height, int C);
#endif
