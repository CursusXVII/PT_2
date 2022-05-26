#include "Coordinates.h"
#include "Stack.h"
#include <conio.h>
#include <cmath>

using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	Coordinates coordinates;

	bool exit = 1;
	int value;
	int x, y, z;
	char choose;

	while (exit)
	{
		cout << "1) Создать класс \"Координаты\"\n" << "2) Создать класс Стек\n" << "3) Выход\n" << "Выберите действие: ";
		choose = _getch();
		cout << choose << endl;
		if (choose == '1')
		{
			system("cls");

			try
			{
				cout << "Введите x, y, z через пробел без запятых: ";
				cin >> x >> y >> z;
				cin.ignore(32767, '\n');	//удаляем значения предыдущего ввода из входного буфера 

				if (cin.fail())
					throw "Введенные символы не являются числом";

				coordinates.SetX(x);
				coordinates.SetY(y);
				coordinates.SetZ(z);
				system("cls");

				while (exit)
				{
					cout << "1) ++A \n" << "2) A++ \n" << "3) --A \n" << "4) A-- \n" << "5) !\n" << "6) Показать координаты \n" << "7) Выход \n" << "\nВыберите действие: ";
					choose = _getch();

					switch (choose)
					{
					case '1':
						cout << "++A\n" << "Координаты: ";
						coordinates.show();
						++coordinates;
						cout << "Координаты после увеличения: ";
						coordinates.show();
						break;

					case '2':
						cout << "A++\n" << "Введите число, на которое хотите увеличить координату: \n";
						cin >> value;
						cin.ignore(32767, '\n');
						if (cin.fail())
							throw "Введенные символы не являются числом"; 

						cout << " Выберите координату, которую хотите увеличить: \n" << "1) x \n" <<  "2) y \n" << "3) z \n";
						choose = _getch();
						cout << choose << endl; 
						
						coordinates += value;
						cout << "Результат прибавления:\n";
						
						if (choose == '1') coordinates.showx();
						if (choose == '2') coordinates.showy();
						if (choose == '3') coordinates.showz();
						
						break;

					case '3':
						cout << "--A\n" << "Координаты: ";
						coordinates.show();
						--coordinates;
						cout << "Координаты после уменьшения: ";
						coordinates.show();
						break;

					case '4':
						cout << "A--\n" << "Введите число, на которое хотите уменьшить координату: \n";
						cin >> value;
						cin.ignore(32767, '\n');
						if (cin.fail())
							throw "Введенные символы не являются числом";

						cout << " Выберите координату, которую хотите уменьшить: \n" << "1) x \n" << "2) y \n" << "3) z \n";
						choose = _getch();
						cout << choose << endl;

						coordinates -= value;
						cout << "Результат вычитания:\n";

						if (choose == '1') coordinates.showx();
						if (choose == '2') coordinates.showy();
						if (choose == '3') coordinates.showz();

						break;

					case '5':
						cout << "!A\n" << "Координаты: ";
						coordinates.show();
						!coordinates;
						cout << "Координаты после умножения на (-1): ";
						coordinates.show();
						break;

					case '6':
						cout << "Показать координаты\n" << "Координаты: ";
						coordinates.show();
						break;

					case '7':
						cout << "Выход\n";
						exit = 0;
						break;
					default:
						cout << "\nОшибка при выборе категории!\n";
						break;
					}

					system("pause");
					system("cls");
				}

				exit = 1;
			}
			catch (const char* exc)
			{
				cout << exc << endl;
				cin.clear();
				cin.ignore(32767, '\n');	//удаляем значения предыдущего ввода из входного буфера 
			}

		}
		else if (choose == '2')
		{
			int size = 0;

			cout << "Размер стека равен ";
			size = rand() % 10 + 1;
			cout << size << endl;

			try
			{
				if (cin.fail())	throw "Введённые символы не являются числом!";

				Stack x(size);
				system("pause");
				system("cls");

				while (exit)
				{
					cout << "1) /, -, =\n" << "2) /=, -=, ! \n" << "3) <, >, == \n" << "4) Ввод и ввывод в поток\n" << "5)Выход из программы \n" << "\nВыберите действие : \n";
					choose = _getch();

					switch (choose)
					{
					case '1':
						cout << "1) / \n" << "2) - \n" << "3) = \n";
						choose = _getch();

						switch (choose)
						{
						case '1':
							cout << "/\n" << "Стек x:\n" << x << endl;
							try
							{
								cout << "Введите число, на которое хотите делить: ";
								cin >> value;
								cin.ignore(32767, '\n');
								if (cin.fail())
									throw "Введенные символы не являются числом";
								x / value;
								cout << "Результат деления:\n" << x << endl;

							}
							catch (const char* exc)
							{
								cout << exc << endl;
								cin.clear();
								cin.ignore(32767, '\n');
							}
							break;
						case '2':
							cout << "-\n" << "Стек x:\n" << x << endl;
							try
							{
								cout << "Введите число, которое хотите отнять: ";
								cin >> value;
								cin.ignore(32767, '\n');
								if (cin.fail())
									throw "Введенные символы не являются числом";
								x - value;
								cout << "Результат вычитания:\n" << x << endl;

							}
							catch (const char* exc)
							{
								cout << exc << endl;
								cin.clear();
								cin.ignore(32767, '\n');
							}
							break;

						case '3':
							cout << "=\n" << "Стек x:\n" << x << endl;
							try
							{
								cout << "Введите число, к которому хотите приравнять все элементы стека: ";
								cin >> value;
								cin.ignore(32767, '\n');
								if (cin.fail())
									throw "Введенные символы не являются числом";

								x = value;
								cout << "Результат приравнивания:\n" << x << endl;
							}
							catch (const char* exc)
							{
								cout << exc << endl;
								cin.clear();
								cin.ignore(32767, '\n');
							}
							break;

						default:
							cout << "\nОшибка при выборе категории!" << endl;
							break;
						}
						break;

					case '2':
						cout << "1) /= \n" << "2) -= \n" << "3) ! \n";
						choose = _getch();

						switch (choose) 
						{
						case '1':
							cout << "/=\n" << "Стек x:\n" << x << endl;
							try
							{
								cout << "Введите число, на которое хотите разделить все элементы стека: ";
								cin >> value;
								cin.ignore(32767, '\n');
								if (cin.fail())
									throw "Введенные символы не являются числом";
								x /= value;
								cout << "Результат деления:\n" << x << endl;
							}
							catch (const char* exc)
							{
								cout << exc << endl;
								cin.clear();
								cin.ignore(32767, '\n');
							}
							break;

						case '2':
							cout << "-=\n" << "Стек x:\n" << x << endl;
							try
							{
								cout << "Введите число, на которое хотите уменьшить все элементы стека: ";
								cin >> value;
								cin.ignore(32767, '\n');
								if (cin.fail())
									throw "Введенные символы не являются числом";
								x -= value;
								cout << "Результат деления:\n" << x << endl;
							}
							catch (const char* exc)
							{
								cout << exc << endl;
								cin.clear();
								cin.ignore(32767, '\n');
							}
							break;

						case '3': 
							cout << "!\n" << "Стек x:\n" << x << endl;
							try
							{
								!x;
								cout << "Результат умножения на (-1):\n" << x << endl;
							}
							catch (const char* exc)
							{
								cout << exc << endl;
								cin.clear();
								cin.ignore(32767, '\n');
							}
							break;
						
						default:
							cout << "\nОшибка при выборе категории!" << endl;
							break;
						}
						break;

					case '3':
						cout << "Сравнение\n" << "Стек x:\n" << x << endl;
						try
						{
							cout << "Введите число, с которым хотите сравнить все элементы стека: ";
							cin >> value;
							cin.ignore(32767, '\n');
							if (cin.fail())
								throw "Введенные символы не являются числом";

							cout << "Результат сравнения: \n";
							x == value;
						}
						catch (const char* exc)
						{
							cout << exc << endl;
							cin.clear();
							cin.ignore(32767, '\n');
						}
						break;

					case '4': 
						cout << "1) Ввод \n" << "2) Вывод \n";
						choose = _getch();

						switch (choose)
						{
						case '1':
							cout << "Ввод\n" << "Стек x:\n" << x << endl;
							try
							{
								cout << "Введите числа: ";
								cin >> x;
								cin.ignore(32767, '\n');
								if (cin.fail())
									throw "Введенные символы не являются числами";
								cout << "Результат ввода:\n" << x << endl;
							}
							catch (const char* exc)
							{
								cout << exc << endl;
								cin.clear();
								cin.ignore(32767, '\n');
							}
							break;

						case '2':
							cout << "Показать стек\n" << "Стек s:\n" << x << endl;
							break;

						default:
							cin.ignore(32767, '\n');
							break;
						}
						break;

					case'5':
						cout << "Выход\n";
						exit = 0;
						break;
					}
					system("pause");
					system("cls");
				}

				exit = 1;
			}
			catch (const char* exc)
			{
				cout << exc << endl;
				cin.ignore(32767, '\n');
				cin.clear();
			}
		}

		else if (choose == '3')
		{
			cout << "Выход из программы\n" << endl;
			exit = 0;
		}
		else
		{
			cout << "Ошибка выбора! Попробуйте ещё раз." << endl;
			system("pause");
			system("cls");
		}
	}

	system("pause");
	return 0;
}