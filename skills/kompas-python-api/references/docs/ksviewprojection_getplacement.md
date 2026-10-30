# GetPlacement - Получить интерфейс системы координат отображения модели в окне

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс коллекции проекций отображения модели (Интерфейсы ksViewProjectionCollection, IViewProjectionCollection) ](ksviewprojectioncollection.html) > [Проекции отображения модели в окне (Интерфейсы ksViewProjection, IViewProjection) ](ksviewprojection.html) > [IViewProjection - методы ](ksviewprojection_methods.html) |  Scroll [ [ [ ](ksviewprojection_getviewprojectontype.html "К следующему разделу")](ksviewprojection_methods.html "На уровень выше")](ksviewprojection_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksviewprojection.html)

Синтаксис Automation:

LPDISPATCH GetPlacement();

Синтаксис COM:

LPPLACEMENT GetPlacement();

Возвращаемое значение:

| \- указатель на интерфейс [ksPlacement](ksplacement.html) или [IPlacement](ksplacement.html).  
---|---  
  
Примечание:

Изменение параметров системы координат возможно только для проекции с индексом vp_None.

Подразделы:

(отсутствуют)
