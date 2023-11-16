/*==============================================================================
FILE NAME: d_ll.h
AUTHOR: LINOSH KURIAN MALAYIL
CREATED: 15 October 2023 08∶22∶10 PM
CONTAINS:
Contains class prototype for Double Linked List functions
==============================================================================*/

#ifndef D_LL_H
#define D_LL_H

/*------------------------------------------------------------------------------
                            START: Includes
------------------------------------------------------------------------------*/
#include <iostream>
#include <stdexcept>
/*------------------------------------------------------------------------------
                            END: Includes
------------------------------------------------------------------------------*/

/*******************************************************************************
                            START: Node Class
*******************************************************************************/
template <typename T>
class Node
{
        unsigned int index;
        T data;
        Node<T> *prev;
        Node<T> *next;
    public:
        Node(unsigned int const &,T const &);
        unsigned int get_index();
        void set_index(unsigned int const &);
        void set_prev(Node<T> *ptr);
        void set_next(Node<T> *ptr);
        Node<T>* get_prev();
        Node<T>* get_next();
        T get_data();
};
/*******************************************************************************
                            END: Node Class
*******************************************************************************/

/*******************************************************************************
                        START: DoubleLinkedList Class
*******************************************************************************/
template <typename T>
class DoubleLinkedList
{
        unsigned int size;
        Node<T> *start;
        void update_index();
    public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        bool insert(T const &);
        bool remove(T const &);
        bool display_list();
        unsigned int get_size();
        T operator[](unsigned int const &);
};
/*******************************************************************************
                        END: DoubleLinkedList Class
*******************************************************************************/

/*******************************************************************************
            START: Member Function Definitions of Node Class
*******************************************************************************/
template <typename T> Node<T>::Node(unsigned int const &idx,T const &init_data)
:index(idx), data(init_data)
{   //Constructor of Node
    prev = nullptr;
    next = nullptr;
}

template <typename T> inline void Node<T>::set_index(unsigned int const &idx)
{
    index = idx;

    return;
}

template <typename T> inline unsigned int Node<T>::get_index()
{
    return index;
}

template <typename T> inline void Node<T>::set_prev(Node<T> *ptr)
{   //Function to set the prevous node pointer
    prev = ptr; 

    return;
}

template <typename T> inline void Node<T>::set_next(Node<T> *ptr)
{   //Function to set the next node pointer
    next = ptr; 
    
    return;
}

template <typename T> inline Node<T>* Node<T>::get_prev()
{   //Function to return the prevous node pointer
    return prev;
}

template <typename T> inline Node<T>* Node<T>::get_next()
{   //Function to return the next node pointer
    return next; 
}

template <typename T> inline T Node<T>::get_data()
{   //Function to return the value in node
    return data;
}
/*******************************************************************************
            END: Member Function Definitions of Node Class
*******************************************************************************/

/*******************************************************************************
        START: Member Function Definitions of DoubleLinkedList Class
*******************************************************************************/
template <typename T> DoubleLinkedList<T>::DoubleLinkedList()
{   //Constructor of DoubleLinkedList
    size = 0;
    start = nullptr;
}

template <typename T> DoubleLinkedList<T>::~DoubleLinkedList()
{
    while(nullptr != start)
    {   
        std::cout << "Cleaning up allocated memory!\n";

        Node<T> *temp = start;
        start = start -> get_next();
        
        delete temp;
    }
}

template <typename T> void DoubleLinkedList<T>::update_index()
{
    Node<T> *temp = start;
    
    unsigned int count = 0;
    while(nullptr != temp)
    {
        temp -> set_index(count++);
        temp = temp -> get_next();
    }

    if(count != size)
    {
        size = count;
    }

    return;
}

template <typename T> bool DoubleLinkedList<T>::insert(T const &data)
{   //Function to add new element to list
    Node<T> *node = new Node<T>(size++, data);
    
    if (nullptr == node)
    {   //Allocation failed, return
        return false;
    }
    else if (nullptr == start)
    {   //First node in the list
        start = node;
    }
    else
    {   //Subsequent elements
        Node<T> *temp = start;
        while(temp -> get_next() != nullptr)
        {   //Reach the end of list
            temp = temp -> get_next();
        }
        temp -> set_next(node);
        node -> set_prev(temp);
    }
    
    return true;
}

template <typename T> bool DoubleLinkedList<T>::remove(T const &data)
{   //Delete element from list based on value
    if(nullptr == start)
    {   //List is empty
        return true;
    }
    else if(data == start -> get_data() && nullptr == start -> get_next())
    {   //Only element in list
        delete start;
        size--;
        start = nullptr;
        
        return true;
    }
    else
    {
        Node<T> *temp = start;
        while (nullptr != temp)
        { 
            if(data == temp -> get_data())
            {   //Found the value
                Node<T> *del_node = temp;
                Node<T> *prev_node = del_node -> get_prev();
                Node<T> *next_node = del_node -> get_next();

                if(nullptr == prev_node)
                {   //First node
                    start = next_node;
                }
                else if(nullptr == next_node)
                {   //Last node
                    prev_node -> set_next(nullptr);
                }
                else
                {   //Middle node
                    prev_node -> set_next(next_node);
                    next_node -> set_prev(prev_node);
                }

                delete del_node;
                size--;
                update_index();

                return true;
            }
            temp = temp -> get_next();
        }
    }
    
    return false;
}

template <typename T> bool DoubleLinkedList<T>::display_list()
{   //Display the list
    Node<T> *temp = start;

    if(nullptr == start)
    {   //List is empty
        std::cout << "[]" << std::endl;
        return false;
    }
    
    std::cout << "[";
    while(nullptr != temp)
    {   //Loop through elements to display
        if(nullptr == temp -> get_next())
        {
            std::cout << temp -> get_index() << ":" <<temp -> get_data() 
                      << "]" << std::endl;
        }
        else
        {
            std::cout << temp -> get_index() << ":" <<temp -> get_data() <<"->";
        }

        temp = temp -> get_next();
    }
    
    return true;
}

template <typename T> inline unsigned int DoubleLinkedList<T>::get_size()
{
    return size;
}
template <typename T> T DoubleLinkedList<T>::operator[](unsigned int const &idx)
{
    Node<T> *temp = start;
    
    while(nullptr != temp)
    {
        if(idx == temp -> get_index())
        {
            return temp -> get_data();
        }
        temp = temp -> get_next();
    }
    
    throw std::out_of_range("Linked List Out of Bounds");
}
/*******************************************************************************
        END: Member Function Definitions of DoubleLinkedList Class
*******************************************************************************/

#endif

/*==============================================================================
                            END OF FILE d_ll.h
==============================================================================*/
