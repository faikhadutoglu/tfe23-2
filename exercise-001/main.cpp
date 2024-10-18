#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include <vector> // 

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    auto counter{20}; /*set a default of 20*/
    CLI::App app{PROJECT_NAME}; /*create an instance of an app with the variable name app*/
    try
    {
        //int count = 20;
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));/*Add an command line option -c or --count and fill the variable counter*/
        app. add_option("-c,--count", counter, "How many items to insert");  //kommandozeile eingabe eigenschafthinzugefügt
        app.parse(argc, argv); 
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
        //int foo = counter ; //undefiniert counter gillt nur innerhalb des try-blocks
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());
    fmt::print("Value of argc, {}!\n", argc);
    //fmt::print("Value of argv[0], {}!\n", argv);
   // fmt::print("Value of argv[2], {}!\n", argv); // /*possible nullpointer exception*/
    fmt::print("The value of counter {}!\n", counter);
    /* INSERT YOUR CODE HERE */


    std::vector<unsigned int> values;
    fmt::print("Elements in values, {}!\n",values.size()); //shows the number of elements in container(vektor)
    values.push_back(42);
    values.push_back(4711);
    values.push_back(11);
    fmt::print("Elements in values, {}!\n",values.size());
    for(int i =0; i < values.size(); i++){
        fmt::print("Value of element {} in values:{}!\n", i,values[i]);

    }
    return 0; /* exit gracefully*/
}











/*	1.	fmt::print("Hello, {}!\n", app.get_name());:
	•	Gibt den Namen der App aus, {} wird durch den App-Namen ersetzt.
	2.	fmt::print("Value of argc, {}!\n", argc);:
	•	Gibt die Anzahl der Kommandozeilenargumente aus.
	3.	fmt::print("Value of argv[0], {}!\n", argv);:
	•	Zeigt den Namen des Programms an.
	4.	fmt::print("Value of argv[2], {}!\n", argv);:
	•	Versucht, das dritte Argument(wie viele zusammengeschriebene ketten ohne leerzeichen) auszugeben, aber vorsichtig, falls es nicht vorhanden ist.
	5.	fmt::print("The value of counter {}!\n", counter);:
	•	Gibt den Wert von counter aus (Standard 20, kann durch -c geändert werden).*/