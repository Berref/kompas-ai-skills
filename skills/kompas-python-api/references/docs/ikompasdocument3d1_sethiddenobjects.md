# SetHiddenObjects - Скрыть/показать объект или объекты

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument3D1 ](ikompasdocument3d1.html) > [IKompasDocument3D1 - методы ](ikompasdocument3d1_methods.html) |  Scroll [ [ [ ](ba1952824.html "К следующему разделу")](ikompasdocument3d1_methods.html "На уровень выше")](ikompasdocument3d1_pickmodelobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d1.html)

Синтаксис Automation:

BOOL SetHiddenObjects( VARIANT Objects, BOOL Visible );

Синтаксис COM:

HRESULT SetHiddenObjects( VARIANT Objects, BOOL Visible, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Objects | \- объект (VT_DISPATCH) или список объектов VT_ARRAY | VT_DISPATCH,  
---|---  
Visible | \- TRUE - Отобразить объект, \- FALSE - Скрыть объект.  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
