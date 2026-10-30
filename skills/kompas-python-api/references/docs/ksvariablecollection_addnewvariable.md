# AddNewVariable - Добавить новую переменную

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Массив переменных (Интерфейсы ksVariableCollection, IVariableCollection) ](ksvariablecollection.html) > [IVariableCollection - методы ](ksvariablecollection_methods.html) |  Scroll [ [ [ ](ksvariablecollection_getbyindex.html "К следующему разделу")](ksvariablecollection_methods.html "На уровень выше")](ksvariablecollection_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksvariablecollection.html)

Синтаксис Automation:

LPDISPATCH AddNewVariable( BSTR name, double value, BSTR note );

Синтаксис COM:

LPVARIABLE AddNewVariable( LPOLESTR name, double value, LPOLESTR note );

Входные параметры:

name | \- имя переменной,  
---|---  
value | \- значение переменной,  
Note | \- комментарий к переменной.  
  
Возвращаемое значение:

| \- указатель на интерфейс внешней переменной модели [ksVariable](ksvariable.html) или [IVariable](ksvariable.html).  
---|---  
  
Примечание:

Переменную можно добавлять только для [ksFeature](ksfeature.html) и [IFeature](ksfeature.html).

Подразделы:

(отсутствуют)
