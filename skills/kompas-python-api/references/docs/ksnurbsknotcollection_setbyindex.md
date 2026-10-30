# SetByIndex - Заменить объект с указанным индексом в массиве на присланный объект

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Параметры точки для трехмерных NURBS (Интерфейсы ksNurbsPoint3dCollCollection, INurbsPoint3dCollCollection) ](ksnurbspoint3dcollcollection.html) > [Массив узлов для трехмерных NURBS - поверхностей (Интерфейсы ksNurbsKnotCollection, INurbsKnotCollection) ](ksnurbsknotcollection.html) > [INurbsKnotCollection - методы ](ksnurbsknotcollection_methods.html) |  Scroll [ [ [ ](ksnurbspoint3dparam.html "К следующему разделу")](ksnurbsknotcollection_methods.html "На уровень выше")](ksnurbsknotcollection_refresh.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbsknotcollection.html)

Синтаксис Automation:

BOOL SetByIndex (double obj, long index);

Синтаксис COM:

BOOL SetByIndex (double obj, long index);

Входные параметры:

obj | \- значение присоединяемого узла,  
---|---  
index | \- индекс элемента в массиве.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
