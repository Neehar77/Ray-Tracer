#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
 

std::ifstream file("C:/Users/baap1/Desktop/Project1_Graphics/project1/trace/balls-3.nff");  /* scope resolution operator */
std::string line;
while(std::getline(file, line))
{
    std::isstringstream iss(line);
    int a, b;
    if(!(iss >> a >> b)){ break; } //error
    std::cout << "Hello" << std::endl;
    //process pair (a, b)
}
