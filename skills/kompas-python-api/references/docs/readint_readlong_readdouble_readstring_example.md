# Пример использования функций ввода параметров

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void MessageEsc(void) {

Message(Отказ от ввода);

}

void Read_Example (void) {

int I; long l; double r;

char s[80], buf[80];

if (ReadInt(Ввод целого числа, 5, 0, 999, &i)) {

sprintf(buf, Результат= %4d, i);

Message(buf);

}

else MessageEsc();

if (ReadLong(Ввод длинного целого, 77, 0, 999, &l)) {

sprintf(buf, Результат= %4d, I);

Message(buf);

}

else MessageEsc();

if (ReadDouble(Ввод действительного числа, 5, 0, 999, &r)) {

sprintf(buf, Результат= %5.1f, r);

Message(buf);

}

else MessageEsc();

if (ReadString(Ввод строки, s))

Message(s);

else MessageEsc();

}; /* Read_Example */
