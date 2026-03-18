#include "../includes/easyfind.hpp"

int main(void)
{
    std::vector<int> vect;
    std::vector<int>::iterator vect_it;
    vect.push_back(0);
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);
    vect.push_back(5);
    vect.push_back(4);
    vect.push_back(3);
    vect.push_back(2);
    vect.push_back(1);
    vect.push_back(0);
    vect_it = vect.end();

    std::deque<int> deq;;
    std::deque<int>::iterator deq_it;
    deq.push_back(9);
    deq.push_back(8);
    deq.push_back(7);
    deq.push_back(6);
    deq.push_back(5);
    deq.push_back(4);
    deq.push_back(3);
    deq.push_back(2);
    deq.push_back(1);
    deq.push_back(0);
    deq_it = deq.end();

    std::list<int> myList;
    std::list<int>::iterator myList_it;
    myList.push_back(9);
    myList.push_back(8);
    myList.push_back(7);
    myList.push_back(6);
    myList.push_back(5);
    myList.push_back(6);
    myList.push_back(7);
    myList.push_back(8);
    myList.push_back(9);
    myList_it = myList.end();

    try
    { 
        vect_it = easyfind(vect, 7);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    if (vect_it != vect.end())
    {
        std::cout << "Value found in vector" << std::endl;
    }

    try
    { 
        deq_it = easyfind(deq, 7);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    if (deq_it != deq.end())
    {
        std::cout << "Value found in double-ended queue" << std::endl;
    }

    try
    { 
        myList_it = easyfind(myList, 7);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    if (myList_it != myList.end())
    {
        std::cout << "Value found in list" << std::endl;
    }
}