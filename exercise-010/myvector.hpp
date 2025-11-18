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

// !!!! size is equal to size of vector, capacity are the free places
namespace tfe24 {
template <typename T>
class myvector {

public:
    
    // Standard-Constructor
    myvector() noexcept{
        int m_count = 0;
        m_arr = new T[m_count];
        m_size = m_count;
        m_capacity = m_count;
    }

    // Size-Constructor
    explicit myvector(size_t count){
        m_arr = new T[count];
        m_size = count;
        m_capacity = count;
        }

    // Copy-Constructor
    myvector(const myvector &other){
        m_size = other.m_size;
        m_capacity = other.m_capacity;

        // copy member from old to new m_arr
        m_arr = new T[other.m_size];
        for (size_t i = 0; i < other.m_size; i++){
            m_arr[i] = other.m_arr[i];
            }
    }

    // Destructor
    ~myvector(){
        delete[] m_arr;
        m_arr = nullptr;
        m_size = 0;
        m_capacity = 0;
    }

    //print status
    void status() const noexcept{
        fmt::println("size: {}, capacity: {}", m_size, m_capacity);
        fmt::println(" ");
    }

    size_t size() const noexcept{
        fmt::println("size: {}", m_size);
        fmt::println(" ");
        return m_size;
    }

    size_t capacity() const noexcept{
        fmt::println("capacity: {}", m_capacity);
        fmt::println(" ");
        return m_capacity;
    }

    void print_all(){

        for(size_t i = 0; i < m_size; i++){
            fmt::println("Element at index {}: {}", i, at(i));
        }

        fmt::println("");
    }

    void push_back(const T& value){
        if (m_capacity == 0){
            fmt::println("Vector is full, double vector size.");
            if (m_size == 0){
                m_size = 1;
                m_capacity = 1;
            }
            size_t temp_new_size = m_size * 2;
            size_t temp_new_capacity = temp_new_size - (m_size - m_capacity);

            // copy member from old to new m_arr
            T* m_arr_new = new T[temp_new_size];
            for (size_t i = 0; i < m_size; i++){
                m_arr_new[i] = m_arr[i];
                }
            delete[] m_arr;

            // update member variable
            m_arr = m_arr_new;
            m_size = temp_new_size;
            m_capacity = temp_new_capacity;

            // pushback value
            //fmt::println("push back of new value.\n");
            size_t position = m_size - m_capacity;
            m_arr[position] = value;
            m_capacity --;
        }
        else {
            size_t position = m_size - m_capacity;
            m_arr[position] = value;
            m_capacity --;
        }
        
    }

    const T& at(size_t index) const{
        if(index > m_size){
            throw std::out_of_range("Index out of range");
        }
        else{
        return m_arr[index];
        }
    }

    void resize(size_t new_size){
        
        size_t temp_new_capacity = new_size - (m_size - m_capacity);

        // copy member from old to new m_arr
        T* m_arr_new = new T[new_size];
        for (size_t i = 0; i < (m_size - m_capacity); i++){
            m_arr_new[i] = m_arr[i];
            }
        
        //fmt::println("Values copied");

        for (size_t i = (m_size - m_capacity); i < new_size; i++){
            m_arr_new[i] = 0;
            }

        delete[] m_arr;

        // update member variable
        m_arr = m_arr_new;
        m_size = new_size;
        m_capacity = temp_new_capacity;

    }

    void clear() noexcept{
        delete[] m_arr;
        m_arr = nullptr;
        m_size = 0;
        m_capacity = 0;
    }

    T& operator[] (size_t index){
        return m_arr[index];
    }

    private:
    T* m_arr;
    size_t m_size;
    size_t m_capacity;
};
} // namespace tfe24

#endif /* MY_VECTOR_HPP */