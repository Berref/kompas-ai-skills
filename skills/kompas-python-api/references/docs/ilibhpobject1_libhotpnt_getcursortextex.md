# LibHotPnt_GetCursorTextEx - Задать текст для отображения рядом с курсором

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Работа с макроэлементами и библиотечными макроэлементами ](cm1919792.html) > [Работа с характерными точками ](cm1878328.html) > [Интерфейс ILibHPObject1 ](ilibhpobject1.html) > [ILibHPObject1 - методы ](ilibhpobject1_methods.html) |  Scroll [ [ [ ](ilibhpobject1_libhotpnt_getmenuex.html "К следующему разделу")](ilibhpobject1_methods.html "На уровень выше")](ilibhpobject1_libhotpnt_getex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibhpobject1.html)

Синтаксис COM:

LPOLESTR LibHotPnt_GetCursorTextEx(int index );

Входной параметр:

index | \- номер характерной точки.  
---|---  
  
Выходной параметр:

text | \- текст для отображения рядом с курсором.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Метод вызывается при попадании мыши в габарит hot point. При помощи метода можно указать текст, который будет выдан рядом с курсором. Текст выдается для UNICODE вместо [ILibHPObject::LibHotPnt_GetCursorText](ilibhpobject_libhotpnt_getcursortext.html).

2\. С присланной строки снимается копия, сама исходная строка не удаляется.

Подразделы:

(отсутствуют)
