# SetLoftParam - Изменить параметры вырезанного элемента по сечениям

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Вырезанный элемент по сечениям (Интерфейсы ksCutLoftDefinition, ICutLoftDefinition) ](kscutloftdefinition.html) > [ICutLoftDefinition - методы ](kscutloftdefinition_methods.html) |  Scroll [ [ [ ](kscutloftdefinition_setthinparam.html "К следующему разделу")](kscutloftdefinition_methods.html "На уровень выше")](kscutloftdefinition_setdirectionalline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutloftdefinition.html)

Синтаксис Automation:

BOOL SetLoftParam (BOOL closed,

BOOL flipVertex,

BOOL autoPath);

Синтаксис COM:

BOOL SetLoftParam (BOOL closed,

BOOL flipVertex,

BOOL autoPath);

Входные параметры:

closed | \- признак замкнутости траектории: TRUE - траектория замкнута, FALSE - траектория разомкнута,  
---|---  
flipVertex | \- параметр зарезервирован для дальнейшего использования,  
autoPath | \- признак автоматического формирования траектории: TRUE - формировать траекторию автоматически, FALSE - для формирования траектории использовать точки, заданные методом [SetLoftPoint](kssketchdefinition_setloftpoint.html).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
