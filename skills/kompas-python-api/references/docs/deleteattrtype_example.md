# DeleteAttrType - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void DeleteAttrType_Example (void)

{

double numb;

int j;

char nameFile[128];

char password[11];

//запросить имя библиотеки

if (!ChoiceFile("tip", NULL, nameFile, 128))

nameFile[0]='\0'; //будем искать в документе

do

{

j = ReadDouble (" номер типа атрибута", 1000.,0, 1e12,&numb);

if (j)

{

j = ReadString (" пароль типа атрибута", password, 10);

if (j)

{

if (!DeleteAttrType (numb, nameFile, password))

MessageBoxResult(); // проверяем результат работы функции

}

}

}

while (j);

};
