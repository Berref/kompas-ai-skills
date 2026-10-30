# RemoveVariable - Удалить переменную

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Массив переменных (Интерфейсы ksVariableCollection, IVariableCollection) ](ksvariablecollection.html) > [IVariableCollection - методы ](ksvariablecollection_methods.html) |  Scroll [ [ [ ](ksvariable.html "К следующему разделу")](ksvariablecollection_methods.html "На уровень выше")](ksvariablecollection_refresh.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksvariablecollection.html)

Синтаксис Automation:

BOOL RemoveVariable (BSTR name);

Синтаксис COM:

BOOL RemoveVariable (LPOLESTR name);

Входные параметры:

name | \- имя переменной.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

1\. Переменную можно удалить только для [ksFeature](ksfeature.html) и [IFeature](ksfeature.html).

2\. Массив автоматически обновляется в случае удачного завершения.

Подразделы:

(отсутствуют)
