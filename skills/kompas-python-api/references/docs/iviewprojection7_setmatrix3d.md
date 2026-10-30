# SetMatrix3D - Установить систему координат отображения модели в окне по матрице

[API интерфейсов. Версия 7](applicate.html) > [Управление изображением модели](view_managment.html) > [Интерфейс IViewProjection7 ](iviewprojection7.html) > [IViewProjection7 - методы](iviewprojection7_methods.html) |  Scroll [ [ [ ](iviewprojection7_update.html "К следующему разделу")](iviewprojection7_methods.html "На уровень выше")](iviewprojection7_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс](iviewprojection7.html)

Синтаксис Automation:

BOOL SetMatrix3D( VARIANT Matrix3D );

Синтаксис COM:

HRESULT SetMatrix3D( VARIANT Matrix3D, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Matrix3D | \- Матрица. Динамический массив SAFEARRAY double (VT_ARRAY | VT_R8),  
---|---  
  
Примечания:

Элементы матрицы возвращаются в виде одномерного массива из 16 элементов SafeAttray типа (VT_ARRAY | VT_R8).

Матрица имеет размер 4х4.

Подразделы:.

(отсутствуют)
