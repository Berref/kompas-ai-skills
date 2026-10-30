# IsModified - Определить, модифицирована ли модель с момента последнего перестроения

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [IFeature - методы ](ksfeature_methods.html) |  Scroll [ [ [ ](ksfeature_isrollbacked.html "К следующему разделу")](ksfeature_methods.html "На уровень выше")](ksfeature_getownerfeature.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfeature.html)

Синтаксис Automation:

BOOL IsModified (BOOL recursive);

Синтаксис COM:

BOOL IsModified (BOOL recursive);

Входной параметр:

recursive | TRUE | Определять по вложенным объектам.  
---|---|---  
  
Возвращаемое значение:

TRUE | \- модель изменена с момента последнего перестроения,  
---|---  
FALSE | \- модель не изменена.  
  
Подразделы:

(отсутствуют)
