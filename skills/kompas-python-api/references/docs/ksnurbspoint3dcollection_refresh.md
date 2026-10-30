# Refresh - Обновить массив

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая кривая в трехмерном пространстве (Интерфейсы ksCurve3D, ICurve3D) ](kscurve3d.html) > [Параметры трехмерных NURBS (Интерфейсы ksNurbs3dParam,INurbs3dParam) ](ksnurbs3dparam.html) > [Массив точек для трехмерных NURBS (Интерфейсы ksNurbsPoint3dCollection, INurbsPoint3dCollection) ](ksnurbspoint3dcollection.html) > [INurbsPoint3dCollection - методы ](ksnurbspoint3dcollection_methods.html) |  Scroll [ [ [ ](ksnurbspoint3dcollection_setbyindex.html "К следующему разделу")](ksnurbspoint3dcollection_methods.html "На уровень выше")](ksnurbspoint3dcollection_prev.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbspoint3dcollection.html)

Синтаксис Automation:

BOOL Refresh();

Синтаксис COM:

BOOL Refresh();

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

После вызова данной функции возникает полное соответствие массива с массивом точек ребра (поверхности), и удаляются все предыдущие изменения в массиве.

Подразделы:

(отсутствуют)
