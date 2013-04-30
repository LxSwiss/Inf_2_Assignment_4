#ifndef __TaskC__Exception__
#define __TaskC__Exception__

#include <iostream>

class Exception {
public:
    void setMessage(std::string msg);
    std::string getMessage();
private:
    std::string msg;
};

#endif /* defined(__TaskC__Exception__) */
