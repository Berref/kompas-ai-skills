# GetByName - Получить указатель на интерфейс элемента массива по имени

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Массив переменных (Интерфейсы ksVariableCollection, IVariableCollection) ](ksvariablecollection.html) > [IVariableCollection - методы ](ksvariablecollection_methods.html) |  Scroll [ [ [ ](ksvariablecollection_getcount.html "К следующему разделу")](ksvariablecollection_methods.html "На уровень выше")](ksvariablecollection_getbyindex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksvariablecollection.html)

Синтаксис Automation:

LPDISPATCH GetByName (BSTR name,

BOOL testFullName,

BOOL testIgnoreCase);

Синтаксис COM:

LPVARIABLE GetByName (LPOLESTR name,

BOOL testFullName,

BOOL testIgnoreCase);

Входные параметры:

name | \- имя объекта,  
---|---  
testFullName | \- признак полного имени: TRUE - name - полное имя, FALSE - имя name может быть частью полного имени,  
testIgnoreCase | \- признак игнорирования регистра символов имени: TRUE - игнорировать регистр, FALSE - учитывать регистр.  
  
Возвращаемое значение:

| \- указатель на интерфейс внешней переменной модели [ksVariable](ksvariable.html) или [IVariable](ksvariable.html).  
---|---  
  
Подразделы:

(отсутствуют)
