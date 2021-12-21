# Lab-10
## Лабораторная номер 3 Шифр Цезаря
## Описание программы
Написать программу для проведения жеребьевки методом генерации случайных чисел.
В мешке с бочонками N бочек (от 1 до N).
Нажатие кнопки – вытаскивание очередного бочонка из мешка.
Вытянутые бочонки убираем в сторону (т.е. каждое число может выпасть только 1 раз).
## Ограничение по входным данным
vector ограничивается 1 млн элементов поэтому большее количество бочонков не реализовано
## По Visual Studio 2019
### КОД
```
#include <iostream>
#include <vector>//подключаем вектор
#include <algorithm>// sort, max_element, random_shuffle, remove_if, lower_bound 
#include <ctime>//для генератора случайных чисел, обновляет генерацию
#include <fstream>//запись в файл 
#include <conio.h>//для функции _getch и _kbhit 
#include <windows.h>

using namespace std;

int ErrorofEnter()
{
    while (true)
    {
        int n;
        std::cout << "Введите количество бочонков от 1 до N " << std::endl;
        std::cin >> n;
        if ((n > 0)& (n < 1000000))//максимальный размер вектора 1073741823 так что ограничиваю ввод до 1 млн элементов
            return(n);
        else
            std::cout << "Ошибка ввода" << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }
}

int main() {
    srand(time(NULL));//генератор случайных чисел, чтобы убрать повторяющиеся значения при повторных запусках программы
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);//русский язык
    vector<int> v;//инициализация вектора
    int n;
    n = ErrorofEnter();//ввод количества бочонков с проверкой на ошибку ввода

    for (int i = 1; i != n+1; i++)//заполняем вектор
    {
        v.push_back(i);//приписываем последний элемент в вектор O(1); хотя с расширением вектора O(n);
    }

    random_shuffle(v.begin(), v.end());//миксуем вектор от начала до конца O(n);
    random_shuffle(v.begin(), v.end());//у меня плохо рандомит поэтому дважды миксую 
    cout << "Нажмите Enter чтобы вытащить бочонок"<<endl;
    while (v.size()!=0)//size размер вектора O(1);
    {
        if (_kbhit())//функция проверки ввода клавиши в моём случае реализую Enter в качестве кнопки ввода;
        {
            switch (_getch()) // ждёт нажатия на клаву без Enter после этого;
            {
            case 13: //кейс 13 это клавиша Enter
                ofstream fout("logfile.txt", std::ios::app);//открываем логфайл
                fout <<"user pressed enter " <<endl;
                fout <<"user get number =" << v.back() << endl;
                fout.close();//закрываем логфайл
                cout << "Нажмите Enter, чтобы вытащить следующий бочонок" << endl;
                cout << "Вы вытянули бочонок номер =" << v.back() << endl;
                v.pop_back();//удаляем последний элемент из вектора O(1);
                break;
            }
        } 
    }
    cout << "Бочонки кончились" << endl;
    ofstream fout("logfile.txt", std::ios::app);//открываем логфайл
    fout << "////////////////////////////////////////////////////////////" << endl;
    fout.close();//закрываем логфайл
return 0;
}
```
### Скрины выполнения 
Для n=5
![Отладка для n=5](https://user-images.githubusercontent.com/90544365/146983080-bb6f669f-a328-418a-9ba5-39456e7ede95.jpg)
Для n=10
![Отладка для n=10](https://user-images.githubusercontent.com/90544365/146983144-8dd8f334-a3d6-4cbc-af50-d0e488e3a583.jpg)
Для n=30
![Отладка для n=30](https://user-images.githubusercontent.com/90544365/146983171-29da778a-17b4-4682-84d8-c3f44f56777f.jpg)
