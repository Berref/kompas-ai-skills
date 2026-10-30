# DeletedFaces - Массив удаляемых граней в виде SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IShell ](ishell.html) > [IShell - свойства ](ishell_propers.html) |  Scroll [ [ [ ](ishell_thintype.html "К следующему разделу")](ishell_propers.html "На уровень выше")](ishell_propers.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ishell.html)

Тип данных: VARIANT

Синтаксис Automation:

DeletedFaces = Object.DeletedFaces | Получить свойство ([* ](1.html))  
---|---  
Object.DeletedFaces = DeletedFaces | Установить свойство ([* ](1.html))  
DeletedFaces = Object.GetDeletedFaces() | Получить свойство ([**](2.html))  
Object.SetDeletedFaces( DeletedFaces ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_DeletedFaces( &DeletedFaces ) | Получить свойство  
---|---  
Object.put_DeletedFaces( DeletedFaces ) | Установить свойство  
  
Примечание.

Позволяет получать и устанавливать грань или массив граней, участвующих в операции оболочка.

Массив граней возвращается в виде массива SAFEARRAY граней LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
