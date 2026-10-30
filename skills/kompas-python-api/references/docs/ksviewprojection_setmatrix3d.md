# SetMatrix3D - Установить систему координат отображения модели в окне по матрице

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс коллекции проекций отображения модели (Интерфейсы ksViewProjectionCollection, IViewProjectionCollection) ](ksviewprojectioncollection.html) > [Проекции отображения модели в окне (Интерфейсы ksViewProjection, IViewProjection) ](ksviewprojection.html) > [IViewProjection - методы ](ksviewprojection_methods.html) |  Scroll [ [ [ ](ksviewprojection_setplacement.html "К следующему разделу")](ksviewprojection_methods.html "На уровень выше")](ksviewprojection_setcurrent.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksviewprojection.html)

Синтаксис Automation:

VARIANT_BOOL SetMatrix3D (VARIANT Matrix3D);

Синтаксис COM:

BOOL SetMatrix3D (VARIANT Matrix3D);

Входные параметры:

Динамический массив SAFEARRAY double (VT_ARRAY | VT_R8). В массиве должны лежать 16 элементов, которые представляют собой матрицу размера 4х4.  
---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Для отображения данной проекции в модели надо после установки системы координат вызвать метод [SetCurrent](ksviewprojection_setcurrent.html).

2\. Матрицу можно получить у ассоциативного вида методом [ksDocument2D::ksAssociationViewMatrix3D](ksdocument2d_ksassociationviewmatrix3d.html).

Подразделы:

(отсутствуют)
