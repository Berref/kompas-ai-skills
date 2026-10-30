# DetachByName - Отсоединить элемент по имени проекции

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс коллекции проекций отображения модели (Интерфейсы ksViewProjectionCollection, IViewProjectionCollection) ](ksviewprojectioncollection.html) > [IViewProjectionCollection - методы ](ksviewprojectioncollection_methods.html) |  Scroll [ [ [ ](ksviewprojectioncollection_findit.html "К следующему разделу")](ksviewprojectioncollection_methods.html "На уровень выше")](ksviewprojectioncollection_detachbyindex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksviewprojectioncollection.html)

Синтаксис Automation:

BOOL DetachByName (BSTR name);

Синтаксис COM:

BOOL DetachByName (LPOLESTR name);

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Отсоединить можно только пользовательскую проекцию, стандартные проекции не отсоединяются.

Подразделы:

(отсутствуют)
