#include <iostream>
#include <Windows.h>
#include <string>
#include "string.h"
#include<cstring>
#include <map>
#include <list>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int sort_number;
	cout << "==========================" << endl;
	cout << "==========================" << endl;
	cout << "1.Простая перестановка" << endl;
	cout << "2.Блочная перестановка" << endl;
	cout << "3.Маршрутная перестановка" << endl;
	cout << "4.Вертикальная перестановка" << endl;
	cout << "5.Поворотная решетка" << endl;
	cout << "6.Магический квадрат" << endl;
	cout << "7.Шифр Цезаря" << endl;
	cout << "8.Лозунговый шифр" << endl;
	cout << "9.Полибианский квадрат" << endl;
	cout << "10.Шифр Триемуса" << endl;
	cout << "11.Выход" << endl;
	cout << "==========================" << endl;
	cout << "==========================" << endl;
	cout << "Введите пунтк меню" << endl;
	cin >> sort_number;
	

	while (sort_number) {
		switch (sort_number)
		{
		case 1: {
			char second_name[50];
			int positions[50];
			char second_name_encrypted[50];
			int second_name_length;

			cout << "Введите фамилию " << endl;
			cin >> second_name;
			second_name_length = strlen(second_name);

			cout << "Введите числа от 1 до " << second_name_length << " в любом порядке, без повторений" << endl;

			for (int i = 0; i < second_name_length; i++) {
				cin >> positions[i];
				positions[i] = positions[i] - 1;
			}

			for (int i = 0; i < second_name_length; i++)
				second_name_encrypted[positions[i]] = second_name[i];

			for (int i = 0; i < second_name_length; i++)
				cout << second_name_encrypted[i];
			cout << endl;
			break;
		}
		case 2: {
			char second_name[50];
			int positions[50];
			char second_name_encrypted[50];
			int second_name_length;
			int block_length;
			int modulo;

			cout << "Введите фамилию " << endl;
			cin >> second_name;
			second_name_length = strlen(second_name);

			cout << "Введите длину блока" << endl;
			cin >> block_length;

			cout << "Введите числа от 1 до " << block_length << " в любом порядке, без повторений" << endl;

			for (int i = 0; i < block_length; i++) {
				cin >> positions[i];
				positions[i] = positions[i] - 1;
			}

			modulo = second_name_length % block_length;

			if (modulo != 0) {
				for (int i = 1; i <= block_length - modulo; i++) {
					second_name[second_name_length - 1 + i] = char('а' + rand() % 33);
				}
				second_name_length = second_name_length + block_length - modulo;
			}

			int k = 1, n = 0;

			while (k*block_length <= second_name_length) {
				for (int i = n * block_length; i < k*block_length; i++) {
					second_name_encrypted[positions[i - block_length * n] + block_length * n] = second_name[i];
				}
				k++;
				n++;
			}

			for (int i = 0; i < second_name_length; i++)
				cout << second_name_encrypted[i];
			cout << endl;
			break;
		}
		case 3: {
			string second_name;
			int positions[50];
			string second_name_encrypted = "";
			int second_name_length;
			int column, row;
			char encryption_table[100][100];
			int index = 0;

			cout << "Введите фамилию и имя" << endl;
			cin.get();
			getline(cin, second_name);

			second_name_length = second_name.length();

			cout << "Введите кол-во столбцов и строк, произведение которых не менее " << second_name_length << endl;
			cin >> column >> row;

			while (second_name_length != column * row) {
				second_name = second_name + ' ';
				second_name_length = second_name.length();
			}

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					encryption_table[i][j] = second_name[index];
					index++;
				}
			}

			for (int i = 0; i < column; i++) {
				for (int j = 0; j < row; j++) {
					second_name_encrypted = second_name_encrypted + encryption_table[j][i];
				}
			}
			cout << second_name_encrypted << endl;
			break;
		}
		case 4: {
			string second_name;
			int positions[50];
			string second_name_encrypted = "";
			int second_name_length;
			int column, row;
			char encryption_table[100][100];
			char table[100][100];
			int index = 0;
			int key;
			int value_current_position;

			cout << "Введите ФИО:" << endl;
			cin.get();
			getline(cin, second_name);
			second_name_length = second_name.length();

			cout << "Введите значение ключа:" << endl;
			cin >> key;
			cout << "Введите числа от 1 до " << key << " включая. В любом порядке, без повторений:" << endl;
			for (int i = 0; i < key; i++)
				cin >> positions[i];

			column = key;
			if (second_name_length%column != 0) {
				row = second_name_length / column + 1;
			}
			else row = second_name_length / column;

			while (second_name_length != column * row) {
				second_name = second_name + ' ';
				second_name_length = second_name.length();
			}

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					table[i][j] = second_name[index];
					index++;
				}
			}

			for (int i = 0; i < key; i++) {
				value_current_position = positions[i];
				for (int j = 0; j < row; j++) {
					encryption_table[value_current_position - 1][j] = table[j][i];
				}
			}
			for (int i = 0; i < column; i++) {
				for (int j = 0; j < row; j++) {
					second_name_encrypted = second_name_encrypted + encryption_table[i][j];
				}
			}
			cout << second_name_encrypted << endl;
			break;
		}
		case 5: {
			string second_name;
			int positions[50];
			int second_name_length;
			string second_name_encrypted = "";

			cout << "Введите фамилию и имя: " << endl;
			cin.get();
			getline(cin, second_name);
			second_name_length = second_name.length();

			if (second_name_length > 16) {
				cout << "Решетка 4*4 не вмещает весь текст" << endl;
				system("pause");
				exit(0);
			}
			else if (second_name_length < 16) {
				for (int i = 0; i < 16 - second_name_length; i++)
					second_name += '_';
			}
			char table[4][4] = { {second_name[0],second_name[8],second_name[6],second_name[14]},
								 {second_name[4],second_name[12],second_name[2],second_name[10]},
								 {second_name[1],second_name[9],second_name[7],second_name[15]},
								 {second_name[5],second_name[13],second_name[3],second_name[11]} };

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					second_name_encrypted += table[i][j];
				}
			}

			cout << second_name_encrypted << endl;
			cout << endl;
			break;
		}
		case 6: {
			const int size = 4;
			const int table[size][size] = {
				{ 16,  3,  2, 13 },
				{  5, 10, 11,  8 },
				{ 9,  6,  7, 12 },
				{  4, 15,  14,  1 }
			};
			char   second_name_encrypted[size][size];
			string second_name;
			int second_name_length;

			for (int i = 0; i < size; ++i)
				for (int j = 0; j < size; ++j)
					second_name_encrypted[i][j] = ' ';

			cout << "Введите фамилию и имя: ";
			cin.get();
			getline(cin,second_name);

			second_name_length = second_name.length();
			while (second_name_length != 16) {
				second_name = second_name + '.';
				second_name_length = second_name.length();
			}
			

			for (int current = 0; current < second_name.length(); ++current) {
				for (int i = 0; i < size; ++i)
					for (int j = 0; j < size; ++j) {
						if (table[i][j] == (current + 1)) {
							second_name_encrypted[i][j] = second_name[current];
							goto next;
						}
					}
			next:
				;
			}

			for (int i = 0; i < size; ++i)
				for (int j = 0; j < size; ++j)
					if (0 != second_name_encrypted[i][j])
						cout << second_name_encrypted[i][j];
			cout << endl;
			break;
		}
		case 7: {
			string second_name;
			int key;
			string second_name_encrypted;
			const string alfabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";


			cout << "Введите фамилию" << endl;
			cin >> second_name;
			cout << "Введите ключ" << endl;
			cin >> key;
			int alffbet_length = alfabet.length();
			string chiffered_message = "";
			for (int i = 0; i < second_name.length(); i++)
			{
				char c = second_name[i];
				int index = -1;
				for (int i = 0; i < alffbet_length; ++i)
					if (alfabet[i] == c)
						index = i;

				if (index < 0)
				{
					chiffered_message += char(c);
				}
				else
				{
					int coded_element_index = (alffbet_length + index + key) % alffbet_length;
					chiffered_message += alfabet[coded_element_index];
				}
			}
			cout << chiffered_message << endl;
			break;
		}
		case 8: {
			const string ABC = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
			string second_name;
			int second_name_length;
			string encrypted_ABC = "";
			string slogan;
			string second_name_encrypted = "";
			int slogan_length;
			int pos;

			cout << "Введите фамилию:" << endl;
			cin.get();
			getline(cin, second_name);
			second_name_length = second_name.length();
			cout << "Введите лозунг:" << endl;
			cin.get();
			getline(cin, slogan);
			slogan_length = slogan.length();

			encrypted_ABC += slogan[0];
			for (int i = 0; i < slogan_length; i++) {
				if (encrypted_ABC.find(slogan[i]) == -1)
					encrypted_ABC += slogan[i];
			}
			for (int i = 0; i < ABC.length(); i++) {
				if (encrypted_ABC.find(ABC[i]) != -1)
					i++;
				encrypted_ABC += ABC[i];

			}
			for (int i = 0; i < second_name_length; i++) {
				pos = ABC.find(second_name[i]);
				if (pos == -1) {
					cout << "В фамилии присутствует символ, отсутствующий в алфавите" << endl;
					system("pause");
					exit(0);
				}
				else second_name_encrypted += encrypted_ABC[pos];
			}

			cout << second_name_encrypted << endl;
			cout << endl;
			break;
		}
		case 9: {
			string second_name;
			int second_name_length;
			int key1, key2;
			map <char, int> mp;
			list <char> ls;

			cout << "Введите фамилию:" << endl;
			cin.get();
			getline(cin, second_name);
			second_name_length = second_name.length();

			key1 = 'а';
			key2 = 'я';

			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					if (key1 <= key2) {
						ls.push_back(char(key1));
						mp[char(key1)] = char((i + 1) * 10 + j + 1);
					}
					else
						ls.push_back(' ');
					key1 += 1;
				}
			}

			map <char, int> ::iterator it;
			for (int i = 0; i < second_name_length; i++) {
				it = mp.find(second_name[i]);
				cout << it->second << " ";
			}

			cout << endl;
			break;
		}
		case 10: {
			const string ABC = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
			string second_name;
			int second_name_length;
			string encrypted_ABC = "";
			int encrypted_ABC_length;
			char table[6][6];
			string key;
			string second_name_encrypted = "";
			int key_length;
			int pos;

			cout << "Введите фамилию:" << endl;
			cin.get();
			getline(cin, second_name);
			second_name_length = second_name.length();
			cout << "Введите ключевое слово:" << endl;
			cin.get();
			getline(cin, key);
			key_length = key.length();


			encrypted_ABC += key[0];
			for (int i = 0; i < key_length; i++) {
				if (encrypted_ABC.find(key[i]) == -1)
					encrypted_ABC += key[i];
			}
			for (int i = 0; i < ABC.length(); i++) {
				if (encrypted_ABC.find(ABC[i]) != -1)
					i++;
				encrypted_ABC += ABC[i];
			}
			encrypted_ABC_length = encrypted_ABC.length();
			for (int i = 0; i < 36 - encrypted_ABC_length; i++)
				encrypted_ABC += " ";
			encrypted_ABC_length = encrypted_ABC.length();
			int k = 0;
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					table[i][j] = encrypted_ABC[k];
					k++;
				}
			}
			//for (int i = 0; i < 6; i++) {
			//	for(int j =0; j<6; j++)
			//		cout << table[i][j]<<" ";
			//	}
			for (int k = 0; k < second_name_length; k++) {
				for (int i = 0; i < 6; i++) {
					for (int j = 0; j < 6; j++) {
						if (table[i][j] == second_name[k]) {
							if (i != 5)
								second_name_encrypted += table[i + 1][j];
							else second_name_encrypted += table[0][j];
						}
					}
				}
			}

			cout << second_name_encrypted << endl;
			break;
		}
		case 11: {
			exit(0);
			break;
			 }
		default:
			cout << "Нет такого пункта меню" << endl;
			break;
		}
		cout << "==========================" << endl;
		cout << "==========================" << endl;
		cout << "Введите пунтк меню" << endl;
		cin >> sort_number;
	}
}