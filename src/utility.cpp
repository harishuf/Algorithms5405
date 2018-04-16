#include <iostream>

//input: task number, row and column for the lower right corner, and side length of a square
//output: display the row and column for upper left corner
//             and the row and column for lower right corner of the square
//comment: due to the read of input, lower right corner has the maximum row and column
void display_rectangle(int task, int row, int column, int side_length)
{
    // increase row and column by 1 since the index starts from 0 in program while it starts from 1 in project handout
    row++;
    column++;
    if (0 == row || 0 == column)
    {
        // no rectangle is found, i.e., the rectangle is 0
        std::cout << " no such squares as required." << std::endl;
        //std::cout << "Task " << task << ":" << " no such squares as required." << std::endl;
    }else
    {
        std::cout << row- side_length + 1 << " " << column- side_length + 1 << " " << row<< " " << column<< std::endl;
        //std::cout << "Task " << task << ": " << row- side_length + 1 << " " << column- side_length + 1 << " " << row<< " " << column<< std::endl;
    }
}

//input: task number, row and column for the lower right corner, width and height of a rectangle
//output: display the row and column for upper left corner
//             and the row and column for lower right corner of the rectangle 
void display_rectangle(int task, int row, int column, int width, int height)
{
    // increase row and column by 1 since the index starts from 0 in program while it starts from 1 in project handout
    row++;
    column++;
//    std::cout << "display_rectangle, task = " << task << ", row = " << row << ", column = " << column << ", width = " << width << ", height = " << height << std::endl;
    if (0 == row || 0 == column)
    {
        // no rectangle is found, i.e., the rectangle is 0
        //std::cout << "Task " << task << ":" << " no such rectangles as required." << std::endl;
        std::cout << " no such rectangles as required." << std::endl;
    }else
    {
        std::cout << row- height + 1 << " " << column- width + 1 << " " << row<< " " << column<< std::endl;
    }
}
