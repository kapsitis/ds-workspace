#ifndef DS_CIRCULARLIST_H
#define DS_CIRCULARLIST_H

#include <string>

namespace ds_course {
class OutOfBoundsException {
    public:
    OutOfBoundsException(const std::string& msg) : msg_(msg) {}
    ~OutOfBoundsException() {}
    std::string getMessage() const { return(msg_); }
    private:
    std::string msg_;
};

class CircularList {
    public:
    CircularList();
    ~CircularList();
    bool empty() const;
    const int& front() const;
    const int& back() const;
    void advance();
    void retreat();
    void add(const int& e);
    void remove();
    std::string to_str();
    int getSize();
    private:
    int* elts;
    int size;
    int cursor; 
};
}


#endif