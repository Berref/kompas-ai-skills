# ViewEditAttrType - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void ViewEditAttrType_Example (void) {

//выбираем библиотеку типов, задаем номер, пароль типа и редактируем тип

char nameFile[128];

char password[10];

int j;

if(!ChoiceFile("*.tip", nameFile))

nameFile[0]='\0'; //будем искать в документе

double numb;

j = ReadDouble("номер типа атрибута", 1000.,0, 1e12,&numb);

if (j) {

j = ReadString("пароль типа атрибута", password, 10);

if (j) {

//отредактировать атрибут с уникальным номером numb

ViewEditAttrType (nameFile, 2, numb, password);

}

}

}; /* ViewEditAttrType */
