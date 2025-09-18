//
// Created by regal on 9/17/25.
//

#ifndef REDISKNOCKOFF_USERINPUT_H
#define REDISKNOCKOFF_USERINPUT_H

#include <utility>
#include <string>
#include <iostream>
#include <limits>

namespace UserInput
{
    std::pair<std::string, std::string> getKeyValue();
    std::string getKey();
    std::string getInstance();
    char yesOrNo();
    int getCommand();
}

#endif //REDISKNOCKOFF_USERINPUT_H