#include <vector>
#include <iostream>
#include "task1.hpp"
#include "utility.hpp"

// task 1:
// input: two dimensional vector height which represents a two dimneionsal grid (num_row * num_column)
//        and a height h to search for a maximum square whose cells all have height of h in the grid
// output: display "Task 1: r1 c1 r2 c2" 
//         where r1 is the row id and c1 is the column id of the upper left corner of the maximum square 
//         and r2 is the row id and c2 is the column id of the lower right corner of the maximum square 
void task1(int num_row, int num_column, std::vector<std::vector<int> >& height, int h)
{
    std::vector<int> side1(num_column,0);
    std::vector<int> side2(num_column,0);
    int i, j = 0;
    int max_side = 0;
    int max_side_row = -1, max_side_column = -1;
//        std::cout << "task1, i = " << i << std::endl;

    for (i = 0; i < num_row; i++)
    {
        // boundary conditions: no side2[j-1] when j=0
        if (height[i][0] == h)
        {
            side2[0] = 1;
            if (max_side < side2[0])
            {
                max_side = side2[0];
                max_side_row = i;
                max_side_column = 0;
            } 
        }else
        {
            side2[0] = 1;
        }
        // general calculation of side2[j] for j > 0
        for (j = 1; j < num_column; j++)
        {
//        std::cout << "     task1, j = " << j << ", height = " << height[i][j] << ", max_side = " << max_side << std::endl;
            if (height[i][j] == h)
            {
                side2[j] = 1 + std::min(side2[j-1], std::min(side1[j-1], side1[j]));
                // save max_side
                if (max_side < side2[j])
                {
                    max_side = side2[j];
                    max_side_row = i;
                    max_side_column = j;
                } 
            }else
            {
                side2[j] = 0;
            }
        }
        // save side2 as side1 for next ieration
        side1 = side2;
    }
//    std::cout << "max_side_row = " << max_side_row << ", max_side_column = " << max_side_column << ", max_side = " << max_side << std::endl;
    display_rectangle(1, max_side_row, max_side_column, max_side);
}
