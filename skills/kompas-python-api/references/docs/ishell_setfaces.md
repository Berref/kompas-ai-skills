# SetFaces - Установить массив граней в виде SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IShell ](ishell.html) > [IShell - методы ](ishell_methods.html) |  Scroll [ [ [ ](isplitsolids.html "К следующему разделу")](ishell_methods.html "На уровень выше")](ishell_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ishell.html)

Синтаксис Automation:

BOOL SetFaces( VARIANT Faces, BOOL TangentFaces );

Синтаксис COM :

HRESULT SetFaces( VARIANT Faces, BOOL TangentFaces, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Faces | \- Список SafeArray граней,  
---|---  
TangentFaces | \- Добавлять касательные грани.  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
