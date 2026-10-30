# Refresh - Обновить массив внешних переменных

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Массив переменных (Интерфейсы ksVariableCollection, IVariableCollection) ](ksvariablecollection.html) > [IVariableCollection - методы ](ksvariablecollection_methods.html) |  Scroll [ [ [ ](ksvariablecollection_removevariable.html "К следующему разделу")](ksvariablecollection_methods.html "На уровень выше")](ksvariablecollection_prev.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksvariablecollection.html)

Синтаксис Automation:

BOOL Refresh();

Синтаксис COM:

BOOL Refresh();

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

После вызова данной функции удаляются все изменения в массиве внешних переменных компонента, которые не были закреплены вызовом функции [RebuildModel](kspart_rebuildmodel.html). Таким образом, возникает полное соответствие массива внешних переменных в памяти с массивом внешних переменных компонента.

Вызов данной функции эквивалентен отказу пользователя от перестроения модели после изменения значений внешних переменных (модель не перестраивается, а измененные значения переменных "забываются", переменные принимают прежние значения).

Подразделы:

(отсутствуют)
