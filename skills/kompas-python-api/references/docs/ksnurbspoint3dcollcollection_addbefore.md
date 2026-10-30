# AddBefore - Добавить объект перед указанным объектом в массиве

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Параметры точки для трехмерных NURBS (Интерфейсы ksNurbsPoint3dCollCollection, INurbsPoint3dCollCollection) ](ksnurbspoint3dcollcollection.html) > [INurbsPoint3dCollCollection - методы ](ksnurbspoint3dcollcollection_methods.html) |  Scroll [ [ [ ](ksnurbspoint3dcollcollection_clear.html "К следующему разделу")](ksnurbspoint3dcollcollection_methods.html "На уровень выше")](ksnurbspoint3dcollcollection_addat.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbspoint3dcollcollection.html)

Синтаксис Automation:

BOOL AddBefore (LPDISPATCH obj, LPDISPATCH base);

Синтаксис COM:

BOOL AddBefore (LPNURBSPOINT3DCOLLECTION obj, LPNURBSPOINT3DCOLLECTION base);

Входные параметры:

obj | \- указатель на интерфейс [ksNurbsPoint3dCollection](ksnurbspoint3dcollection.html) или [INurbsPoint3dCollection](ksnurbspoint3dcollection.html) добавляемого объекта,  
---|---  
base | \- указатель на интерфейс [ksNurbsPoint3dCollection ](ksnurbspoint3dcollection.html)или [INurbsPoint3dCollection](ksnurbspoint3dcollection.html) базового объекта.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Указатели на интерфейсы добавляемого и базового объекта obj и base не должны быть равны 0.

Подразделы:

(отсутствуют)
