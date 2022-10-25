/***************************************************************************************
*Project Name : SimvolnieDannie                                                        *
*File Name    : SimvolnieDannie.cpp                                                    *
*Language     : CPP,MSVS ver 2015 and above                                            *
*Programmers  : Ратников Роман Олегович,Фицайло Александр Александрович,               *
*                               группа:М3О-110Б-20                                     *
*Modified By  :                                                                        *
*Created      : 22/02/2021                                                             *
*Last Revision: 23/03/2021                                                             *
*Comment      : Символьные Данные                                                      *
***************************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;
//const char* fName = "Simv.txt"; //Файл. Корректный тест
//const char* fName = "SIMVOL.txt"; // Некорректный тест. Файл не существует
//const char* fName = "Simv0.txt";//Некорректный тест. Пустой файл
//const char* fName = "Simv1.txt"; //Некорректный тест. Превышен лимит в 1 строке
//const char* fName = "Simv2.txt";//Некорректный тест. 1 строка пустая
//const char* fName = "Simv3.txt";//Некорректный тест.Превышен лимит во 2 строке
//const char* fName = "Simv4.txt";//Некорректный тест. 2 строка пустая
const char* fName = "Simv5.txt"; //Файл. Корректный тест. Одинаковые слова
const char MAXLEN = 20;
int main()
{
	setlocale(LC_ALL, "Russian");  //Русский язык в консоли
	system("color F0");            //Белый фон,чёрные символы
	//Объявление переменных
	int lenStr = 0;                //Реальный размер 1 строки
	int lenStr2 = 0;               //Реальный размер 2 строки
	int minLen;                    //Минимальный размер новой строки
	int modLen;                    //Оставшееся длина строки
	bool simSymbol = false;        //Такой же символ 
	bool Info = false;             //Информация для вывода
	int i, j;                      //Индексовые переменные                
	fstream fin;                   //Команда для работы с файлами
	fin.open(fName);               //Открытие файла
    char Str[MAXLEN+1];                    // 1 строка
	char Str2[MAXLEN+1];                   // 2 строка
	char Str3[MAXLEN+MAXLEN];            //Сформированная строка
    //Проверка на существование файла
	if (!fin)
	{
		cout << "Файл не найден" << endl;			//Сообщение об ошибке
		fin.close();								//Закрыть файл
		return 1;									//Выход по ошибке
	}
	//Проверка на пустоту файл
	if (fin.peek() == EOF)
	{
		cout << "Файл пуст" << endl;
		fin.close();
		return 2;
	}

  //Цикл, где можем ввести больше символов для обнаружения ошибки
    char symbol;                                  
	for (i = 0;i < MAXLEN+1;i++)                   //Запись 1 строки
	{
		
		if (fin.peek()=='\n')                     //Если есть переход на новую строку
			break;
		if (fin.peek() == EOF)
		{
			cout << "Вторая строка пуста" << endl;
			fin.close();
			return 3;
		}
		
		if (fin.peek() == ' ')                    //Если найден пробел
		{
			Str[i] = ' ';
			
			lenStr++;
			i++;                                  //Переход к новому элементу
		}
		
		if (i < MAXLEN + 1)                      //Проверка , не вышли ли за массив
		{
			fin >> symbol;
			Str[i] = symbol;
			lenStr++;
		}
		

	}   
	if (lenStr == MAXLEN + 1)                   //Проверка на превышение максимума
	{
		cout << " Ошибка.В строке не м.б. больше " << MAXLEN+0  << "  символов" << endl;
		fin.close();
		return 4;
	}
	
	if (lenStr == 0)
	{
		cout << "  Первая строка пуста  " << endl;
		fin.close();
		return 5;
	}
	for (i = 0;i < lenStr;i++)
	{
		cout << Str[i];
	}	                                   // Вывод 1 строки
	cout << "\n"  << "Длина 1 строки = " << lenStr << endl;  // Вывод длины 1 строки

	for (i = 0;i < MAXLEN + 1;i++)         //Цикл, где можем ввести больше символов для обнаружения ошибки
	{

		if (fin.peek() == EOF)             //Проверка, есть ли символ
			break;

		if (fin.peek() == ' ')            //Если найден пробел
		{
			Str2[i] = ' ';

			lenStr2++;
			i++;                          //Переход к следующему символу
		}

		if (i < MAXLEN + 1)              // Проверка, не вышли ли за массив 
		{
			fin >> symbol;
			Str2[i] = symbol;
			lenStr2++;
		}


	}
	if (lenStr2 == MAXLEN + 1)                    //Проверка, превышен ли максимум
	{
		cout << " Ошибка.В строке не м.б. больше " << MAXLEN + 0 << "  символов" << endl;
		fin.close();
		return 6;
	}
	
	
	
	if (lenStr2 == 0)                              //Проверка на непустую вторую строку
	{
		cout << "  Вторая строка пуста" << endl;
		fin.close();
		return 3;
	}
	
	for (i = 0;i < lenStr2;i++)                   //Вывод 2 строки
	{
		cout << Str2[i];
	}
	                   
	cout << " \n"<< "Длина 2 строки = " << lenStr2 << endl;   //Вывод длины 2 строки

	
	

	cout << " 1 строка с уник. символами: ";       //Формирование новой строки
	for (i = 0; i < lenStr;i++)
	{
		j = 0;                                      //Обнуление индекса перед началом внутр. цикла
		while (j < lenStr2 && !simSymbol)
		{
			if (Str[i] == Str2[j])
			{
				simSymbol = true;     // Есть такой же символ во 2 строке

			}

			j++;
		}
		if (!simSymbol)           //Выводим символ, если нет совпадений
		{
			cout << Str[i];
			Info = true;          //Обновление информации
		}

		simSymbol = false;        //Ложь для проверки других символов
	}
	if (!Info)        //Выводим сообщение, если все сиволы совпали
	{
		cout << "\nВсе символы 1 строки находятся во 2 строке" << endl;
	}
	if (lenStr <= lenStr2)     //Поиск мин. длины новой строки
	{
		minLen = lenStr;
		modLen = lenStr2;
	}
	else
	{
		minLen = lenStr2;
		modLen = lenStr;
	}
	cout << " \n Строка с чередованием символов : " << endl;
	
	for (i=0,j = 0;i < minLen;i++)            //Часть 3 строки с чередованием   
	{
		
		Str3[j] = Str[i];
		j++;                         //Переход к новому символу
		Str3[j] = Str2[i];
		j++;
	}

	// Уже записано по minLen из каждой строки
	for (i = minLen,j=minLen+minLen;i < modLen;i++,j++)         //Конечное формирование 3 строки
	{
		if (modLen == lenStr)               //Если большая строка - 1 строка
		{
			Str3[j] = Str[i];

	    }
		else
		{
			Str3[j] = Str2[i];

		}
	}
	
	//Вывод 3 строки
	for (i = 0;i < lenStr+lenStr2;i++)
		cout << Str3[i];
	

	return 0;
}
