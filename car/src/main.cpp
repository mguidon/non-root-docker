#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <fstream>
#include <stdlib.h> 
#include <time.h> 

#include "cxxopts.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Reiceved the following command line line arguments" << std::endl;
    
    for(int i = 0; i < argc; ++i)
    {
        std::cout << argv[i] << std::endl;
    }
	
    cxxopts::Options options("Docker non root", "I am lazy");

    options.add_options()
        ("in_1", "input file", cxxopts::value<std::string>())
        ("out_1","output file", cxxopts::value<std::string>());

    auto result = options.parse(argc, argv);

    srand (time(NULL));

    
    if (result.count("in_1"))
    {
        int in_1 = 0;
        std::string in1_filename = result["in_1"].as<std::string>();
        std::fstream input(in1_filename, std::ios_base::in);
        input >> in_1;
        input.close();
        std::cout << "in_1:\t" << in1_filename << ":" << in_1 << std::endl;
    }
    std::string out_1_filename;
    if (result.count("out_1"))
    {
        out_1_filename = result["out_1"].as<std::string>();
        std::cout << "out_1:\t" << out_1_filename << std::endl;
        std::ofstream output;
        output.open(out_1_filename);
        output <<  "output" << std::endl;
        output.close();
    }

    return 0;
}
