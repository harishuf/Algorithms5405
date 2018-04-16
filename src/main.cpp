#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"
#include "task4.hpp"
//#include "task4.hpp"

void show_usage(const std::string& program)
{
    std::cout << "Usage: " << program << " n" << std::endl;
    std::cout << "n: an integer between 1 and 4" << std::endl;
}

int main(int argc, char* argv[])
{
    // get program name
    std::string program(argv[0]);
    if (2 != argc)
    {
        // show correct usage to run the program
        show_usage(program);
        return 0;
    }
    std::stringstream ss(argv[1]);
    int task;
    // get the number of task to perform
    ss >> task;
    if (task < 1 || task > 4)
    {
        // show correct usage to run the program if the task number is not valid
        show_usage(program);
        return 0;
    }
    int i, j, num_row, num_column, C; 
    // first read num_row, num_column, and C from user input
    std::cin >> num_row >> num_column >> C;
    std::vector<std::vector<int> > height(num_row, std::vector<int>(num_column));
    // read height matrix
    for (i = 0; i < num_row; i++)
    {
        for (j = 0; j < num_column; j++)
        {
            std::cin >> height[i][j];
        }
    }
/*
    for (i = 0; i < num_row; i++)
    {
        for (j = 0; j < num_column; j++)
        {
            std::cout << " " << height[i][j];
        }
        std::cout << std::endl;
    }
*/
    // perform the task
    switch (task)
    {
        case 1:
            task1(num_row, num_column, height, C);
            break;
        case 2:
            task2(num_row, num_column, height, C);
            break;
        case 3:
            task3(num_row, num_column, height, C);
            break;
        case 4:
            task4(num_row, num_column, height, C);
            break;
    }
    return 0;
}
