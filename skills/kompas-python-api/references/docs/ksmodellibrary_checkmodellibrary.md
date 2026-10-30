# CheckModelLibrary - Проверить, открыта ли указанная библиотека моделей

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с библиотеками ](ck1750127.html) > [Библиотека моделей (Интерфейсы ksModelLibrary и IModelLibrary ) ](ksmodellibrary.html) > [ksModelLibrary - методы ](ksmodellibrary_methods.html) |  Scroll [ [ [ ](ksmodellibrary_choicemodelfromlib.html "К следующему разделу")](ksmodellibrary_methods.html "На уровень выше")](ksmodellibrary_addd3documenttolibrary.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](ksmodellibrary.html)

Синтаксис Automation:

long CheckModelLibrary (BSTR libName,

BOOL possibleMessage);

Синтаксис COM:

long CheckModelLibrary (LPOLESTR libName,

BOOL possibleMessage);

Входные параметры:

libName | \- имя файла библиотеки моделей,  
---|---  
possibleMessage | \- признак, показывающий, нужно ли выдать сообщение об открытии библиотеки: TRUE - сообщение выдается, FALSE - сообщение не выдается.  
  
Возвращаемое значение:

1 | \- библиотека открыта (успешное завершение),  
---|---  
0 | \- библиотека закрыта.  
  
Подразделы:

(отсутствуют)
