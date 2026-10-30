# GetByName - Получить указатель на интерфейс объекта в массиве по имени

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Массив объектов модели (Интерфейсы ksEntityCollection и IEntityCollection) ](ksentitycollection.html) > [ksEntityCollection - методы ](ksentitycollection_methods.html) |  Scroll [ [ [ ](ksentitycollection_getcount.html "К следующему разделу")](ksentitycollection_methods.html "На уровень выше")](ksentitycollection_getbyindex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksentitycollection.html)

Синтаксис Automation:

LPDISPATCH GetByName (BSTR name,

BOOL testFullName,

BOOL testIgnoreCase);

Синтаксис COM:

LPENTITY GetByName (LPOLESTR name,

BOOL testFullName,

BOOL testIgnoreCase);

Входные параметры:

name | \- имя объекта,  
---|---  
testFullName | \- признак полного имени: TRUE - name - полное имя, FALSE - имя name может быть частью полного имени,  
testIgnoreCase | \- признак игнорирования регистра символов: TRUE - игнорировать регистр, FALSE - учитывать регистр.  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Подразделы:

(отсутствуют)
