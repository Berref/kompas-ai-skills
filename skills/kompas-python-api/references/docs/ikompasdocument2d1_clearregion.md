# ClearRegion - Очистить область

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_clearundo.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_changeobjectsorder.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

BOOL ClearRegion( IDrawingGroup * ClearGroup, IDrawingGroup * RegionGroup, BOOL Inside );

Синтаксис COM:

HRESULT ClearRegion( IDrawingGroup * ClearGroup, IDrawingGroup * RegionGroup, BOOL Inside, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

ClearGroup | \- группа геометрии, которую нужно очистить (0 - просматривать все объекты текущего вида),  
---|---  
RegionGroup | \- группа объектов, задающая область очистки,  
Inside | \- признак расположения удаляемых объектов: TRUE - внутри области, FALSE - снаружи области, ограниченной grRegion.  
  
Версия Компас v23

Подразделы:

(отсутствуют)
