# GetLoftParam - Получить параметры элемента по сечениям

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Основание — элемент по сечениям (Интерфейсы ksBaseLoftDefinition, IBaseLoftDefinition) ](ksbaseloftdefinition.html) > [IBaseLoftDefinition - методы ](ksbaseloftdefinition_methods.html) |  Scroll [ [ [ ](ksbaseloftdefinition_getthinparam.html "К следующему разделу")](ksbaseloftdefinition_methods.html "На уровень выше")](ksbaseloftdefinition_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbaseloftdefinition.html)

Синтаксис Automation:

BOOL GetLoftParam (BOOL *closed,

BOOL *flipVertex,

BOOL *autoPath);

Синтаксис COM:

BOOL GetLoftParam (BOOL *closed,

BOOL *flipVertex,

BOOL *autoPath);

Выходные параметры:

closed | \- признак замкнутости траектории: TRUE - траектория замкнута, FALSE - траектория разомкнута,  
---|---  
flipVertex | \- параметр зарезервирован для дальнейшего использования,  
autoPath | \- признак автоматического формирования траектории: TRUE - формировать траекторию автоматически, FALSE - для формирования траектории использовать точки, заданные методом [SetLoftPoint](kssketchdefinition_setloftpoint.html).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
