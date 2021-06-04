#include<iostream>
#include<fstream>
using namespace std;
void print_Tab(int tab)
{
	for (int i = 0; i < tab; i++)
	{
		cout << "	";
	}
}
int look = 0;
char *ary;
int tab = 0;
int counter_brackets = 0;
char *ptr_lc = { "'" };
ifstream fin1("input.txt");
ifstream fin("input.txt");
void Data_Type(char *ptr)
{
	char *ary1 = new char[20];
	int i = 0;
	while (ptr[look] != ':')
	{
		ary1[i] = ptr[look];
		look++;
		i++;
	}
	ary1[i] = '\0';
	if (strcmp(ary1, "char") == 0 || strcmp(ary1, "char ") == 0 || strcmp(ary1, "int") == 0 || strcmp(ary1, "int ") == 0)
	{
		tab++;
		print_Tab(tab);
		cout << "Data_Type" << endl;
		tab++;
		print_Tab(tab);
		cout << ary1 << endl;
		tab--;
		tab--;
	}

	tab++;
	print_Tab(tab);
	cout << "Variable_declaration_operator" << endl;
	tab++;
	print_Tab(tab);
	cout << ptr[look] << endl;
	tab--;
	tab--;
	look++;
}
char * get_val(char * ptr)
{
	char *ary1 = new char[20];
	int i = 0;
	while (ptr[look] != '(' &&ptr[look] != ':'&&ptr[look] != ')'&&ptr[look] != ';'&&ptr[look] != '<'&&ptr[look] != '>'&&ptr[look] != ',')
	{
		ary1[i] = ptr[look];
		look++;
		i++;
	}
	ary1[i] = '\0';
	return ary1;
}


void Function_1(char *ptr)
{
	char *ary1;
	Data_Type(ptr);

	tab++;
	print_Tab(tab);
	cout << "Identifier" << endl;
	tab++;
	print_Tab(tab);
	ary1 = get_val(ptr);
	cout << ary1 << endl;
	tab--;
	tab--;

	tab++;
	print_Tab(tab);
	cout << "Bracket" << endl;
	tab++;
	print_Tab(tab);
	cout << ptr[look] << endl;
	tab--;
	tab--;
	look++;


	Data_Type(ptr);
	tab++;
	print_Tab(tab);
	cout << "Identifier" << endl;
	tab++;
	print_Tab(tab);
	ary1 = get_val(ptr);
	cout << ary1 << endl;
	tab--;
	tab--;

	if (ptr[look] == ',')
	{
		while (ptr[look] != ';')
		{
			if (ptr[look] == ',')
			{
				tab++;
				print_Tab(tab);
				cout << "Comma" << endl;
				tab++;
				print_Tab(tab);
				cout << "," << endl;
				tab--;
				tab--;
				look++;

				Data_Type(ptr);
			}
			else if (ptr[look] == ')')
			{
				tab++;
				print_Tab(tab);
				cout << "bracket" << endl;
				tab++;
				print_Tab(tab);
				cout << ")" << endl;
				tab--;
				tab--;
				break;
			}
			else
			{
				tab++;
				print_Tab(tab);
				cout << "Identifier" << endl;
				tab++;
				print_Tab(tab);
				ary1 = get_val(ptr);
				cout << ary1 << endl;
				tab--;
				tab--;
			}
			//look++;
		}
	}
	tab++;
	tab++;
}
int  Chek_type(char *ptr)
{
	int look_v = 0;
	int len = strlen(ptr);
	char *ptr1 = new char[100];
	int i = 0;
	while (look_v<len)
	{
		if (ptr[look_v] == ' ')
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "ret") == 0)  // return
			{
				return 1;
			}
			if (strcmp(ptr1, "while") == 0 || strcmp(ptr1, "if") == 0)  //condition
			{
				return 2;
			}
			if (strcmp(ptr1, "write") == 0)   // output
			{
				return 3;
			}
		}
		if (ptr[look_v] == ':' && ptr[look_v + 1] == '=') // assign
		{
			return 4;
		}
		if (ptr[look_v] == '>' && ptr[look_v + 1] == '>') //input
		{
			return 5;
		}
		if (ptr[look_v] == '(')
		{

			ptr1[i] = '\0';
			if (strcmp(ptr1, "while") == 0 || strcmp(ptr1, "if") == 0)   // condition
			{
				return 2;
			}
			if (strcmp(ptr1, "write") == 0)  //output
			{
				return 3;
			}
		}
		if (ptr[look_v] == '/' && ptr[look_v + 1] == '*')  // comment
		{
			return 6;
		}
		if (ptr[look_v] == '{' || ptr[look_v] == '}')  //function start or end
		{
			return 7;
		}
		if (ptr[look_v] == ',' || ptr[look_v] == ';') // variable declaration
		{
			return 8;
		}
		ptr1[i] = ptr[look_v];
		look_v++;
		len++;
		i++;
	}
}
void Function1(char *ptr)
{
	char * ary1;
	int len = strlen(ptr);
	char *ptr1 = new char[100];
	int i = 0;
	while (ptr[look] != ' ')
	{
		ptr1[i] = ptr[look];
		look++;
		i++;
	}
	ptr1[i] = '\0';
	tab++;
	print_Tab(tab);
	cout << "Keyword" << endl;
	tab++;
	print_Tab(tab);
	cout << ptr1 << endl;
	tab--;
	tab--;

	tab++;
	print_Tab(tab);
	cout << "Identifier" << endl;
	tab++;
	print_Tab(tab);
	ary1 = get_val(ptr);
	cout << ary1 << endl;
	tab--;
	tab--;

	tab++;
	print_Tab(tab);
	cout << "Semi colon" << endl;
	tab++;
	print_Tab(tab);
	cout << ";" << endl;
	tab--;
	tab--;
}
void Function7(char *ptr)
{
	tab++;
	print_Tab(tab);
	cout << "Bracket" << endl;
	tab++;
	print_Tab(tab);
	if (ptr[look] == '{')
	{
		tab++;
		tab++;
	}
	if (ptr[look] == '}')
	{
		tab--;
		tab--;
	}

	cout << ptr[look] << endl;
	tab--;
	tab--;


}
void Function5(char *ptr)
{
	char *ary1;
	tab++;
	print_Tab(tab);
	cout << "Keyword" << endl;
	tab++;
	print_Tab(tab);
	ary1 = get_val(ptr);
	cout << ary1 << endl;
	tab--;
	tab--;

	tab++;
	print_Tab(tab);
	cout << "Input Operator" << endl;
	tab++;
	print_Tab(tab);
	cout << ">>" << endl;
	tab--;
	tab--;
	look++;
	look++;

	tab++;
	print_Tab(tab);
	cout << "Identifier" << endl;
	tab++;
	print_Tab(tab);
	ary1 = get_val(ptr);
	cout << ary1 << endl;
	tab--;
	tab--;

	tab++;
	print_Tab(tab);
	cout << "semi colon" << endl;
	tab++;
	print_Tab(tab);
	cout << ";" << endl;
	tab--;
	tab--;


}
void Function6(char *ptr)
{
	int len = strlen(ptr);
	if (ptr[len - 1] == '/' && ptr[len - 2] == '*')
	{
		tab++;
		print_Tab(tab);
		cout << "comment" << endl;
		tab++;
		print_Tab(tab);
		cout << ptr << endl;
		tab--;
		tab--;
	}
	else
	{
		tab++;
		print_Tab(tab);
		cout << "comment" << endl;
		tab++;
		print_Tab(tab);
		cout << ptr << endl;
		tab--;

		fin.getline(ptr, 100);
		int len = strlen(ptr);
		while (ptr[len - 1] != '/' && ptr[len - 2] != '*')
		{
			tab++;
			print_Tab(tab);
			cout << ptr << endl;
			tab--;

			fin.getline(ptr, 100);
			len = strlen(ptr);
		}
		tab++;
		print_Tab(tab);
		cout << ptr << endl;
		tab--;
		tab--;
	}
}
void Function3(char *ptr)
{
	char *ary1;
	tab++;
	print_Tab(tab);
	cout << "Keyword" << endl;
	tab++;
	print_Tab(tab);
	ary1 = get_val(ptr);
	cout << ary1 << endl;
	tab--;
	tab--;

	tab++;
	print_Tab(tab);
	cout << "Bracket" << endl;
	tab++;
	print_Tab(tab);
	cout << "(" << endl;
	tab--;
	tab--;
	look++;

	char *a = new char[2];
	a[0] = ptr[look];
	char *s1 = new char[40];
	int i = 0;
	if (ptr[look] == '"')
	{
		while (ptr[look] != ')')
		{
			s1[i] = ptr[look];
			i++;
			look++;
		}
		s1[i] = '\0';
		tab++;
		print_Tab(tab);
		cout << "String" << endl;

		tab++;
		print_Tab(tab);
		cout << s1 << endl;
		tab--;

		tab--;
	}
	else if (ptr[look] == ptr_lc[0])
	{
		while (ptr[look] != ')')
		{
			s1[i] = ptr[look];
			i++;
			look++;
		}
		s1[i] = '\0';
		tab++;
		print_Tab(tab);
		cout << "Literal Constant" << endl;

		tab++;
		print_Tab(tab);
		cout << s1 << endl;
		tab--;

		tab--;
	}
	else
	{
		while (ptr[look] != ')')
		{
			s1[i] = ptr[look];
			i++;
			look++;
		}
		s1[i] = '\0';
		tab++;
		print_Tab(tab);
		cout << "Identifier" << endl;
		tab++;
		print_Tab(tab);
		cout << s1 << endl;
		tab--;
		tab--;
	}

	tab++;
	print_Tab(tab);
	cout << "Bracket" << endl;
	tab++;
	print_Tab(tab);
	cout << ")" << endl;
	tab--;
	tab--;

	tab++;
	print_Tab(tab);
	cout << "semicolon" << endl;
	tab++;
	print_Tab(tab);
	cout << ";" << endl;
	tab--;
	tab--;

}
void Function2(char *ptr)
{
	char *ary1;
	tab++;
	print_Tab(tab);
	cout << "Keyword" << endl;
	tab++;
	print_Tab(tab);
	ary1 = get_val(ptr);
	cout << ary1 << endl;
	tab--;
	tab--;

	tab++;
	print_Tab(tab);
	cout << "Bracket" << endl;
	tab++;
	print_Tab(tab);
	cout << "(" << endl;
	tab--;
	tab--;

	tab++;
	print_Tab(tab);
	cout << "Keyword" << endl;
	tab++;
	print_Tab(tab);
	ary1 = get_val(ptr);
	cout << ary1 << endl;
	tab--;
	tab--;

	tab++;
	print_Tab(tab);
	cout << "Operator" << endl;
	tab++;
	print_Tab(tab);
	cout << ptr[look] << endl;
	tab--;
	tab--;
	look++;


	ary1 = get_val(ptr);
	int ary_len1 = strlen(ary1);
	char Nc[] = { '0', '1','2', '3', '4', '5', '6', '7', '8', '9' };
	bool flag = false;
	for (int m = 0; m < 10; m++)
	{
		for (int n = 0; n < ary_len1; n++)
		{
			if (ary1[n] == Nc[m])
			{
				flag = true;
			}
		}
	}

	if (flag == true)
	{
		tab++;
		print_Tab(tab);
		cout << "Literal constant" << endl;
		tab++;
		print_Tab(tab);
		cout << ary1 << endl;
		tab--;
		tab--;
	}
	else
	{
		tab++;
		print_Tab(tab);
		cout << "Identifier" << endl;
		tab++;
		print_Tab(tab);
		cout << ary1 << endl;
		tab--;
		tab--;
	}


	tab++;
	print_Tab(tab);
	cout << "Bracket" << endl;
	tab++;
	print_Tab(tab);
	cout << ")" << endl;
	tab--;
	tab--;
}
void Function4(char *ptr)
{
	char *ary1;
	tab++;
	print_Tab(tab);
	cout << "Identifier" << endl;
	tab++;
	print_Tab(tab);
	ary1 = get_val(ptr);
	cout << ary1 << endl;
	tab--;
	tab--;

	tab++;
	print_Tab(tab);
	cout << "assignment Operator" << endl;
	tab++;
	print_Tab(tab);
	cout << ":=" << endl;
	tab--;
	tab--;
	look++;
	look++;

	char *s1 = new char[40];
	int i = 0;
	if (ptr[look] == ptr_lc[0])
	{
		while (ptr[look] != ';')
		{
			s1[i] = ptr[look];
			i++;
			look++;
		}
		s1[i] = '\0';
		tab++;
		print_Tab(tab);
		cout << "Literal Constant" << endl;

		tab++;
		print_Tab(tab);
		cout << s1 << endl;
		tab--;

		tab--;
	}
	else
	{
		tab++;
		print_Tab(tab);
		cout << "Identifier" << endl;
		tab++;
		print_Tab(tab);
		ary1 = get_val(ptr);
		cout << ary1 << endl;
		tab--;
		tab--;
	}

	tab++;
	print_Tab(tab);
	cout << "semi colon" << endl;
	tab++;
	print_Tab(tab);
	ary1 = get_val(ptr);
	cout << ary1 << endl;
	tab--;
	tab--;
}
void Function8(char *ptr)
{
	char *ary1;
	Data_Type(ptr);

	tab++;
	print_Tab(tab);
	cout << "Identifier" << endl;
	tab++;
	print_Tab(tab);
	ary1 = get_val(ptr);
	cout << ary1 << endl;
	tab--;
	tab--;



	if (ptr[look] == ',')
	{
		while (ptr[look] != ';')
		{
			if (ptr[look] == ',')
			{
				tab++;
				print_Tab(tab);
				cout << "Comma" << endl;
				tab++;
				print_Tab(tab);
				cout << "," << endl;
				tab--;
				tab--;
				look++;

				//Data_Type(ptr);
			}
			else
			{
				tab++;
				print_Tab(tab);
				cout << "Identifier" << endl;
				tab++;
				print_Tab(tab);
				ary1 = get_val(ptr);
				cout << ary1 << endl;
				tab--;
				tab--;
			}
			//look++;
		}
	}

	tab++;
	print_Tab(tab);
	cout << "semi colon" << endl;
	tab++;
	print_Tab(tab);
	cout << ";" << endl;
	tab--;
	tab--;
}
void Functionptr(char * ptr, int value)
{
	if (value == 1)
	{
		Function1(ptr);
	}
	else if (value == 2)
	{
		Function2(ptr);
	}
	else if (value == 3)
	{
		Function3(ptr);
	}
	else if (value == 4)
	{
		Function4(ptr);
	}
	else if (value == 5)
	{
		Function5(ptr);
	}
	else if (value == 6)
	{
		Function6(ptr);
	}
	else if (value == 7)
	{
		Function7(ptr);
	}
	else if (value == 8)
	{
		Function8(ptr);
	}
}
void Function(char *ptr)
{

	tab++;
	print_Tab(tab);
	cout << "Programme" << endl;

	tab++;
	print_Tab(tab);
	cout << "Function_declaration " << endl;
	Function_1(ptr);

	tab--;
	tab--;
}


int  new_chek_type(char *ptr)
{
	int look_v = 0;
	int len = strlen(ptr);
	char *ptr1 = new char[100];
	char *ptr2 = nullptr;
	int i = 0;
	if (ptr[look_v] == '{')  //function start or end
	{
		return 8;
	}
	if (ptr[look_v] == '}')  //function start or end
	{
		return 9;
	}

	while (look_v < len)
	{
		if (ptr[look_v] == '/' && ptr[look_v + 1] == '*')  // comment
		{
			return 6;
		}
		if (ptr[len-1] == '/' && ptr[len-2] == '*')  // comment
		{
			return 6;
		}
		look_v++;
		//len++;
	}

	look_v = 0;
	len = strlen(ptr);
	//ptr1 =nullptr;
	//ptr2 = nullptr;
	i = 0;
	while (look_v < len)
	{
		if (ptr[look_v] == ' ')
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "read") == 0)  // input
			{
				return 5;
			}
			look_v++;
		}
		if (ptr[look_v] == '>' && ptr[look_v + 1] == '>') //input
		{
			return 5;
		}
		if (ptr[look_v] == '>') //input
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "read") == 0)  // input
			{
				return 5;
			}
			look_v++;
		}
		ptr1[i] = ptr[look_v];
		look_v++;
		//len++;
		i++;
	}


	look_v = 0;
	len = strlen(ptr);
	//ptr1 = NULL;
	//ptr2 = NULL;
	i = 0;
	while (look_v < len)
	{
		if (ptr[look_v] == ' ')
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "write") == 0)   // output
			{
				return 3;
			}
			look_v++;
		}
		if (ptr[look_v] == '"') 
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "write") == 0)   // output
			{
				return 3;
			}
			look_v++;
		}
		ptr1[i] = ptr[look_v];
		look_v++;
		//len++;
		i++;
	}



	look_v = 0;
	len = strlen(ptr);
	//ptr1 = NULL;
	//ptr2 = NULL;
	i = 0;
	while (look_v < len)
	{
		if (ptr[look_v] == ' ')
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "while") == 0 || strcmp(ptr1, "if") == 0)  //condition
			{
				return 2;
			}
			look_v++;
		}
		if (strcmp(ptr1, "while") == 0 || strcmp(ptr1, "if") == 0)  //condition
		{
			return 2;
		}
		if (ptr[look_v] == '>' && ptr[look_v+1] != '>')
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "read") != 0)  //condition
			{
				return 2;
			}
			look_v++;
					
		}
		ptr1[i] = ptr[look_v];
		look_v++;
		//len++;
		i++;
	}

	look_v = 0;
	len = strlen(ptr);
	//ptr1 = NULL;
	//ptr2 = NULL;
	i = 0;
	while (look_v < len)
	{
		if (ptr[look_v] == ':' || ptr[look_v] == '=')
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "char") != 0 && strcmp(ptr1, "int") != 0 && strcmp(ptr1, "char ") != 0 && strcmp(ptr1, "int ") != 0) // assign
			{
				return 4;
			}
			look_v++;

		}
		if (ptr[look_v] == ':' && ptr[look_v + 1] == '=') // assign
		{
			return 4;
		}
		ptr1[i] = ptr[look_v];
		look_v++;
		//len++;
		i++;
	}

	look_v = 0;
	len = strlen(ptr);
	//ptr1 = NULL;
	//ptr2 = NULL;
	i = 0;
	while (look_v < len)
	{
		if (ptr[look_v] == ' ')
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "ret") == 0)  // return
			{
				return 1;
			}
			look_v++;
		}
		if (ptr[0] == 'r' &&ptr[1] == 'e'&&ptr[2] == 't')
		{
			if (ptr[len] == ';')  // return
			{
				return 1;
			}
		}
		ptr1[i] = ptr[look_v];
		look_v++;
		//len++;
		i++;
	}


	look_v = 0;
	len = strlen(ptr);
	//ptr1 = NULL;
	//ptr2 = NULL;
	i = 0;
	while (look_v < len)
	{
		if (ptr[look_v] == ':')
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "char") == 0 && strcmp(ptr1, "int") == 0 && strcmp(ptr1, "char ") == 0 && strcmp(ptr1, "int ") == 0) // variable declaration
			{
				return 7;
			}
			look_v++;
		}
		if (ptr[look_v] == ',') // variable declaration
		{
			return 7;
		}
		if (ptr[look_v] == ':' &&ptr[look_v] != '=') // variable declaration
		{
			return 7;
		}

		if (ptr[look_v] == ' ')
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "char") == 0 && strcmp(ptr1, "int") == 0 && strcmp(ptr1, "char ") == 0 && strcmp(ptr1, "int ") == 0) // variable declaration
			{
				return 7;
			}
			look_v++;
		}
		ptr1[i] = ptr[look_v];
		look_v++;
		//len++;
		i++;
	}
}

int c_v1(char * ptr)
{
	int len1 = strlen(ptr);
	int j = 0;
	bool flag = 0;
	while (j < len1)
	{
		if ((ptr[j] >= 'a' && ptr[j] <= 'z') || (ptr[j] >= 'A' && ptr[j] <= 'Z') || (ptr[j] == '_'))
		{
			flag = 1;
		}
		else
		{
			return 0;
		}
		j++;
	}
}
int c_f1(char * ptr)
{
	int len1 = strlen(ptr);
	int j = 0;
	int i = 0;
	char *ptr1 = new char[100];
	bool flag = 0;
	while (j < len1)
	{
		if (ptr[j] == ':')
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "char") != 0 && strcmp(ptr1, "int") != 0 && strcmp(ptr1, "char ") != 0 && strcmp(ptr1, "int ") != 0)
			{
				return 0;
			}
			flag = 1;
			i = 0;
			j++;
			//ptr1 = NULL;
		}
		ptr1[i] = ptr[j];
		j++;
		i++;
	}
	ptr1[i] = '\0';
	
	if (c_v1(ptr1) == 0)
	{
		return 0;
	}
	if (flag == 0)
	{
		return 0;
	}
	return 1;
}
int c_if(char *ptr)
{
	int look_v = 0;
	int len = strlen(ptr);
	char *ptr1 = new char[100];
	char *ptr2 = new char[100];
	bool flag = 0;
	int i = 0;
	while (look_v < len)
	{
		if (ptr[look_v] == '<' || ptr[look_v] == '>' || ptr[look_v] == '=')
		{
			ptr1[i] = '\0';
			if (c_v1(ptr1) == 0)
			{
				return 0;
			}
		}
		ptr1[i] = ptr[look_v];
		look_v++;
		i++;
	}
	return 1;
}
int check_function_dec_error(char * ptr)
{
	int look_v = 0;
	int len = strlen(ptr);
	char *ptr1 = new char[100];
	bool flag = 0;
	int i = 0;
	if (ptr[len - 1] != ')')
	{
		return 0;
	}
	while (ptr[look_v]!=':' && look_v<len)
	{
		ptr1[i]=ptr[look_v];
		look_v++;
		i++;
	}
	if (ptr[look_v] == ':')
	{
		ptr1[i] = '\0';
		if (strcmp(ptr1, "char") != 0 && strcmp(ptr1, "int") != 0 && strcmp(ptr1, "char ") != 0 && strcmp(ptr1, "int ") != 0)
		{
			return 0;
		}
		flag = 1;
		look_v++;
	}
	i =0;
	//ptr1 = NULL;
	while ((ptr[look_v] != '(' && look_v<len))
	{
		ptr1[i] = ptr[look_v];
		flag = 0;
		look_v++;
		i++;
	}
	ptr1[i] = '\0';
	look_v++;
	if (c_v1(ptr1) == 0)
	{
		return 0;
	}
	if (look_v == len - 1)
	{
		flag = 1;
		return 0;
	}
	i = 0;
	//ptr1 = NULL;
	int cnt_c = 0;
	int cnt_s = 0;
	while (look_v<len)
	{
		if (ptr[look_v] == ',')
		{
			ptr1[i] = '\0';
			if (c_f1(ptr1) == 0)
			{
				return 0;
			}
			i = 0;
			//ptr1 = NULL;
			cnt_c++;
			look_v++;
		}
		if (ptr[look_v] == ':')
		{
			cnt_s++;
			//ptr1[i] = ptr[look_v];
			//look_v++;
		}
		ptr1[i] = ptr[look_v];
		look_v++;
		i++;
	}
	if (cnt_c + 1 != cnt_s)
	{
		return 0;
	}
	return 1;
}

int check_variable_dec_error(char * ptr)
{
	int look_v = 0;
	int len = strlen(ptr);
	char *ptr1 = new char[100];
	bool flag = 0;
	int i = 0;
	if (ptr[len - 1] != ';')
	{
		return 0;
	}
	while (ptr[look_v] != ':' && look_v<len)
	{
		ptr1[i] = ptr[look_v];
		look_v++;
		i++;
	}
	if (ptr[look_v] == ':')
	{
		ptr1[i] = '\0';
		if (strcmp(ptr1, "char") != 0 && strcmp(ptr1, "int") != 0 && strcmp(ptr1, "char ") != 0 && strcmp(ptr1, "int ") != 0)
		{
			return 0;
		}
		flag = 1;
		look_v++;
	}
	i = 0;
	//ptr1 = NULL;
	while (look_v<len)
	{
		if (ptr[look_v] == ',')
		{
			ptr1[i] = '\0';
			if (c_v1(ptr1) == 0)
			{
				return 0;
			}
			i = 0;
			look_v++;
			//ptr1 = NULL;
		}
		ptr1[i] = ptr[look_v];
		look_v++;
		i++;
	}
	return 1;
}

int check_input_error(char*ptr)
{
	int look_v = 0;
	int len = strlen(ptr);
	char *ptr1 = new char[100];
	bool flag = 0;
	int i = 0;
	if (ptr[len - 1] != ';')
	{
		return 0;
	}
	while (look_v < len)
	{
		if (ptr[look_v] == ' ')
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "read") != 0)  // input
			{
				return 0;
			}
			look_v++;
		}
		if (ptr[look_v] == '>' && ptr[look_v+1] == '>')
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "read") != 0 && strcmp(ptr1, "read ") != 0)  // input
			{
				return 0;
			}
			return 1;
		}
		ptr1[i] = ptr[look_v];
		i++;
		look_v++;
	}
	return 1;
}

int check_output_error(char*ptr)
{
	int look_v = 0;
	int len = strlen(ptr);
	char *ptr1 = new char[100];
	char *ptr2 = new char[100];
	bool flag = 0;
	int i = 0;
	int j = 0;
	if (ptr[len - 1] != ';')
	{
		return 0;
	}
	if (ptr[len-2] != ')')
	{
		return 0;
	}
	while (look_v < len)
	{
		if (ptr[look_v] == ' ')
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "write") != 0)  // input
			{
				return 0;
			}
			look_v++;
		}
		if (ptr[look_v] == '(')
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "write") != 0)  // input
			{
				return 0;
			}
			while (ptr[look_v] != ')' && (look_v <len))
			{
				ptr2[j] = ptr[look_v];
				j++;
				look_v++;
			}
			ptr2[j] = '\0';
			if (c_v1(ptr2) == 0)
			{
				return 0;
			}
			look_v++;
		}
		if (ptr[look_v] == '"')
		{
			while (ptr[look_v] != '"' && (look_v <len))
			{
				look_v++;
			}
			if (look_v == len - 1)
			{
				return 0;
			}
			look_v++;
		}
		ptr1[i] = ptr[look_v];
		i++;
		look_v++;
	}
	return 1;
}

int check_ret_error(char*ptr)
{
	int look_v = 0;
	int len = strlen(ptr);
	char *ptr1 = new char[100];
	char *ptr2 = new char[100];
	bool flag = 0;
	int i = 0;
	int j = 0;
	if (ptr[len - 1] != ';')
	{
		return 0;
	}
	while (look_v < len)
	{
		if (ptr[look_v] == ' ')
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "ret") != 0)  // input
			{
				return 0;
			}
			if (ptr[look_v] == ' ')
			{
				look_v++;
			}
			while (ptr[look_v] != ';' && (look_v < len))
			{
				ptr2[j] = ptr[look_v];
				j++;
				look_v++;
			}
			ptr2[j] = '\0';
			if (c_v1(ptr2) == 0)
			{
				return 0;
			}
			look_v++;
		}
		ptr1[i] = ptr[look_v];
		i++;
		look_v++;
	}
	return 1;
}

int check_comment_error(char*ptr)
{
	int look_v = 0;
	int len = strlen(ptr);
	char *ptr1 = new char[100];
	char *ptr2 = new char[100];
	bool flag = 0;
	int i = 0;
	int j = 0;
	if (ptr[len - 1] != '/')
	{
		return 0;
	}
	if (ptr[len - 2] != '*')
	{
		return 0;
	}
	if (ptr[0] != '/')
	{
		return 0;
	}
	if (ptr[1] != '*')
	{
		return 0;
	}
	return 1;
}

int check_condition_error(char*ptr)
{
	int look_v = 0;
	int len = strlen(ptr);
	char *ptr1 = new char[100];
	char *ptr2 = new char[100];
	bool flag = 0;
	int i = 0;
	int j = 0;
	if (ptr[len - 1] != ')')
	{
		return 0;
	}
	while (look_v < len)
	{
		if (ptr[look_v] == ' ')
		{
			ptr1[i] = '\0';
			if (strcmp(ptr1, "while") != 0 && strcmp(ptr1, "if") != 0)  
			{
				return 0;
			}
			look_v++;
		}
		if (ptr[look_v] == '(')
		{
			ptr1[i] = '\0';
			look_v++;
			if (strcmp(ptr1, "while") != 0 && strcmp(ptr1, "if") != 0 && strcmp(ptr1, "while ") != 0 && strcmp(ptr1, "if ") != 0)
			{
				return 0;
			}
			while (ptr[look_v] != ')' && (look_v <len))
			{
				ptr2[j] = ptr[look_v];
				j++;
				look_v++;
			}
			ptr2[j] = '\0';
			if (c_if(ptr2) == 0)
			{
				return 0;
			}
			//look_v++;
		}
		ptr1[i] = ptr[look_v];
		i++;
		look_v++;
	}
}
int check_assign_error(char*ptr)
{
	int look_v = 0;
	int len = strlen(ptr);
	char *ptr1 = new char[100];
	char *ptr2 = new char[100];
	bool flag = 0;
	int i = 0;
	int j = 0;
	if (ptr[len - 1] != ';')
	{
		return 0;
	}
	while (look_v < len)
	{
		if (ptr[look_v] == ' ')
		{
			ptr1[i] = '\0';
			if (c_v1(ptr1) == 0)
			{
				return 0;
			}
			look_v++;
		}
		if (ptr[look_v] == ':')
		{
			ptr1[i] = '\0';
			if (c_v1(ptr1) == 0)
			{
				return 0;
			}
			i = 0;
			look_v++;
		}
		if (ptr[look_v] == ':' &&ptr[look_v+1] == '=')
		{
			ptr1[i] = '\0';
			if (c_v1(ptr1) == 0)
			{
				return 0;
			}
			look_v++;
			look_v++;
		}

		if (ptr[look_v] == ':')
		{
			if (ptr[look_v+1]!= '=')
			{
				return 0;
			}
			look_v++;
		}
		if (ptr[look_v] == '=')
		{
			if (ptr[look_v-1] != ':')
			{
				return 0;
			}
			look_v++;
		}
		ptr1[i] = ptr[look_v];
		i++;
		look_v++;
	}
	return 1;
}


int main()
{
	int val = 0;
	char *new_ptr = new char[1000];
	fin1.getline(new_ptr, 1000);
	if (check_function_dec_error(new_ptr) == 0)
	{
		cout << "Error in function declaration" << endl;
	}
	while (!fin1.eof())
	{
		look = 0;
		fin1.getline(new_ptr, 1000);
		val = new_chek_type(new_ptr);
		if (val == 1)
		{
			if (check_ret_error(new_ptr) == 0)
			{
				cout << "Error in return" << endl;
			}
		}
		else if (val == 2)
		{
			if (check_condition_error(new_ptr) == 0)
			{
				cout << "Error in condition" << endl;
			}
		}
		else if (val == 3)
		{
			if (check_output_error(new_ptr) == 0)
			{
				cout << "Error in output" << endl;
			}
		}
		else if (val == 4)
		{
			if (check_assign_error(new_ptr) == 0)
			{
				cout << "Error in assigning value" << endl;
			}
		}
		else if (val == 5)
		{
			if (check_input_error(new_ptr) == 0)
			{
				cout << "Error in input" << endl;
			}
		}
		else if (val == 6)
		{
			if (check_comment_error(new_ptr) == 0)
			{
				cout << "Error in comment" << endl;
			}
		}

		else if (val == 7)
		{
			if (check_variable_dec_error(new_ptr) == 0)
			{
				cout << "Error in Variable declaration" << endl;
			}
		}
		else if (val == 8)
		{
			counter_brackets++;
		}
		else if (val == 9)
		{
			counter_brackets--;
		}
	}


	if (counter_brackets != -1)
	{
		cout << "Error in square bracket" << endl;
	}

	//int val_p = 0;
	char *ptr2 = new char[1000];
	fin.getline(ptr2, 1000);
	Function(ptr2);
	while (!fin.eof())
	{
		look = 0;
		fin.getline(ptr2, 1000);
		val = Chek_type(ptr2);
		Functionptr(ptr2, val);
		//cout << val << endl;
	}
	system("pause");
}