# IsSuitableObject - Проверка пригодности объекта для операции

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ICopyGeometry ](icopygeometry.html) > [ICopyGeometry - методы ](icopygeometry_methods.html) |  Scroll [ [ [ ](icopygeometry_opendocument.html "К следующему разделу")](icopygeometry_methods.html "На уровень выше")](icopygeometry_isinitialobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icopygeometry.html)

Синтаксис Automation:

BOOL IsSuitableObject( IModelObject * Object );

Синтаксис COM:

HRESULT IsSuitableObject( IModelObject * Object, BOOL * Result );

Возвращаемое значение:

TRUE | \- объект пригоден,  
---|---  
FALSE | \- объект не пригоден.  
  
Входные параметры:

Object | \- указатель на объект.  
---|---  
  
Подразделы:

(отсутствуют)
