# GetIntersectionType - Получить тип пересечения по индексу

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Трехмерное тело ](ca1747705.html) > [Интерфейс результатов пересечения тел (Интерфейсы ksIntersectionResult, IIntersectionResult) ](ksintersectionresult.html) > [IIntersectionResult - методы ](ksintersectionresult_methods.html) |  Scroll [ [ [ ](ksmassinertiaparam.html "К следующему разделу")](ksintersectionresult_methods.html "На уровень выше")](ksintersectionresult_getcount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksintersectionresult.html)

Синтаксис Automation:

long GetIntersectionType (long index);

Синтаксис COM:

long GetIntersectionType( long index );

Входные параметры:

index | \- индекс пересечения.  
---|---  
  
Возвращаемое значение:

| \- тип пересечения.  
---|---  
  
Примечание:

Два тела в сборке могут иметь более одного пересечения. См. также [Типы пересечений](intersection_type.html)

Подразделы:

(отсутствуют)
