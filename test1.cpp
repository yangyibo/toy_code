#include <iostream>

using namespace::std;

class Animal
{
public:
    Animal(int age, int name): m_age(age), m_name(name)
    {}
    virtual ~Animal() {}
    
    virtual int cry() = 0;
    virtual void bigCry()
    {
        cout << "big" << endl;
        int a = cry();
        cout << a << endl;
    }

    int getAge()
    {
        cout << "in animal" << endl;
        return m_age;
    }

    int m_name;

private:
    int m_age;
};


class Cat: public Animal
{
public:
    Cat(int age, int name): Animal(age, name), m_age(age + 1), m_name(name + 1)
    {}
    virtual ~Cat() {}
    virtual int cry()
    {
        cout << "Cat cry" << endl;
        return 6;
    }

    int getAge()
    {
        cout << "int cat" << endl;
        return Animal::getAge();
    }

    int m_name;

private:
    int m_age;

};

int main(int argc, char const *argv[])
{
    Animal* a = new Cat(88, 777);

    a->bigCry();

    cout << a->getAge() << endl;
    cout << a->m_name << endl;

    return 0;
}