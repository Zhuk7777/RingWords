#include <iostream>

std::string reverseLastNsymbol(std::string str, int n);
void ring(std::string* mas, std::string* cur, std::string* result, int* used, int size, int n, int flag = 0, int j = 0);

int main()
{
	setlocale(0, "rus");

	int n, size;
	std::string str;

	std::cout << "¬ведите количество слов\n";

	std::cin >> size;

	std::string* mas = new std::string[size];

	for (int i = 0; i < size; i++)
	{
		std::cout << "¬ведите слово\n";
		std::cin >> str;
		mas[i] = str;
		std::cout << std::endl;
	}

	std::string* result = new std::string[size];
	std::string* cur = new std::string[size];
	int* used = new int[size];
	for (int i = 0; i < size; i++)
	{
		result[i] = "";
		used[i] = 0;
		cur[i] = "";
	}

	std::cout << "¬введите n\n";
	std::cin >> n;

	ring(mas, cur, result, used, size, n);
	for (int i = 0; i < size; i++)
		std::cout << result[i] << " ";

	return 0;
}


std::string reverseLastNsymbol(std::string str, int n)
{
	int size = str.size();
	std::string result;

	for (int i = size - 1; i >= size - n; i--)
		result += str[i];

	return result;

}

void ring(std::string* mas, std::string* cur, std::string* result, int* used, int size, int n, int flag, int j)
{
	for (int i = 0; i < size; i++)
	{
		if (j >= size && cur[j - 1] != "")
		{
			if (cur[0].substr(0, n) == reverseLastNsymbol(cur[j - 1], n)) {
				for (int i = 0; i < size; i++)
					result[i] = cur[i];
			}
			return;
		}
		if (!flag)
		{
			cur[j] = mas[i];
			used[i] = 1;
			ring(mas, cur, result, used, size, n, flag + 1, j + 1);
			used[i] = 0;
		}


		if (used[i] != 1 && flag) {
			if (mas[i].substr(0, 2) == reverseLastNsymbol(cur[j - 1], n))
			{
				cur[j] = mas[i];
				used[i] = 1;
				ring(mas, cur, result, used, size, n, flag + 1, j + 1);
				used[i] = 0;
			}
		}
	}
}