# SetPTextItem - Установить указатель на интерфейс динамического массива компонент текcта ksDynamicArray типа TEXT_ITEM_ARR

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Обозначение базы (Интерфейс ksBaseParam) ](ksbaseparam.html) > [ksBaseParam - методы ](ksbaseparam_methods.html) |  Scroll [ [ [ ](ch1721808.html "К следующему разделу")](ksbaseparam_methods.html "На уровень выше")](ksbaseparam_init.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbaseparam.html)

Синтаксис Automation:

BOOL SetPTextItem (LPDISPATCH pTextItem);

Входной параметр:

pTextItem | \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html) типа TEXT_ITEM_ARR.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Массив используется при [ksBaseParam::type](ksbaseparam_type.html) = TRUE.

Смотрите также: [TextItemParam](structtextitemparam.html)

Подразделы:

(отсутствуют)
