# VariableCollection - Получить указатель на интерфейс массива переменных

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [IFeature - методы ](ksfeature_methods.html) |  Scroll [ [ [ ](ksfeature_variablecollectionex.html "К следующему разделу")](ksfeature_methods.html "На уровень выше")](ksfeature_subfeaturecollection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfeature.html)

Синтаксис Automation:

LPDISPATCH VariableCollection();

Синтаксис COM:

LPVARIABLECOLLECTION VariableCollection();

Возвращаемое значение:

| \- указатель на интерфейс [ksVariableCollection](ksvariablecollection.html) или [IVariableCollection](ksvariablecollection.html).  
---|---  
  
Примечание:

Изменения в полученном массиве не отображаются в модели немедленно. Чтобы изменения вступили в силу, необходимо вызвать метод [ksPart::RebuildModel](kspart_rebuildmodel.html).

Подразделы:

(отсутствуют)
