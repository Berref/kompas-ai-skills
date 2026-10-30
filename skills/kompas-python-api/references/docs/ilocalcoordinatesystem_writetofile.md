# WriteToFile - Записать файл с данными

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [Наследники - вспомогательные объекты ](bc2284488.html) > [Интерфейс ILocalCoordinateSystem ](ilocalcoordinatesystem.html) > [ILocalCoordinateSystem - методы ](ilocalcoordinatesystem_methods.html) |  Scroll [ [ [ ](ipoint3dparambetweenpoints.html "К следующему разделу")](ilocalcoordinatesystem_methods.html "На уровень выше")](ilocalcoordinatesystem_update.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcoordinatesystem.html)

Синтаксис Automation:

BOOL WriteToFile( BSTR fileName );

Синтаксис COM:

HRESULT WriteToFile( [in] BSTR fileName,

[out, retval] VARIANT_BOOL* Result);

Входные параметры:

fileName | \- полное имя файла.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха;  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Позволяет записать значения векторов направлений осей ЛСК в текстовый файл.

Подразделы:

(отсутствуют)
