#ifndef __TaskC__EmptyContainerException__
#define __TaskC__EmptyContainerException__

#include <iostream>
#include "Exception.h"

class EmptyContainerException : Exception {
public:
    std::string getMessage();
};

#endif /* defined(__TaskC__EmptyContainerException__) */
