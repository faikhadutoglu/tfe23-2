#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

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
    fmt::print("Value of argv[0], {}!\n", argv);
    fmt::print("Value of argv[2], {}!\n", argv);
    fmt::print("The value of counter {}!\n", counter);
    /* INSERT YOUR CODE HERE */

    return 42; /* exit gracefully*/
}
