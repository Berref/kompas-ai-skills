# DetachByBody - Удалить указанный объект из массива

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Параметры точки для трехмерных NURBS (Интерфейсы ksNurbsPoint3dCollCollection, INurbsPoint3dCollCollection) ](ksnurbspoint3dcollcollection.html) > [INurbsPoint3dCollCollection - методы ](ksnurbspoint3dcollcollection_methods.html) |  Scroll [ [ [ ](ksnurbspoint3dcollcollection_detachbyindex.html "К следующему разделу")](ksnurbspoint3dcollcollection_methods.html "На уровень выше")](ksnurbspoint3dcollcollection_clear.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbspoint3dcollcollection.html)

Синтаксис Automation:

BOOL DetachByBody (LPDISPATCH obj);

Синтаксис COM:

BOOL DetachByBody (LPNURBSPOINT3DCOLLECTION obj);

Входные параметры:

obj | \- указатель на интерфейс [ksNurbsPoint3dCollection](ksnurbspoint3dcollection.html) или [INurbsPoint3dCollection](ksnurbspoint3dcollection.html) удаляемого объекта.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания:

Указатель на интерфейс удаляемого объекта obj не должен быть равен 0.

Подразделы:

(отсутствуют)
