# ReadFromFile - Прочитать файл с данными

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [Наследники - вспомогательные объекты ](bc2284488.html) > [Интерфейс ILocalCoordinateSystem ](ilocalcoordinatesystem.html) > [ILocalCoordinateSystem - методы ](ilocalcoordinatesystem_methods.html) |  Scroll [ [ [ ](ilocalcoordinatesystem_setassociationobject.html "К следующему разделу")](ilocalcoordinatesystem_methods.html "На уровень выше")](ilocalcoordinatesystem_initbymatrix3d.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcoordinatesystem.html)

Синтаксис Automation:

BOOL ReadFromFile( BSTR fileName );

Синтаксис COM:

HRESULT ReadFromFile( [in] BSTR fileName,

[out, retval] VARIANT_BOOL* Result);

Входные данные:

fileName | \- полное имя файла.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха;  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Позволяет установить направление осей ЛСК в соответствии со значениями в текстовом файле. Файл должен быть записан с помощью метода [ILocalCoordinateSystem::WriteToFile](ilocalcoordinatesystem_writetofile.html).

Подразделы:

(отсутствуют)
