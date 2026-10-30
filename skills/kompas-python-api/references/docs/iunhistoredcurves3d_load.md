# Load - Прочитать кривые из файла

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IUnhistoredCurves3D ](iunhistoredcurves3d.html) > [IUnhistoredCurves3D - методы ](iunhistoredcurves3d_methods.html) |  Scroll [ [ [ ](iuserfolders.html "К следующему разделу")](iunhistoredcurves3d_methods.html "На уровень выше")](iunhistoredcurves3d_convert.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iunhistoredcurves3d.html)

Синтаксис Automation:

VARIANT Load( BSTR FileName, BOOL SewCurves );

Синтаксис COM:

HRESULT Load( BSTR FileName, BOOL SewCurves, VARIANT * Result );

Возвращаемое значение:

| \- массив указателей на кривые VT_ARRAY | VT_DISPATCH.  
---|---  
  
Входные параметры:

FileName | \- имя файла,  
---|---  
SewCurves | \- сшивать кривые.  
  
Подразделы:

(отсутствуют)
