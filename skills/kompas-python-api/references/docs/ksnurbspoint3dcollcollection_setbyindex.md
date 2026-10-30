# SetByIndex - Заменить объект с указанным индексом в массиве на присланный объект

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Параметры точки для трехмерных NURBS (Интерфейсы ksNurbsPoint3dCollCollection, INurbsPoint3dCollCollection) ](ksnurbspoint3dcollcollection.html) > [INurbsPoint3dCollCollection - методы ](ksnurbspoint3dcollcollection_methods.html) |  Scroll [ [ [ ](ksnurbsknotcollection.html "К следующему разделу")](ksnurbspoint3dcollcollection_methods.html "На уровень выше")](ksnurbspoint3dcollcollection_refresh.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbspoint3dcollcollection.html)

Синтаксис Automation:

BOOL SetByIndex (LPDISPATCH obj, long index );

Синтаксис COM:

BOOL SetByIndex (LPNURBSPOINT3DCOLLECTION obj, long index);

Входные параметры:

obj | \- указатель на интерфейс [ksINurbsPoint3dCollection](ksnurbspoint3dcollection.html) или [INurbsPoint3dCollection](ksnurbspoint3dcollection.html) присоединяемого объекта,  
---|---  
index | \- индекс элемента в массиве.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
