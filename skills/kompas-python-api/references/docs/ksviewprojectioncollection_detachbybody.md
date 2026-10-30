# DetachByBody - Отсоединить элемент по указателю на интерфейс

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс коллекции проекций отображения модели (Интерфейсы ksViewProjectionCollection, IViewProjectionCollection) ](ksviewprojectioncollection.html) > [IViewProjectionCollection - методы ](ksviewprojectioncollection_methods.html) |  Scroll [ [ [ ](ksviewprojectioncollection_detachbyindex.html "К следующему разделу")](ksviewprojectioncollection_methods.html "На уровень выше")](ksviewprojectioncollection_addunfoldprojection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksviewprojectioncollection.html)

Синтаксис Automation:

BOOL DetachByBody (LPDISPATCH projection);

Синтаксис COM:

BOOL DetachByBody (LPVIEWPROJECTION projection);

Входные параметры:

projection | \- указатель на интерфейс [ksViewProjection](ksviewprojection.html) или [IViewProjection](ksviewprojection.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Отсоединить можно только пользовательскую проекцию, стандартные проекции не отсоединяются.

Подразделы:

(отсутствуют)
