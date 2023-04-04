#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <chrono>

using  namespace std ;
using namespace std::chrono;

class Stack {
public:
    Stack() {
        size = 0;
        capacity = 25;
        array = new int[capacity];
    }

    ~Stack() {
        delete[] array;
    }

    void push(int value) {
        if (size == capacity) {
            expand();
        }
        array[size++] = value;
    }

    int pop() {
        if (size == 0) {
            throw std::underflow_error("Stack is empty");
        }
        return array[--size];
    }

    int top() const {
        if (size == 0) {
            throw std::underflow_error("Stack is empty");
        }
        return array[size-1];
    }

    bool empty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

void display() const {
    std::cout << "Stack: ";
    for (int i = size-1; i >= 0; i--) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}


private:
    int* array;
    int size;
    int capacity;

    void expand() {
        capacity *= 2;
        int* newArray = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }
};

int main() {
    Stack myStack;

 auto start = high_resolution_clock::now();
  
    myStack.push(8);
    myStack.push(10);
    myStack.push(5);
  
  myStack.push(11);
  myStack.push(15);
  myStack.push(23);

  myStack.push(6);
  myStack.push(18);
  myStack.push(20);

  myStack.push(17);


  myStack.display();

  myStack.pop();

   myStack.pop();
   myStack.pop();
  
   myStack.pop();
   myStack.pop();

  
   myStack.display();

myStack.push(4);
  myStack.push(30);
  
  myStack.push(3);
  myStack.push(1);



  myStack.display();

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stop - start);

    
    cout  << duration.count() << "   microseconds";
  
  
    

   
    return 0;
}
