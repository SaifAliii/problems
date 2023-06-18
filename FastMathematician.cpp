#include<iostream>
#include<string>
std::string calculateSum(std::string str1, std::string str2)
{
	std::string res;
	int i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] == str2[i])
		{
			res += '0';
		}
		else
		{
			res += '1';
		}
		i++;
	}
	return res;
}
int main()
{
	std::string str1;
	std::string str2;
	std::cin >> str1 >> str2;
	std::cout << calculateSum(str1, str2);
	return 0;
}