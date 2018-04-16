#include <vector>
#include <iostream>
#include <stack>
#include "task3.hpp"
#include "utility.hpp"


// find max rectangle given the count
int get_max_rectangle(std::vector<int>& count, int& max_column, int& max_width, int& max_height )
{
    int max_area = 0;
    int current_column, top_column;
    int left_boundary, right_boundary, area;
 
    std::stack<int> column;
    column.push(0);
 
    
    for (int i=1; i < count.size(); i++)
    {
 
        while (column.empty() == false)
        {
            top_column = column.top(); 
 
            if ( count[i] > count[column.top()] )
            {
                column.push (i);
                break;
            }else
            {
                // count[i] is not larger than column.top()
                 
                current_column = column.top(); 
                column.pop();
     
                // stack top is the leftmost boundary of the rectangle containing current_column if the stack is not empty
                // otherwise, the leftmost boundary is 0
                left_boundary = column.empty() ? 0 : column.top(); 

                // since we only consider max rectangle starts at current_column
                // rightmost boundary is determined
                right_boundary = (count[top_column] == count[i]) ? i : i-1;
     
                area = (right_boundary - left_boundary) * count[top_column];
                if (area > max_area)
                {
                    max_area = area;
                    max_width = right_boundary - left_boundary;
                    max_height = count[top_column];
                    max_column = right_boundary;
                }
            }
        }
        
        if (column.empty())
            column.push (i);
    }
 
    // empty the remaining stack
    right_boundary = count.size() - 1;
    while (!column.empty())
    {
        top_column = column.top();
        column.pop();
        left_boundary = column.empty() ? 0 : top_column;
        area = (right_boundary - left_boundary + 1) * count[top_column];
        if (area > max_area)
        {
            max_area = area;
            max_width = right_boundary - left_boundary + 1;
            max_height = count[top_column];
            max_column = right_boundary;
        }
    }
    return max_area;
}
// task 3:
// input: two dimensional vector height which represents a two dimneionsal grid (num_row * num_column)
//        and a height h to search for a maximum square whose cells all have height of h in the grid
// output: display "Task 1: r1 c1 r2 c2" 
//         where r1 is the row id and c1 is the column id of the upper left corner of the maximum rectangle 
//         and r2 is the row id and c2 is the column id of the lower right corner of the maximum rectangle
void task3(int num_row, int num_column, std::vector<std::vector<int> >& height, int h)
{
    std::vector<int> count1(num_column,0);
    std::vector<int> count2(num_column,0);
    int i, j, k;
    int rectangle_width = 0, rectangle_height, rectangle_area;
    int max_rectangle_width = 0, max_rectangle_row = -1, max_rectangle_column = -1, max_rectangle_area = 0, max_width = -1, max_height = -1, rectangle_column;
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
        rectangle_area = get_max_rectangle(count2, rectangle_column, rectangle_width, rectangle_height);
        if (rectangle_area > max_rectangle_area)
        {
            max_rectangle_area = rectangle_area;
            max_width = rectangle_width;
            max_height = rectangle_height;
            max_rectangle_row = i;
            max_rectangle_column = rectangle_column;
        }
    }
    display_rectangle(3, max_rectangle_row, max_rectangle_column, max_width, max_height);
}
