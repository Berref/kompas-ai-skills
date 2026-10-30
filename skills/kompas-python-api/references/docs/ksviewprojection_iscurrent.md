# IsCurrent - Определить, является ли данная проекция текущей

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс коллекции проекций отображения модели (Интерфейсы ksViewProjectionCollection, IViewProjectionCollection) ](ksviewprojectioncollection.html) > [Проекции отображения модели в окне (Интерфейсы ksViewProjection, IViewProjection) ](ksviewprojection.html) > [IViewProjection - методы ](ksviewprojection_methods.html) |  Scroll [ [ [ ](ksviewprojection_setcurrent.html "К следующему разделу")](ksviewprojection_methods.html "На уровень выше")](ksviewprojection_getviewprojectontype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksviewprojection.html)

Синтаксис Automation:

BOOL IsCurrent();

Синтаксис COM:

BOOL IsCurrent();

Возвращаемое значение:

TRUE | \- данная проекция является текущей,  
---|---  
FALSE | \- данная проекция не является текущей.  
  
Примечание:

Для проекции с индексом vp_None возвращаемое значение всегда FALSE.

Подразделы:

(отсутствуют)
