#include <iostream>
#include <string> 
#include <map>


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
      std::cout << "Thisi is the constructor" << std::endl;
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

    const std::string& getName() const 
    {
      return d_name;
    }
    int getClass() const 
    {
      return d_class;
    }
};

int main() {
  std::map<std::string, int> container = {
    {}
  };

}