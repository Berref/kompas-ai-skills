# SetStartingOrientation - Установить исходное положение ЛСК

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [Наследники - вспомогательные объекты ](bc2284488.html) > [Интерфейс ILocalCoordinateSystem ](ilocalcoordinatesystem.html) > [ILocalCoordinateSystem - методы ](ilocalcoordinatesystem_methods.html) |  Scroll [ [ [ ](ilocalcoordinatesystem_update.html "К следующему разделу")](ilocalcoordinatesystem_methods.html "На уровень выше")](ilocalcoordinatesystem_setdisplacementbyaxis.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcoordinatesystem.html)

Синтаксис Automation:

BOOL SetStartingOrientation();

Синтаксис COM:

HRESULT SetStartingOrientation([out, retval] VARIANT_BOOL* Result);

Возвращаемое значение:

TRUE | \- в случае успеха;  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Позволяет установить ЛСК в положение, соответствующее матрице векторов:

Ось | X | Y | Z  
---|---|---|---  
Ось X | 1 | 0 | 0  
Ось Y | 0 | 1 | 0  
Ось Z | 0 | 0 | 1  
  
Подразделы:

(отсутствуют)
