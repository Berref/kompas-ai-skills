# FindIt - Получить индекс элемента в массиве

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Параметры точки для трехмерных NURBS (Интерфейсы ksNurbsPoint3dCollCollection, INurbsPoint3dCollCollection) ](ksnurbspoint3dcollcollection.html) > [INurbsPoint3dCollCollection - методы ](ksnurbspoint3dcollcollection_methods.html) |  Scroll [ [ [ ](ksnurbspoint3dcollcollection_first.html "К следующему разделу")](ksnurbspoint3dcollcollection_methods.html "На уровень выше")](ksnurbspoint3dcollcollection_detachbyindex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbspoint3dcollcollection.html)

Синтаксис Automation:

long FindIt (LPDISPATCH entity);

Возвращаемое значение:

индекс элемента | \- если элемент найден в массиве,  
---|---  
-1 | \- если элемент не найден.  
  
Синтаксис COM:

unsigned long FindIt (LPNURBSPOINT3DCOLLECTION entity);

Возвращаемое значение:

индекс элемента | \- если элемент найден в массиве,  
---|---  
SYS_MAX_UINT | \- если элемент не найден.  
  
Входные параметры:

entity | \- указатель на интерфейс компонента [ksNurbsPoint3dCollection](ksnurbspoint3dcollection.html) или [INurbsPoint3dCollection](ksnurbspoint3dcollection.html).  
---|---  
  
Подразделы:

(отсутствуют)
