#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fmt/format.h>

class MyVector {

public:
    MyVector();
    MyVector(unsigned int size);
    ~MyVector();
    int size();

private:
    int* m_data;
};


// Template class myVector

template <typename T>
class myvector {

public:
    
    myvector() noexcept{
        m_arr = new T[2];
        m_size = 2;
        m_capacity = 2;
    }

    explicit myvector(size_t count){
        m_arr = new T[count];
        m_size = count;
        m_capacity = count;
        }

    ~myvector(){
        delete[] m_arr;
    }

    void status(){
        fmt::println("size: {}, capacity: {}", m_size, m_capacity);
        fmt::println(" ");
    }

    void push_back(const T& value){
        if (m_capacity == 0){
            fmt::println("Vector is full, cannot push_back more elements.\n");
        }
        else{
            size_t position = m_size - m_capacity;
            m_arr[position] = value;
            m_capacity --;
        }
        
    }

    T& at(size_t index){
        return m_arr[index];
    }

    const T& at(size_t index) const;
    size_t size() const noexcept;
    void resize(size_t new_size);
    void clear() noexcept;

private:
    T* m_arr;
    size_t m_size;
    size_t m_capacity;
};


#endif /* MY_VECTOR_HPP */