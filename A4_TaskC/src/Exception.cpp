#include "Exception.h"

std::string Exception::getMessage()  {
    if(msg.empty()) {
    std::string msg = "An error occured.";
    }
    return msg;
}

void Exception::setMessage(std::string _msg) {
    msg = _msg;
}
