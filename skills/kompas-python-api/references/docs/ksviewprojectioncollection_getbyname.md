# GetByName - Получить указатель на элемент массива по имени

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс коллекции проекций отображения модели (Интерфейсы ksViewProjectionCollection, IViewProjectionCollection) ](ksviewprojectioncollection.html) > [IViewProjectionCollection - методы ](ksviewprojectioncollection_methods.html) |  Scroll [ [ [ ](ksviewprojectioncollection_getbaseuserorientation.html "К следующему разделу")](ksviewprojectioncollection_methods.html "На уровень выше")](ksviewprojectioncollection_getbyindex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksviewprojectioncollection.html)

Синтаксис Automation:

LPDISPATCH GetByName (BSTR name, BOOL testFullName, BOOL testIgnoreCase);

Синтаксис COM:

LPVIEWPROJECTION GetByName (LPOLESTR name, BOOL testFullName, BOOL testIgnoreCase);

Входные параметры:

name | \- имя проекции,  
---|---  
testFullName | \- признак полного имени: TRUE - name - полное имя, FALSE - имя name может быть частью полного имени,  
testIgnoreCase | \- признак игнорирования регистра символов: TRUE - игнорировать регистр, FALSE - учитывать регистр.  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksViewProjection](ksviewprojection.html) или [IViewProjection](ksviewprojection.html).  
---|---  
  
Подразделы:

(отсутствуют)
