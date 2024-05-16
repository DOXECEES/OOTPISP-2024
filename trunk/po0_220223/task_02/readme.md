
Лабораторная работа №2

НАСЛЕДОВАНИЕ И ВИРТУАЛЬНЫЕ ФУНКЦИИ 

Вариант 8
 

Цель работы
получить практические навыки создания иерархии классов и использования статических компонентов класса.


конструктор с параметрами и без для базового класса:

void Place::printHead() {
    Place* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->getName() << endl;
        ptr = ptr->next;
    }
}
void Place::show() {
    cout << " " << endl;
    Place* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->getName() << endl;
        ptr = ptr->next;
    }
}

конструктор с параметрами и без для одного из дочерних классов:

Region::Region(string_view name1, const int Population1)
    : Population(Population1) {
    name = name1;
}
void Region::printVirtual() {
    cout << "Region (virtual function)" << endl;
}
void Region::show() {
    Place* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->getName() << " - Population: " << Population << endl;
        ptr = ptr->getNext();
        if (this->getNext() == ptr) {
            break;
        }
    }
}

статические компоненты класса:
    static Place* head;
    static Place* lastObject;


