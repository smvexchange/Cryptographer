#include <iostream>

int input_operation()
{
	std::cout << "Enter the operation number(1 - encodind, 2 - decoding, 3 - quit): ";
	int operation;
	std::cin >> operation;
	return operation;
}

int input_length()
{
	std::cout << "Enter text length: ";
	int text_length;
	std::cin >> text_length;
	return text_length;
}
char* input_text(int text_length)
{
	std::cout << "Enter the text: ";
	char* text = new char[text_length];
	int index = 0;
	while (index < text_length)
	{
		std::cin >> text[index];
		++index;
	}
	return text;
	delete[] text;
}

int input_offset()
{
	std::cout << "Enter the offset: ";
	int offset;
	std::cin >> offset;
	return offset;
}

char* encoding(char *text, int text_length, int offset)
{
	for (int i = 0; i < text_length; i++) {
		if (text[i] + offset > 122)
		{
			text[i] = 64 + ((text[i] + offset) % 122);
		} 
		else if (text[i] + offset < 65)
		{
			text[i] = 123 - (65 % (text[i] + offset));
		}
		else
		{
			text[i] += offset;
		}
	}
	return text;
}

char* decoding(char* text, int text_length, int offset)
{
	return encoding(text, text_length, offset * -1);
}

void print_text(char* text, int text_length) {
	std::cout << "Converted text: \"";
	for (int i = 0; i < text_length; i++)
	{
		std::cout << text[i];
	}
	std::cout << "\"" << std::endl;
	std::cout << "*******************************************************************" << std::endl;
}

int main()
{
	while (true) {
		int operation;
		operation = input_operation();
		if (operation == 3)
		{	
			break;
		}
		int text_length;
		text_length = input_length();
		char* text = nullptr;
		text = input_text(text_length);
		int offset;
		offset = input_offset();
		if (operation == 1)
		{
			encoding(text, text_length, offset);
		}
		else if (operation == 2)
		{
			decoding(text, text_length, offset);
		}
		print_text(text, text_length);
	}
}