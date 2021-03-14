#include <iostream>
#include <string>
#include <tuple>
#include <map>

class Student
{
  private:
    std::string d_name; 
    int d_cls; 

  public:
    Student(const std::string& name, int cls) 
    :d_name(name)
    , d_cls (cls)
    {
      std::cout << "Constructor with name=" << d_name <<", class=" << d_cls << std::endl;
    }
    Student()
    {
      std::cout << "Default Constructor " << std::endl;
    }

    Student(const Student& s)
    {
      std::cout << "Copy Constructor, source=" << s.getName() 
                  << ", destination=" << d_name << std::endl;
      d_name  = s.getName(); 
      d_cls   = s.getClass();
    }

    Student(const Student&& s) 
    {
      std::cout << "This is a move Constructor, source=" << s.getName() << std::endl;
    }

    Student& operator=(const Student&  s) 
    {
      std::cout << "= operator , source=" << s.getName() << ", destination=" << getName() << std::endl;
      return *this; 
    }

    const std::string& getName() const 
    {
      return  d_name;
    }

    int getClass() const 
    {
      return d_cls;
    }
};

std::pair<double, double> divison(int num, int divisor)
{
  return std::make_pair((num/divisor), (double)(num%divisor));
}

auto registerStudent(const std::string& name, int cls)
{
  static int index = 0; 
  static std::map<int,Student> studentMap; 
  studentMap.insert(std::move(Student{name,cls}));

}



int main()
{
  const auto&[result, remainder] = divison(100,3);
  std::cout << "Result=" << result << ", remainder=" << remainder <<std::endl;
  return 0;
} 