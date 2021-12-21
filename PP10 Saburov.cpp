#include <iostream>
#include <vector>//подключаем вектор
#include <algorithm>// sort, max_element, random_shuffle, remove_if, lower_bound 
#include <ctime>//для генератора случайных чисел, обновляет генерацию
#include <fstream>//запись в файл 
#include <conio.h>//для функции _getch и _kbhit 

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
    setlocale(LC_ALL, "Rus");//русский язык
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
                fout <<"Enter" <<endl;
                fout << "Вы вытянули бочонок номер =" << v.back() << endl;
                fout.close();//закрываем логфайл
                cout << "Нажмите Enter, чтобы вытащить следующий бочонок" << endl;
                cout << "Вы вытянули бочонок номер =" << v.back() << endl;
                v.pop_back();//удаляем последний элемент из вектора O(1);
                break;
            }
        } 
    }
    cout << "Бочонки кончились" << endl;
return 0;
}
