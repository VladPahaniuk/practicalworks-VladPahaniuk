#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <exception>

template<typename Type>
class List {
private:
  class Node {
  public:
    Type data;
    Node* pointerNextElement;
    Node(Type = Type(), Node* = nullptr);
  };
  size_t size;
  Node* head;
public:

  // Конструктор по умолчанию
  List();

  // Конструктор копирования
  List(const List<Type>& other);

  // Деструктор
  ~List();

  // Оператор присваивания
  List<Type>& operator=(const List<Type>& other);

  size_t getSize()const;

  void push_front(Type data);
  void push_back(Type data);

  void pop_front();
  void pop_back();

  void removeByValue(const Type& value);

  size_t searchWithValue(const Type& value);
  void forEach(void (*callback)(const Type&));

  Type& operator[](const size_t index);
  void clear();

};

struct Student {
  std::string lastName;
  size_t grades[5];
  size_t studentID;
   bool operator==(const Student& other) const {
        return lastName == other.lastName && studentID == other.studentID;
    }
};


#include "List.inl"
#endif
