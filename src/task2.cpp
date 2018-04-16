#include <vector>
#include <iostream>
#include "task2.hpp"
#include "utility.hpp"

// task 2:
// input: two dimensional vector height which represents a two dimneionsal grid (num_row * num_column)
//        and a height h to search for a maximum square whose cells all have height of h in the grid
// output: display "Task 1: r1 c1 r2 c2" 
//         where r1 is the row id and c1 is the column id of the upper left corner of the maximum rectangle 
//         and r2 is the row id and c2 is the column id of the lower right corner of the maximum rectangle
void task2(int num_row, int num_column, std::vector<std::vector<int> >& height, int h)
{
    std::vector<int> count1(num_column,0);
    std::vector<int> count2(num_column,0);
    int i, j, k;
    int rectangle_width = 0, rectangle_area;
    int max_rectangle_width = 0, max_rectangle_row = -1, max_rectangle_column = -1, max_rectangle_area = 0, max_width = -1, max_height = -1, rectangle_column;
//    std::cout << "task2, h = " << h << std::endl;
    for (i = 0; i < num_row; i++)
    {
        // calculate count for row i which is the number of consecutive cells including cell (i, j)
        // and having a height of h such tath Height[i - count[i][j]] != C
        for (j = 0; j < num_column; j++)
        {
            if (h == height[i][j])
            {
                count2[j] = count1[j] + 1;
            }else
            {
                count2[j] = 0;
            }
        }
        // save count2 for next iteration
        count1 = count2;
        // find the maximum rectangle for each column j
        // such that the height of that maximum rectangle is h
        for (j = 0; j < num_column; j++)
        {
            if (h != height[i][j])
            {
                // no rectangles exist so continue next column
                continue;
            }
            rectangle_width = 1;
            // first find the left consecutive cells in the maximum rectangle
            for (k = j-1; k >-1; k--)
            {
                if (count2[k] >= count2[j])
                {
                    // increase rectangle_width by one
                    rectangle_width++;
                }else
                {
                    // stop search on the left
                    break;
                }
            }
            // then find the right consecutive cells in the maximum rectangle
            rectangle_column = j;
            for (k = j+1; k < num_column; k++)
            {
                if (count2[k] >= count2[j])
                {
                    // increase rectangle_width by one
                    rectangle_width++;
                    rectangle_column = k;
                }else
                {
                    // stop search on the right
                    break;
                }
            }
            rectangle_area = rectangle_width * count2[j];
//            std::cout << "i = " << i << ", j = " << j << ", rectangle_width = " << rectangle_width << ", rectangle_height = " << count2[j] << ", max_rectangle_area = " << max_rectangle_area << ", rectangle_area = " << rectangle_area <<  std::endl;
            if (rectangle_area > max_rectangle_area)
            {
                // save the bigger rectangle
                max_width = rectangle_width;
                max_height = count2[j];
                max_rectangle_area = rectangle_area;
                max_rectangle_row = i;
                max_rectangle_column = rectangle_column ;
            }
//    std::cout << "=======max_rectangle_row = " << max_rectangle_row << ", max_rectangle_column = " << max_rectangle_column << ", max_width = " << max_width << ", max_height = " << max_height << std::endl;
        }
    }
//    std::cout << "max_rectangle_row = " << max_rectangle_row << ", max_rectangle_column = " << max_rectangle_column << ", max_width = " << max_width << ", max_height = " << max_height << std::endl;
    display_rectangle(2, max_rectangle_row, max_rectangle_column, max_width, max_height);
}
