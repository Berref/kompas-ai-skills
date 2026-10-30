# VariableCollectionEx - Получить массив переменных из источника

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [IFeature - методы ](ksfeature_methods.html) |  Scroll [ [ [ ](ksfeaturecollection.html "К следующему разделу")](ksfeature_methods.html "На уровень выше")](ksfeature_variablecollection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfeature.html)

Синтаксис Automation:

LPDISPATCH VariableCollectionEx( BOOL sourсe );

Синтаксис COM:

LPVARIABLECOLLECTION VariableCollectionEx( BOOL sourсe );

Входные параметры:

Sourсe | \- признак получения списка переменных и значений из источника.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс коллекции переменных [ksVariableCollection](ksvariablecollection.html)[ или ](ksvariablecollection.html)[IvariableCollection](ksvariablecollection.html).  
---|---  
  
Примечание:

Метод позволяет получать и изменять переменные в исходном документе детали без открытия документа в отдельном окне или вслепую.

Подразделы:

(отсутствуют)
