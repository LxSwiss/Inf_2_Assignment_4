#include "EmptyContainerException.h"


std::string EmptyContainerException::getMessage() {
    Exception::setMessage("ERROR: Your container is empty!");
    return Exception::getMessage();
}
