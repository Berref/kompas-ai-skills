# GetByName - Получить указатель на интерфейс компонента по имени

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Массив компонентов сборки (Интерфейсы ksPartCollection и IPartCollection) ](kspartcollection.html) > [ksPartCollection - методы ](kspartcollection_methods.html) |  Scroll [ [ [ ](kspartcollection_getcount.html "К следующему разделу")](kspartcollection_methods.html "На уровень выше")](kspartcollection_getbyindex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspartcollection.html)

Синтаксис Automation:

LPDISPATCH GetByName (BSTR name,

BOOL testFullName,

BOOL testIgnoreCase);

Синтаксис COM:

LPPART GetByName (LPOLESTR name,

BOOL testFullName,

BOOL testIgnoreCase);

Входные параметры:

name | \- имя объекта,  
---|---  
testFullName | \- признак полного имени (TRUE - полное имя),  
testIgnoreCase | \- признак учета регистра: TRUE - игнорировать регистр, FALSE - учитывать регистр.  
  
Возвращаемое значение:

| \- указатель на интерфейс компонента [ksPart](kspart.html) или [IPart](kspart.html).  
---|---  
  
Подразделы:

(отсутствуют)
