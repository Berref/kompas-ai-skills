# CreateAttrIterator - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
double x, y;

reference pObj;

char password[11];

int j;

RequestInfo info;

memset (&info, 0, sizeof(info));

info.prompt = "Укажите объект";

do

{

j = Cursor (&info, &x, &y, 0);

if (j)

{

if (ExistObj(pObj = FindObj (x, y, 1e6)))

{

LightObj (pObj, 1);

//создадим итератор для хождения по атрибутам объекта

reference iter = CreateAttrIterator (pObj, 0,0,0,0,0);

//встали на первый атрибут

reference attr = MoveAttrIterator (iter, 'F', 0);

if (attr)

{

j = ReadString ("Ввести пароль типа атрибута", password, 10);

if (j)

{

//удалить атрибут

if (!DeleteAttr (pObj, attr, password))

MessageBoxResult(); // неудачное завершение -

// выдадим результат работы

// нашей функции

}

}

else

Message("атрибут не найден");

LightObj (pObj, 0);

}

}

}

while (j);
