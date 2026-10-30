# DeletePoint - Удалить узел

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IBezier ](ibezier.html) > [IBezier - методы ](ibezier_methods.html) |  Scroll [ [ [ ](ibezier_getpoint.html "К следующему разделу")](ibezier_methods.html "На уровень выше")](ibezier_clear.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ibezier.html)

Синтаксис Automation:

BOOL DeletePoint( long Index );

Синтаксис COM:

HRESULT DeletePoint( long Index, BOOL * Result );

Входные параметры:

Index | \- индекс удаляемого узла.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет удалить заданный узел кривой.

Подразделы:

(отсутствуют)
