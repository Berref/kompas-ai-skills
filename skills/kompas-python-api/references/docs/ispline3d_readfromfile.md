# ReadFromFile - Прочитать параметры вершин из текстового файла

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISpline3D ](ispline3d.html) > [ISpline3D - методы ](ispline3d_methods.html) |  Scroll [ [ [ ](ispline3d_setcenterpoint.html "К следующему разделу")](ispline3d_methods.html "На уровень выше")](ispline3d_invertvector.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispline3d.html)

Синтаксис Automation:

BOOL ReadFromFile( BSTR fileName );

Синтаксис COM:

HRESULT ReadFromFile( [in] BSTR fileName,

[out, retval] VARIANT_BOOL * Result);

Входные параметры:

fileName | \- имя файла.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание.

См. также [ISpline3D::WriteToFile](ispline3d_writetofile.html).

Подразделы:

(отсутствуют)
