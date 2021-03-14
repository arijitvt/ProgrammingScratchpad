#include <iostream>
#include <string> 
#include <map>
#include <vector>


class Student
{
  private: 
    std::string d_name; 
    int d_class; 

  public: 
    Student(const std::string& name, int cls)
    :d_name(name)
    , d_class(cls)
    {
      std::cout << "This is the constructor" << std::endl;
    }

    Student()
    : d_name("")
    , d_class(0)
    {
      std::cout << "This is the default constructor" << std::endl;
    }


    Student& operator=(const Student& s)
    {
      std::cout << "This is = operator " << std::endl;
      d_name = s.getName(); 
      d_class = s.getClass();
      return *this;
    }

    Student(const Student& s)
    {
      std::cout << "This is copy constructor" 
            << ", source name=" << s.getName()
            << ", destination name=" << getName() << std::endl;
      d_name = s.getName(); 
      d_class = s.getClass();
    }
    Student (const Student&& s) 
    {
      std::cout << "This is move constructor" 
            << ", source name=" << s.getName()
            << ", destination name=" << getName() << std::endl;
    }

    const std::string& getName() const 
    {
      return d_name;
    }
    int getClass() const 
    {
      return d_class;
    }
};

void fooByValue(Student s)
{
  std::cout << __func__ << ":" <<s.getName() << std::endl;
}

void fooByReference(const Student& s) 
{
  std::cout << __func__ << ":" << s.getName() << std::endl;
}


int main() {
  Student s {"Arijit", 1};
  std::cout << "Object construction is done" << std::endl;

  std::cout << "Equal operator overload"<< std::endl;
  Student s1;
  s1 = Student{"Rajni", 2}; // = operator
  std::cout << "Equal operator overload is Done." << std::endl;

  std::cout <<"Pass by value" << std::endl;
  fooByValue(s); // Calls the copy constructor
  std::cout << "Pass by value is Done" << std::endl;

  std::cout << "Pass by reference." << std::endl;
  fooByReference(s);  // Pass by reference
  std::cout <<"Pass by reference is Done." <<std::endl;

  std::cout << "Initializer list in vector"<< std::endl;
  std::vector<Student> studentList;
  std::cout << "-> Capacity=" << studentList.capacity() <<":size="<< studentList.size() << std::endl;
  std::cout << "-> Vector creation done" << std::endl;
  std::cout << "-> Move operation"<< std::endl;
  studentList.push_back({std::move(Student{"Urbi",3})}); // calls the move constructor
  std::cout << "-> Move operation is DONE."<< std::endl;
  std::cout << "-> Copy operation"<< std::endl;
  studentList.push_back(Student{"Tuktuk",3}); // calls the move constructor
  std::cout << "-> Copy operation is DONE."<< std::endl;
  std::cout << "-> Vector  population is done" << std::endl;
  std::cout << "Initializer list is Done" << std::endl;


  return 0;
}