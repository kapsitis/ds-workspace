#ifndef DS_CIRCULARLIST_H
#define DS_CIRCULARLIST_H

#include <string>

namespace ds_course
{

    class CLNode
    {
    private:
        int info;
        CLNode *prev;
        CLNode *next;
    };

    class CircularList
    {
    private:
        CLNode* tail_;
        int size;
    public:
        CircularList();
        ~CircularList();
        bool isEmpty() const;
        int &head() const;
        int &tail() const;
        void insertAt(int pos, int val);
        void eraseAt(int pos);
        void assignAt(int pos, int val);
        void moveNext();
        void movePrev();
        void pushFront(int val);
        void popFront();
        std::string toString();
        int getSize();
    };
}

#endif