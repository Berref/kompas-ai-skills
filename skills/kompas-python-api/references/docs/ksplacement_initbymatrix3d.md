# InitByMatrix3D - Установить систему координат по матрице

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [Положение объекта (Интерфейсы ksPlacement, IPlacement) ](ksplacement.html) > [IPlacement - методы ](ksplacement_methods.html) |  Scroll [ [ [ ](ksplacement_pointprojection.html "К следующему разделу")](ksplacement_methods.html "На уровень выше")](ksplacement_getvector.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplacement.html)

Синтаксис Automation:

BOOL InitByMatrix3D( VARIANT * mtr );

Синтаксис COM:

BOOL InitByMatrix3D( VARIANT * mtr );

Входные параметры:

mtr | \- массив SafeAttray типа (VT_ARRAY | VT_R8).  
---|---  
  
Примечание:

1\. Элементы матрицы возвращаются в виде одномерного массива из 16 элементов.

2\. Матрица имеет размер 4х4.

Подразделы:

(отсутствуют)
