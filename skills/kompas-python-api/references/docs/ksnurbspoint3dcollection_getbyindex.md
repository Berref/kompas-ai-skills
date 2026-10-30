# GetByIndex - Получить указатель на интерфейс объекта в массиве по индексу

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая кривая в трехмерном пространстве (Интерфейсы ksCurve3D, ICurve3D) ](kscurve3d.html) > [Параметры трехмерных NURBS (Интерфейсы ksNurbs3dParam,INurbs3dParam) ](ksnurbs3dparam.html) > [Массив точек для трехмерных NURBS (Интерфейсы ksNurbsPoint3dCollection, INurbsPoint3dCollection) ](ksnurbspoint3dcollection.html) > [INurbsPoint3dCollection - методы ](ksnurbspoint3dcollection_methods.html) |  Scroll [ [ [ ](ksnurbspoint3dcollection_getcount.html "К следующему разделу")](ksnurbspoint3dcollection_methods.html "На уровень выше")](ksnurbspoint3dcollection_detachbyindex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbspoint3dcollection.html)

Синтаксис Automation:

LPDISPATCH GetByIndex (long index);

Синтаксис COM:

LPNURBSPOINT3DPARAM GetByIndex (long index);

Входной параметр:

index | \- номер объекта в массиве.  
---|---  
  
Возвращаемое значение:

| указатель на интерфейс [ksNurbsPoint3dParam](ksnurbspoint3dparam.html) или [INurbsPoint3dParam](ksnurbspoint3dparam.html).  
---|---  
  
Подразделы:

(отсутствуют)
