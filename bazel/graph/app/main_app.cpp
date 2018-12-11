#include "input_parser/input_parser.h"
#include "logger/logger.h"
#include "op_gen/op_gen.h"


int main(int argc, char const *argv[])
{
    logger log("main_app");
    log.error(input());
    return 0;
}
