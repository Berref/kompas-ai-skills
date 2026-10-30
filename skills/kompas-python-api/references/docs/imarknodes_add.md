# Add - Создать узел (добавить узел в коллекцию)

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMarkNodes ](imarknodes.html) > [IMarkNodes - методы ](imarknodes_methods.html) |  Scroll [ [ [ ](imarknodes_clear.html "К следующему разделу")](imarknodes_methods.html "На уровень выше")](imarknodes_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imarknodes.html)

Синтаксис Automation:

LPDISPATH Add( ksMarkNodeEnum Type,

VARIANT Index );

Синтаксис COM:

HRESULT Add( ksMarkNodeEnum Type,

VARIANT Index, IMarkNode** Result);

Входные параметры:

Type | \- тип марки из перечисления [ksMarkNodeEnum,](ksmarknodeenum.html)  
---|---  
Index | \- индекс узла для вставки марки. Поддерживаются следующие типы: VT_I4 - добавление узла по индексу, -1 - добавление в конец списка, VT_BSTR - добавление узла перед элементом с заданным именем, VT_DISPATCH - добавление узла перед заданным.  
  
Возвращаемое значение:

| \- Указатель на интерфейс узла [IMarkNode](imarknode.html).  
---|---  
  
Примечание:

Метод позволяет создать дополнительные узлы для марок.

Подразделы:

(отсутствуют)
