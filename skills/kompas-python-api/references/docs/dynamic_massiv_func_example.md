# Пример использования функций работы с динамическими массивами

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
struct User_Data // определение структуры пользовательского массива

{

int I;

char *c;

float f;

};

//функция удаляет элемент User_Data пользовательского массива

void WINAPI DelUserFunc (void *val)

{

User_Data *tmp = (User_Data *)val;

Message(tmp->c);

delete [] tmp->c;

delete tmp;

}

//функция добавляет элемент User_Data в пользовательский массив

int CreateUserItem (reference arr, int i, char *c, float f)

{

User_Data* tmp = new User_Data;

tmp->i = I;

tmp->c = new char [strlen(c) +1];

strcpy (tmp->c, c);

tmp->f = f;

return AddArrayItem (arr, -1, tmp, 0);

}

//функция выдает содержимое элемента User_Data

void ShowUserItem (User_Data & tmp)

{

char buf[128];

sprintf (buf, " i=%d f=%f\n c=%s ", tmp.i, tmp.f, tmp.c);

Message (buf);

}

void Array_Example (void)

{

User_Data *tmp;

//создадим пользовательский массив неопределенной длины

reference userArr = CreateArray (USER_ARR, DelUserFunc);

if (!CreateUserItem (userArr, 1, "январь", 31.))

MessageBoxResult();

if (!CreateUserItem (userArr, 2, "февраль", 29.))

MessageBoxResult();

if (!CreateUserItem (userArr, 3, "март", 31.))

MessageBoxResult();

//просмотрим массив

for (int i=0; i< GetArrayCount(userArr); i++)

{

// получим указатель на элемент массива

GetUserArrayItem (userArr, i, &(void*)tmp);

ShowUserItem (*tmp);

}

ClearArray (userArr); //очистить массив

Message ("удаляем массив");

DeleteArray (userArr);

};
