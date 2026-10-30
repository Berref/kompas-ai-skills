# Cell - Значение в ячейке таблицы переменных

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Переменные ](ba1859837.html) > [Интерфейс IVariableTable ](ivariabletable.html) > [IVariableTable - свойства ](ivariabletable_props.html) |  Scroll [ [ [ ](ivariabletable_columnscount.html "К следующему разделу")](ivariabletable_props.html "На уровень выше")](ivariabletable_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ivariabletable.html)

Тип данных: double.

Синтаксис Automation:

Cell = iObject.Cell (rIndex,cIndex) | Получить свойство ([* ](1.html))  
---|---  
iObject.Cell (rIndex,cIndex) = Cell | Установить свойство ([* ](1.html))  
Cell = iObject.GetCell (rIndex,cIndex) | Получить свойство ([**](2.html))  
iObject.SetCell (rIndex,cIndex,Cell) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Cell(rIndex,cIndex,&Cell) | Получить свойство  
---|---  
iObject->put_Cell (rIndex,cIndex,Cell) | Установить свойство  
  
Входные параметры:

long rIndex | \- индекс строки таблицы переменных,  
---|---  
long cIndex | \- индекс колонки таблицы переменных.  
  
Примечание:

Установка свойства доступна только для верхнего компонента.

Подразделы:

(отсутствуют)
