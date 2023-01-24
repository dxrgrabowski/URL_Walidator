#include <iostream>
#include <string>
#include "InputParser.hpp"
#include "Validator.hpp"
#include "OutputHandler.hpp"


int main() {
    InputParse parse;
    Validator validate(parse.addresses);
    OutputHandler output(validate.logs, parse);
}
