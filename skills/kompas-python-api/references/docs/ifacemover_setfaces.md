# SetFaces - Установить массив граней в виде SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IFaceMover ](ifacemover.html) > [IFaceMover - методы ](ifacemover_methods.html) |  Scroll [ [ [ ](icoupling.html "К следующему разделу")](ifacemover_methods.html "На уровень выше")](ifacemover_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifacemover.html)

Синтаксис Automation:

BOOL SetFaces( VARIANT Faces, BOOL TangentFaces );

Синтаксис COM :

HRESULT SetFaces( VARIANT Faces, BOOL TangentFaces, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Faces | \- список SafeArray граней,  
---|---  
TangentFaces | \- добавлять касательные грани.  
  
Подразделы:

(отсутствуют)
