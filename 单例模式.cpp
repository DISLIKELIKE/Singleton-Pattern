#include<iostream>

//c++新特性的泛型单例
//模板可变参数、右值引用、完美转发。
template <class T>
class SingleClass {
public:

    //delete可以禁用成员函数的使用
    // 禁止外部构造、析构、拷贝构造和赋值构造
    SingleClass() = delete;
    ~SingleClass() = delete;
    SingleClass& operator = (const SingleClass&) = delete;
    SingleClass(const SingleClass&) = delete;

    //使用可变参数模板创建单例
    template <typename ...Args>
    static T* instance(Args&&... args) {
        static T* m_pInstance = nullptr;//这里使用了局部静态变量来确保线程安全
        if (nullptr == m_pInstance)
        {
            m_pInstance = new T(std::forward<Args>(args)...);
        }
        return m_pInstance;
    }

    //获取单例
    static T* GetInstance() {

        std::cout << "GetInstance success!" << std::endl;
        return instance<>();
    }
};



class MyClass {
public:
    MyClass(int value1, int value2) : value_1(value1), value_2(value2) {}
    void print() { std::cout << "Value: " << value_1 << std::endl; std::cout << "Value: " << value_2 << std::endl;
    }

private:
    int value_1;
    int value_2;
};

int main()
{
    
    auto p1 = SingleClass<int>::GetInstance();
    
    auto p2 = SingleClass<MyClass>::instance(232,89);//自定义类型、多参数测试
    p2->print();
    
    return 0;
}