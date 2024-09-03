#include<iostream>

//c++�����Եķ��͵���
//ģ��ɱ��������ֵ���á�����ת����
template <class T>
class SingleClass {
public:

    //delete���Խ��ó�Ա������ʹ��
    // ��ֹ�ⲿ���졢��������������͸�ֵ����
    SingleClass() = delete;
    ~SingleClass() = delete;
    SingleClass& operator = (const SingleClass&) = delete;
    SingleClass(const SingleClass&) = delete;

    //ʹ�ÿɱ����ģ�崴������
    template <typename ...Args>
    static T* instance(Args&&... args) {
        static T* m_pInstance = nullptr;//����ʹ���˾ֲ���̬������ȷ���̰߳�ȫ
        if (nullptr == m_pInstance)
        {
            m_pInstance = new T(std::forward<Args>(args)...);
        }
        return m_pInstance;
    }

    //��ȡ����
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
    
    auto p2 = SingleClass<MyClass>::instance(232,89);//�Զ������͡����������
    p2->print();
    
    return 0;
}