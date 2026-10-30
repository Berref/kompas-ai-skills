# AddAt - Добавить объект с заданным индексом в массив

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Параметры точки для трехмерных NURBS (Интерфейсы ksNurbsPoint3dCollCollection, INurbsPoint3dCollCollection) ](ksnurbspoint3dcollcollection.html) > [INurbsPoint3dCollCollection - методы ](ksnurbspoint3dcollcollection_methods.html) |  Scroll [ [ [ ](ksnurbspoint3dcollcollection_addbefore.html "К следующему разделу")](ksnurbspoint3dcollcollection_methods.html "На уровень выше")](ksnurbspoint3dcollcollection_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbspoint3dcollcollection.html)

Синтаксис Automation:

BOOL AddAt (LPDISPATCH obj, long index);

Синтаксис COM:

BOOL AddAt (LPNURBSPOINT3DCOLLECTION obj, long index);

Входные параметры:

obj | \- указатель на интерфейс [ksNurbsPoint3dCollection](ksnurbspoint3dcollection.html) или [INurbsPoint3dCollection](ksnurbspoint3dcollection.html) параметров точки для трехмерной NURBS,  
---|---  
index | \- индекс в массиве.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Указатель на интерфейс добавляемого объекта obj не должен быть равен 0.

Подразделы:

(отсутствуют)
