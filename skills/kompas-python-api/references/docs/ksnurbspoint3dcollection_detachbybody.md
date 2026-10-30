# DetachByBody - Удалить указанный объект из массива

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая кривая в трехмерном пространстве (Интерфейсы ksCurve3D, ICurve3D) ](kscurve3d.html) > [Параметры трехмерных NURBS (Интерфейсы ksNurbs3dParam,INurbs3dParam) ](ksnurbs3dparam.html) > [Массив точек для трехмерных NURBS (Интерфейсы ksNurbsPoint3dCollection, INurbsPoint3dCollection) ](ksnurbspoint3dcollection.html) > [INurbsPoint3dCollection - методы ](ksnurbspoint3dcollection_methods.html) |  Scroll [ [ [ ](ksnurbspoint3dcollection_detachbyindex.html "К следующему разделу")](ksnurbspoint3dcollection_methods.html "На уровень выше")](ksnurbspoint3dcollection_clear.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbspoint3dcollection.html)

Синтаксис Automation:

BOOL DetachByBody (LPDISPATCH obj);

Синтаксис COM:

BOOL DetachByBody (LPNURBSPOINT3DPARAM obj);

Входные параметры:

obj | \- указатель на интерфейс [ksNurbsPoint3dParam](ksnurbspoint3dparam.html) или [INurbsPoint3dParam](ksnurbspoint3dparam.html) удаляемого объекта.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания:

Указатель на интерфейс удаляемого объекта obj не должен быть равен 0.

Подразделы:

(отсутствуют)
