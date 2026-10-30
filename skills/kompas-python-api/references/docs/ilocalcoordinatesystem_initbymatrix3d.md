# InitByMatrix3D - Установить систему координат по матрице

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [Наследники - вспомогательные объекты ](bc2284488.html) > [Интерфейс ILocalCoordinateSystem ](ilocalcoordinatesystem.html) > [ILocalCoordinateSystem - методы ](ilocalcoordinatesystem_methods.html) |  Scroll [ [ [ ](ilocalcoordinatesystem_readfromfile.html "К следующему разделу")](ilocalcoordinatesystem_methods.html "На уровень выше")](ilocalcoordinatesystem_getvector.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcoordinatesystem.html)

Синтаксис Automation:

BOOL InitByMatrix3D( VARIANT mtr );

Синтаксис COM:

HRESULT InitByMatrix3D( VARIANT mtr, BOOL * Result );

Входные параметры:

mtr | \- массив SafeAttray типа (VT_ARRAY | VT_R8).  
---|---  
  
Примечание:

1\. Элементы матрицы возвращаются в виде одномерного массива из 16 элементов.

2\. Матрица имеет размер 4х4.

Подразделы:

(отсутствуют)
