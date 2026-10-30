# ChangeObjectLinks - Заменить ссылки на объекты по всем операциям

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_curveintersection.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_beginedit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation:

BOOL ChangeObjectLinks( VARIANT SourceObjs,

VARIANT DestObjs,

BOOL RebuildAll );

Синтаксис COM:

HRESULT ChangeObjectLinks( VARIANT SourceObjs,

VARIANT DestObjs,

BOOL RebuildAll,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

SourceObjs | \- массив исходных примитивов,  
---|---  
DestObjs | \- массив новых примитивов,  
RebuildAll | \- перестроить объекты.  
  
Метод позволяет заменить ссылки в объектах 3D модели с одних опорных примитивов на другие.

Подразделы:

(отсутствуют)
