# DetachByIndex - Удалить объект из массива по индексу

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Параметры точки для трехмерных NURBS (Интерфейсы ksNurbsPoint3dCollCollection, INurbsPoint3dCollCollection) ](ksnurbspoint3dcollcollection.html) > [Массив узлов для трехмерных NURBS - поверхностей (Интерфейсы ksNurbsKnotCollection, INurbsKnotCollection) ](ksnurbsknotcollection.html) > [INurbsKnotCollection - методы ](ksnurbsknotcollection_methods.html) |  Scroll [ [ [ ](ksnurbsknotcollection_first.html "К следующему разделу")](ksnurbsknotcollection_methods.html "На уровень выше")](ksnurbsknotcollection_detachbybody.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbsknotcollection.html)

Синтаксис Automation:

BOOL DetachByIndex (long index);

Синтаксис COM:

BOOL DetachByIndex (long index);

Входной параметр:

index | \- индекс удаляемого объекта в массиве.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Элемент массива из модели не удаляется.

Подразделы:

(отсутствуют)
