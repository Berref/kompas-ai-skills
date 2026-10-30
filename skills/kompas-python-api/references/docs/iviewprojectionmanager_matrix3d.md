# Matrix3D - Текущая матрица отображения в окне документа

[API интерфейсов. Версия 7](applicate.html) > [Управление изображением модели](view_managment.html) > [Интерфейс IViewProjectionManager](iviewprojectionmanager.html) > [IViewProjectionManager - свойства](iviewprojectionmanager_propers.html) |  Scroll [ [ [ ](iviewprojectionmanager_scale.html "К следующему разделу")](iviewprojectionmanager_propers.html "На уровень выше")](iviewprojectionmanager_count.html "К предыдущему разделу")  
---|---  
  
[Интерфейс](iviewprojectionmanager.html)

Тип данных:VARIANT

Синтаксис Automation:

Matrix3D = Object.Matrix3D | Получить свойство ([* ](1.html))  
---|---  
Matrix3D = Object.GetMatrix3D() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Matrix3D( &Matrix3D ) | Получить свойство  
---|---  
  
Примечание:

1.Свойство доступно только для чтения.

2.Для изменения текущей ориентации используется метод [IViewProjection7_SetMatrix3D](iviewprojection7_setmatrix3d.html).

3.Элементы матрицы возвращаются в виде одномерного массива из 16 элементов SafeAttray типа (VT_ARRAY | VT_R8). Матрица имеет размер 4х4.

Подразделы:

(отсутствуют)
