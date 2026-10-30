# GetByName - Получить указатель на интерфейс объекта в массиве по имени

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Массив граней (Интерфейсы ksFaceCollection, IFaceCollection) ](ksfacecollection.html) > [IFaceCollection - методы ](ksfacecollection_methods.html) |  Scroll [ [ [ ](ksfacecollection_getcount.html "К следующему разделу")](ksfacecollection_methods.html "На уровень выше")](ksfacecollection_getbyindex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfacecollection.html)

Синтаксис Automation:

LPDISPATCH GetByName (BSTR name,

BOOL testFullName,

BOOL testIgnoreCase);

Синтаксис COM:

LPFACEDEFINITION GetByName (LPOLESTR name,

BOOL testFullName,

BOOL testIgnoreCase);

Входные параметры:

name | \- название грани,  
---|---  
testFullName | \- признак полного имени: TRUE - name - проверять по полному пути, FALSE - имя name может быть частью полного имени,  
testIgnoreCase | \- признак игнорирования регистра символов: TRUE - игнорировать регистр, FALSE - учитывать регистр.  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksFaceDefinition](ksfacedefinition.html) или [IFaceDefinition](ksfacedefinition.html).  
---|---  
  
Подразделы:

(отсутствуют)
