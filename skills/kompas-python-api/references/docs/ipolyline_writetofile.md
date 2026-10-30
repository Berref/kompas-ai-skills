# WriteToFile - Записать параметры вершин в текстовый файл

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IPolyLine ](ipolyline.html) > [IPolyLine - методы ](ipolyline_methods.html) |  Scroll [ [ [ ](iprojectioncurve.html "К следующему разделу")](ipolyline_methods.html "На уровень выше")](ipolyline_readfromfile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipolyline.html)

Синтаксис Automation:

BOOL WriteToFile( BSTR fileName );

Синтаксис COM:

HRESULT WriteToFile( [in] BSTR fileName,

[out, retval] VARIANT_BOOL * Result);

Входные параметры:

fileName | \- имя файла.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание.

См. также [IPolyLine::ReadFromFile](ipolyline_readfromfile.html).

Подразделы:

(отсутствуют)
