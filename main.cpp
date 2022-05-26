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
		cout << "1) ������� ����� \"����������\"\n" << "2) ������� ����� ����\n" << "3) �����\n" << "�������� ��������: ";
		choose = _getch();
		cout << choose << endl;
		if (choose == '1')
		{
			system("cls");

			try
			{
				cout << "������� x, y, z ����� ������ ��� �������: ";
				cin >> x >> y >> z;
				cin.ignore(32767, '\n');	//������� �������� ����������� ����� �� �������� ������ 

				if (cin.fail())
					throw "��������� ������� �� �������� ������";

				coordinates.SetX(x);
				coordinates.SetY(y);
				coordinates.SetZ(z);
				system("cls");

				while (exit)
				{
					cout << "1) ++A \n" << "2) A++ \n" << "3) --A \n" << "4) A-- \n" << "5) !\n" << "6) �������� ���������� \n" << "7) ����� \n" << "\n�������� ��������: ";
					choose = _getch();

					switch (choose)
					{
					case '1':
						cout << "++A\n" << "����������: ";
						coordinates.show();
						++coordinates;
						cout << "���������� ����� ����������: ";
						coordinates.show();
						break;

					case '2':
						cout << "A++\n" << "������� �����, �� ������� ������ ��������� ����������: \n";
						cin >> value;
						cin.ignore(32767, '\n');
						if (cin.fail())
							throw "��������� ������� �� �������� ������"; 

						cout << " �������� ����������, ������� ������ ���������: \n" << "1) x \n" <<  "2) y \n" << "3) z \n";
						choose = _getch();
						cout << choose << endl; 
						
						coordinates += value;
						cout << "��������� �����������:\n";
						
						if (choose == '1') coordinates.showx();
						if (choose == '2') coordinates.showy();
						if (choose == '3') coordinates.showz();
						
						break;

					case '3':
						cout << "--A\n" << "����������: ";
						coordinates.show();
						--coordinates;
						cout << "���������� ����� ����������: ";
						coordinates.show();
						break;

					case '4':
						cout << "A--\n" << "������� �����, �� ������� ������ ��������� ����������: \n";
						cin >> value;
						cin.ignore(32767, '\n');
						if (cin.fail())
							throw "��������� ������� �� �������� ������";

						cout << " �������� ����������, ������� ������ ���������: \n" << "1) x \n" << "2) y \n" << "3) z \n";
						choose = _getch();
						cout << choose << endl;

						coordinates -= value;
						cout << "��������� ���������:\n";

						if (choose == '1') coordinates.showx();
						if (choose == '2') coordinates.showy();
						if (choose == '3') coordinates.showz();

						break;

					case '5':
						cout << "!A\n" << "����������: ";
						coordinates.show();
						!coordinates;
						cout << "���������� ����� ��������� �� (-1): ";
						coordinates.show();
						break;

					case '6':
						cout << "�������� ����������\n" << "����������: ";
						coordinates.show();
						break;

					case '7':
						cout << "�����\n";
						exit = 0;
						break;
					default:
						cout << "\n������ ��� ������ ���������!\n";
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
				cin.ignore(32767, '\n');	//������� �������� ����������� ����� �� �������� ������ 
			}

		}
		else if (choose == '2')
		{
			int size = 0;

			cout << "������ ����� ����� ";
			size = rand() % 10 + 1;
			cout << size << endl;

			try
			{
				if (cin.fail())	throw "�������� ������� �� �������� ������!";

				Stack x(size);
				system("pause");
				system("cls");

				while (exit)
				{
					cout << "1) /, -, =\n" << "2) /=, -=, ! \n" << "3) <, >, == \n" << "4) ���� � ������ � �����\n" << "5)����� �� ��������� \n" << "\n�������� �������� : \n";
					choose = _getch();

					switch (choose)
					{
					case '1':
						cout << "1) / \n" << "2) - \n" << "3) = \n";
						choose = _getch();

						switch (choose)
						{
						case '1':
							cout << "/\n" << "���� x:\n" << x << endl;
							try
							{
								cout << "������� �����, �� ������� ������ ������: ";
								cin >> value;
								cin.ignore(32767, '\n');
								if (cin.fail())
									throw "��������� ������� �� �������� ������";
								x / value;
								cout << "��������� �������:\n" << x << endl;

							}
							catch (const char* exc)
							{
								cout << exc << endl;
								cin.clear();
								cin.ignore(32767, '\n');
							}
							break;
						case '2':
							cout << "-\n" << "���� x:\n" << x << endl;
							try
							{
								cout << "������� �����, ������� ������ ������: ";
								cin >> value;
								cin.ignore(32767, '\n');
								if (cin.fail())
									throw "��������� ������� �� �������� ������";
								x - value;
								cout << "��������� ���������:\n" << x << endl;

							}
							catch (const char* exc)
							{
								cout << exc << endl;
								cin.clear();
								cin.ignore(32767, '\n');
							}
							break;

						case '3':
							cout << "=\n" << "���� x:\n" << x << endl;
							try
							{
								cout << "������� �����, � �������� ������ ���������� ��� �������� �����: ";
								cin >> value;
								cin.ignore(32767, '\n');
								if (cin.fail())
									throw "��������� ������� �� �������� ������";

								x = value;
								cout << "��������� �������������:\n" << x << endl;
							}
							catch (const char* exc)
							{
								cout << exc << endl;
								cin.clear();
								cin.ignore(32767, '\n');
							}
							break;

						default:
							cout << "\n������ ��� ������ ���������!" << endl;
							break;
						}
						break;

					case '2':
						cout << "1) /= \n" << "2) -= \n" << "3) ! \n";
						choose = _getch();

						switch (choose) 
						{
						case '1':
							cout << "/=\n" << "���� x:\n" << x << endl;
							try
							{
								cout << "������� �����, �� ������� ������ ��������� ��� �������� �����: ";
								cin >> value;
								cin.ignore(32767, '\n');
								if (cin.fail())
									throw "��������� ������� �� �������� ������";
								x /= value;
								cout << "��������� �������:\n" << x << endl;
							}
							catch (const char* exc)
							{
								cout << exc << endl;
								cin.clear();
								cin.ignore(32767, '\n');
							}
							break;

						case '2':
							cout << "-=\n" << "���� x:\n" << x << endl;
							try
							{
								cout << "������� �����, �� ������� ������ ��������� ��� �������� �����: ";
								cin >> value;
								cin.ignore(32767, '\n');
								if (cin.fail())
									throw "��������� ������� �� �������� ������";
								x -= value;
								cout << "��������� �������:\n" << x << endl;
							}
							catch (const char* exc)
							{
								cout << exc << endl;
								cin.clear();
								cin.ignore(32767, '\n');
							}
							break;

						case '3': 
							cout << "!\n" << "���� x:\n" << x << endl;
							try
							{
								!x;
								cout << "��������� ��������� �� (-1):\n" << x << endl;
							}
							catch (const char* exc)
							{
								cout << exc << endl;
								cin.clear();
								cin.ignore(32767, '\n');
							}
							break;
						
						default:
							cout << "\n������ ��� ������ ���������!" << endl;
							break;
						}
						break;

					case '3':
						cout << "���������\n" << "���� x:\n" << x << endl;
						try
						{
							cout << "������� �����, � ������� ������ �������� ��� �������� �����: ";
							cin >> value;
							cin.ignore(32767, '\n');
							if (cin.fail())
								throw "��������� ������� �� �������� ������";

							cout << "��������� ���������: \n";
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
						cout << "1) ���� \n" << "2) ����� \n";
						choose = _getch();

						switch (choose)
						{
						case '1':
							cout << "����\n" << "���� x:\n" << x << endl;
							try
							{
								cout << "������� �����: ";
								cin >> x;
								cin.ignore(32767, '\n');
								if (cin.fail())
									throw "��������� ������� �� �������� �������";
								cout << "��������� �����:\n" << x << endl;
							}
							catch (const char* exc)
							{
								cout << exc << endl;
								cin.clear();
								cin.ignore(32767, '\n');
							}
							break;

						case '2':
							cout << "�������� ����\n" << "���� s:\n" << x << endl;
							break;

						default:
							cin.ignore(32767, '\n');
							break;
						}
						break;

					case'5':
						cout << "�����\n";
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
			cout << "����� �� ���������\n" << endl;
			exit = 0;
		}
		else
		{
			cout << "������ ������! ���������� ��� ���." << endl;
			system("pause");
			system("cls");
		}
	}

	system("pause");
	return 0;
}