# SetAssociationObject - Установить опорный объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [Наследники - вспомогательные объекты ](bc2284488.html) > [Интерфейс ILocalCoordinateSystem ](ilocalcoordinatesystem.html) > [ILocalCoordinateSystem - методы ](ilocalcoordinatesystem_methods.html) |  Scroll [ [ [ ](ilocalcoordinatesystem_setdisplacementbyaxis.html "К следующему разделу")](ilocalcoordinatesystem_methods.html "На уровень выше")](ilocalcoordinatesystem_readfromfile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcoordinatesystem.html)

Синтаксис Automation:

BOOL SetAssociationObject( IModelObject * NewVal );

Синтаксис COM:

HRESULT SetAssociationObject( IModelObject * NewVal, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успеха;  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

NewVal | \- указатель на опорный объект.  
---|---  
  
Подразделы:

(отсутствуют)
