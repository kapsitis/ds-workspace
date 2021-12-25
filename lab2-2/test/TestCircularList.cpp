#include <string>
#include <stdexcept>
#include "catch.hpp"
#include "CircularList.h"

using namespace ds_course;
using namespace std;
TEST_CASE("Building a circlelist from individual items", "[circlelist]")
{
    CircularList<int> cL;
    REQUIRE(cL.toString() == "[]");
    cL.pushFront(2);
    REQUIRE(cL.getSize() == 1);
    REQUIRE(cL.toString() == "[2]");
    cL.pushFront(4);
    REQUIRE(cL.getSize() == 2);
    REQUIRE(cL.toString() == "[4, 2]");
    cL.pushFront(6);
    REQUIRE(cL.getSize() == 3);
    REQUIRE(cL.toString() == "[6, 4, 2]");
}


TEST_CASE("Some basic list operations", "[circlelist]")
{
    CircularList<int> cl;
    cl.pushFront(11);
    cl.moveNext();
    cl.pushFront(12);
    cl.moveNext();
    cl.pushFront(13);
    cl.moveNext();
    cl.pushFront(14);
    cl.moveNext();
    cl.pushFront(15);
    cl.moveNext();
    cl.pushFront(16);
    cl.moveNext();
    REQUIRE(cl.toString() == "[11, 12, 13, 14, 15, 16]");

    SECTION("Can advance 4 times") {
        for (int j = 0; j < 4; j++) 
            cl.moveNext();
        REQUIRE(cl.toString() == "[15, 16, 11, 12, 13, 14]");
    }

    SECTION("Insert at position 2") {
        cl.moveNext();
        cl.moveNext();
        REQUIRE(cl.toString() == "[13, 14, 15, 16, 11, 12]");
        cl.pushFront(1000);
        REQUIRE(cl.toString() == "[1000, 13, 14, 15, 16, 11, 12]");
        cl.moveNext();
        cl.moveNext();
        cl.moveNext();
        cl.moveNext();
        cl.moveNext();
        REQUIRE(cl.toString() == "[11, 12, 1000, 13, 14, 15, 16]");
    }

    SECTION("Delete at position 2") {
        cl.moveNext();
        cl.moveNext();
        REQUIRE(cl.toString() == "[13, 14, 15, 16, 11, 12]");
        cl.popFront();
        REQUIRE(cl.toString() == "[14, 15, 16, 11, 12]");
        cl.moveNext();
        cl.moveNext();
        cl.moveNext();
        REQUIRE(cl.toString() == "[11, 12, 14, 15, 16]");
    }

    SECTION("insert, then delete") {
        cl.pushFront(100);
        REQUIRE(cl.toString() == "[100, 11, 12, 13, 14, 15, 16]");
        cl.moveNext();
        cl.moveNext();
        cl.popFront();
        cl.moveNext();
        cl.moveNext();
        cl.moveNext();
        cl.moveNext();
        REQUIRE(cl.toString() == "[100, 11, 13, 14, 15, 16]");
    }

    SECTION("can delete everything")
    {
        cl.popFront();
        cl.popFront();
        cl.popFront();
        REQUIRE(cl.toString() == "[14, 15, 16]");
        cl.popFront();
        cl.popFront();
        cl.popFront();
        REQUIRE(cl.toString() == "[]");
        cl.pushFront(17);
        REQUIRE(cl.toString() == "[17]");
    }

    SECTION("can delete everything with clear()") {
        cl.clear(); 
        REQUIRE(cl.getSize() == 0); 
        REQUIRE(cl.toString() == "[]");
    }
}

TEST_CASE("Test Exceptional Conditions", "[circlelist]") {
    SECTION("Head of an empty list") {
        CircularList<int> empty; 
        REQUIRE_THROWS_AS(empty.head(), std::out_of_range); 
    }

    SECTION("Tail of an empty list") {
        CircularList<int> empty; 
        REQUIRE_THROWS_AS(empty.tail(), std::out_of_range); 
    }

    SECTION("popFront on an empty list") {
        CircularList<string> empty; 
        REQUIRE_THROWS_AS(empty.popFront(), std::out_of_range); 
    }

    SECTION("Insert at invalid position") {
        CircularList<int> a = {1,2,3};
        a.insertAt(3,100);
        REQUIRE(a.toString() == "[1, 2, 3, 100]");
        REQUIRE_THROWS_AS(a.insertAt(5,100), std::out_of_range); 
    }

    SECTION("Insert at negative position") {
        CircularList<int> a = {1,2,3};
        REQUIRE_THROWS_AS(a.insertAt(-1,100), std::out_of_range); 
    }

    SECTION("Erase at invalid position") {
        CircularList<int> a = {1,2,3};
        a.eraseAt(1);
        REQUIRE(a.toString() == "[1, 3]");
        REQUIRE_THROWS_AS(a.eraseAt(2), std::out_of_range); 
    }

    SECTION("Erase at negative position") {
        CircularList<int> a = {1,2,3};
        REQUIRE_THROWS_AS(a.eraseAt(-1), std::out_of_range); 
    }

    SECTION("Assign at invalid position") {
        CircularList<int> a = {1,2,3};
        a.assignAt(2,4);
        REQUIRE(a.toString() == "[1, 2, 4]");
        REQUIRE_THROWS_AS(a.assignAt(3,100), std::out_of_range); 
    }

    SECTION("Assign at negative position") {
        CircularList<int> a = {1,2,3};
        REQUIRE_THROWS_AS(a.assignAt(-1,100), std::out_of_range); 
    }
}

// A helper function to test copy-constructor for CircularList<int>
std::string getModifiedIntList(CircularList<int> arg) {
    arg.assignAt(2, 117);
    return arg.toString();
}


// A helper function to test copy-constructor for CircularList<string>
std::string getModifiedStringList(CircularList<std::string> arg) {
    arg.assignAt(2, "def");
    arg.head() = arg.head() + "xx";
    return arg.toString();
}


TEST_CASE("Constructors", "[circlelist]")
{
    SECTION("Create an empty list")
    {
        CircularList<int> a;
        REQUIRE(a.toString() == "[]");
    }

    SECTION("Create from initializer_list with ints")
    {
        CircularList<int> a1 = {};
        REQUIRE(a1.toString() == "[]");
        CircularList<int> a2 = {1};
        REQUIRE(a2.toString() == "[1]");
        CircularList<int> a3 = {2,3,4,5};
        REQUIRE(a3.toString() == "[2, 3, 4, 5]");
    }


    SECTION("Create from initializer_list with strings")
    {
        CircularList<string> a1 = {};
        REQUIRE(a1.toString() == "[]");
        CircularList<string> a2 = {"abc"};
        REQUIRE(a2.toString() == "[abc]");
        CircularList<string> a3 = {"a", "ab", "abc"};
        REQUIRE(a3.toString() == "[a, ab, abc]");
    }


    SECTION("Create list with identical int items") {
        CircularList<int> a3(5, 17);
        REQUIRE(a3.toString() == "[17, 17, 17, 17, 17]");
    }

    SECTION("Create list with identical string items") {
        CircularList<string> b3(5, "s");
        REQUIRE(b3.toString() == "[s, s, s, s, s]");
    }

    SECTION("Create an int list and then a copy-constructor") {
        CircularList<int> a3(5, 17);
        REQUIRE(a3.toString() == "[17, 17, 17, 17, 17]");
        string res = getModifiedIntList(a3);
        REQUIRE(res == "[17, 17, 117, 17, 17]");
        REQUIRE(a3.toString() == "[17, 17, 17, 17, 17]");
    }

    SECTION("Create a string list and then a copy-constructor") {
        CircularList<string> b3(5, "s");
        REQUIRE(b3.toString() == "[s, s, s, s, s]");
        string res = getModifiedStringList(b3);
        REQUIRE(res == "[sxx, s, def, s, s]");
        REQUIRE(b3.toString() == "[s, s, s, s, s]");
    }

    SECTION("Check overloaded assignment to empty list") {
        // check assignment
        CircularList<string> b4 = { "x", "a", "ab", "abc" };
        CircularList<string> b5 = b4;
        
        b4.assignAt(3, "def");
        REQUIRE(b4.toString() == "[x, a, ab, def]");
        REQUIRE(b5.toString() == "[x, a, ab, abc]");
        b5.moveNext();    
        REQUIRE(b5.toString() == "[a, ab, abc, x]");
        b5.moveNext();    
        REQUIRE(b5.toString() == "[ab, abc, x, a]");
    }

    SECTION("Check overloaded assignment to itself") {
        CircularList<string> b6 = { "x", "a", "ab", "abc" };
        REQUIRE(b6.toString() == "[x, a, ab, abc]");
        b6 = b6; 
        REQUIRE(b6.toString() == "[x, a, ab, abc]");
    }
}

TEST_CASE("Overloaded appending with + and reverse") {
    SECTION("Append two different lists") {
        CircularList<int> a1 = CircularList<int>(3, 17) + CircularList<int>{1,2,3};
        REQUIRE(a1.toString() == "[17, 17, 17, 1, 2, 3]");
    }

    SECTION("Prepend or append an empty list") {
        CircularList<int> empty; 
        CircularList<int> a1 = CircularList<int>(3, 17) + empty;
        REQUIRE(a1.toString() == "[17, 17, 17]");
        CircularList<int> a2 = empty + CircularList<int>(3, 18);
        REQUIRE(a2.toString() == "[18, 18, 18]");
    }

    SECTION("Append a list to itself") {
        CircularList<string> a3 = {"a", "bb", "ccc"};
        CircularList<string> a4 = a3 + a3; 
        REQUIRE(a4.toString() == "[a, bb, ccc, a, bb, ccc]");
        CircularList<string> a5 = a3.reverse() + a3; 
        REQUIRE(a5.toString() == "[ccc, bb, a, a, bb, ccc]");
    }   

    SECTION("Reverse an empty list") {   
        CircularList<string> empty;
        CircularList<string> cL2 = empty.reverse();
        REQUIRE(cL2.toString() == "[]");
    }

    SECTION("Reverse a one-element list") {   
        CircularList<string> cL1 = {"1"};
        CircularList<string> cL2 = cL1.reverse();
        REQUIRE(cL2.toString() == "[1]");
    }

    SECTION("Reverse a two-element list") {   
        CircularList<string> cL1 = {"1", "2"};
        CircularList<string> cL2 = cL1.reverse();
        REQUIRE(cL2.toString() == "[2, 1]");
        REQUIRE(cL1.toString() == "[1, 2]");
    }


    SECTION("Reverse a longer list") {   
        CircularList<int> c1 = { 1, 2, 3, 4, 5};
        REQUIRE(c1.toString() == "[1, 2, 3, 4, 5]");
        CircularList<int> c2 = c1.reverse();
        REQUIRE(c2.toString() == "[5, 4, 3, 2, 1]");
    }

    SECTION("Reverse and assign to itself") {
        CircularList<string> c1 = {"A","B","C"};
        c1 = c1.reverse();
        REQUIRE(c1.toString() == "[C, B, A]");
    }
}


CircularList<string> recursiveFun(CircularList<string> arg, int level) {
    arg.pushFront(to_string(level));
    if (level == 0) {
        return arg;
    }
    else {
        return recursiveFun(arg, level-1) + recursiveFun(arg, level-1);
    }
}

TEST_CASE("Additional Memory Leak Scenarios", "[circlelist]") {
    SECTION("Overloaded assignment to non-empty list") {
        // Can replace "100" with another value to see how leaks change
        CircularList<int> z1(100,17); 
        CircularList<int> z2 = {18}; 
        // this should free 100 CLNode<int> objects in the old list.
        z1 = z2; 
    }

    SECTION("Assign the sum of two identical lists to the list itself") {
        // Can replace "1000" with another value to see how leaks change
        CircularList<int> z1(1000,17); 
        // this should free 1000 CLNode<int> objects; replace with 2000 objects
        z1 = z1 + z1;
    }

    SECTION("A binary tree of copy-constructor calls ") {
        CircularList<string> s1 = {"a", "b", "c"};
        // Can replace level=2 with another value to see the change
        CircularList<string> s2 = recursiveFun(s1, 2);        
        REQUIRE(s2.toString() == "[0, 1, 2, a, b, c, 0, 1, 2, a, b, c, 0, 1, 2, a, b, c, 0, 1, 2, a, b, c]");
    }
}


TEST_CASE("Lists of lists", "[circlelist]") {
    SECTION("Building list of lists") {
        CircularList<CircularList<string>> masterList; 
        CircularList<string> sublist1; 
        sublist1.pushFront("A1");
        sublist1.moveNext();
        sublist1.pushFront("A2");
        sublist1.moveNext();
        masterList.pushFront(sublist1);
        masterList.moveNext();

        CircularList<string> sublist2; 
        sublist2.pushFront("B1");
        sublist2.moveNext();
        sublist2.pushFront("B2");
        sublist2.moveNext();
        masterList.pushFront(sublist2);
        masterList.moveNext();

        
        REQUIRE(masterList.head().toString() == "[A1, A2]");
        masterList.moveNext();
        REQUIRE(masterList.head().toString() == "[B1, B2]");
        masterList.head().pushFront("B3");
        REQUIRE(masterList.head().toString() == "[B3, B1, B2]");
    }
}
