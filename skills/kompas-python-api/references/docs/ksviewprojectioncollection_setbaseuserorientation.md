# SetBaseUserOrientation - Установить пользовательскую базовую ориентацию модели

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс коллекции проекций отображения модели (Интерфейсы ksViewProjectionCollection, IViewProjectionCollection) ](ksviewprojectioncollection.html) > [IViewProjectionCollection - методы ](ksviewprojectioncollection_methods.html) |  Scroll [ [ [ ](ksviewprojection.html "К следующему разделу")](ksviewprojectioncollection_methods.html "На уровень выше")](ksviewprojectioncollection_refresh.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksviewprojectioncollection.html)

Синтаксис Automation:

BOOL SetBaseUserOrientation(VARIANT place);

Синтаксис COM:

BOOL SetBaseUserOrientation(VARIANT * place);

Входные параметры:

place | \- массив SafeAttray типа (VT_ARRAY | VT_R8).  
---|---  
  
Примечание:

1\. Элементы матрицы возвращаются в виде одномерного массива из 16 элементов. Матрица имеет размер 4х4.

2\. Метод позволяет получить матрицу, которая может использоваться для отображения вида спереди.

3\. По умолчанию используется единичная матрица без смещения.

Подразделы:

(отсутствуют)
