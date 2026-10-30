# Пример использования функций навигации по объектам

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//позиционирование в текущем виде текущего документа по всем элементам

void Iterator_Example (void)

{

reference itAllObj;

reference obj;

int count = 0;

char buf[128];

//Создать итератор

itAllObj = CreateIterator(ALL_OBJ, 0);

if (itAllObj)

{

if (ExistObj(obj = MoveIterator(itAllObj, 'F')))

{

// поиск первого объекта и следующего в цикле

do

{

LightObj(obj, 1);

count ;

sprintf(buf,"номер = %d", count);

Message(buf);

LightObj(obj, 0);

}

while (ExistObj (obj = MoveIterator (itAllObj, 'N')));

}

}

//Удалить итератор

DeleteIterator(itAllObj);

};
