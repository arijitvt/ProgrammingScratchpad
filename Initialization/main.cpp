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
      std::cout << "This is copy constructor" << std::endl;
      d_name = s.getName(); 
      d_class = s.getClass();
    }
    Student (const Student&& s) 
    {
      std::cout << "Move constructor" << std::endl;
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
  Student s = Student {"Arijit", 1};
  fooByValue(s); // Calls the copy constructor
  fooByReference(s);  

  std::vector<Student> studentList = {
    std::move(Student("Rajni",2))
  };
  return 0;
}