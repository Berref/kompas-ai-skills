# SetMatrix3D - Установить систему координат отображения модели в окне по матрице и масштабу

[API интерфейсов. Версия 7](applicate.html) > [Управление изображением модели](view_managment.html) > [Интерфейс IViewProjectionManager](iviewprojectionmanager.html) > [IViewProjectionManager - методы](iviewprojectionmanager_methods.html) |  Scroll [ [ [ ](iviewprojection7.html "К следующему разделу")](iviewprojectionmanager_methods.html "На уровень выше")](iviewprojectionmanager_orientationnormaltoandaling.html "К предыдущему разделу")  
---|---  
  
[Интерфейс](iviewprojectionmanager.html)

Синтаксис Automation:

BOOL SetMatrix3D( VARIANT Matrix3D, double Scale );

Синтаксис COM:

HRESULT SetMatrix3D( VARIANT Matrix3D, double Scale, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Matrix3D | \- динамический массив SAFEARRAY double (VT_ARRAY | VT_R8),  
---|---  
Scale | \- масштаб.  
  
Примечания:

В массиве должны лежать 16 элементов, которые представляют собой матрицу размера 4х4.

Подразделы:

(отсутствуют)
