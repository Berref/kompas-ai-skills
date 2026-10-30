# Refresh - Обновить массив

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Трехмерное тело ](ca1747705.html) > [Интерфейсы, получаемые от ksFaceDefinition ](ca1747810.html) > [Массив ребер (Интерфейсы ksEdgeCollection, IEdgeCollection) ](ksedgecollection.html) > [IEdgeCollection - методы ](ksedgecollection_methods.html) |  Scroll [ [ [ ](ca1714932.html "К следующему разделу")](ksedgecollection_methods.html "На уровень выше")](ksedgecollection_prev.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksedgecollection.html)

Синтаксис Automation:

BOOL Refresh();

Синтаксис COM:

BOOL Refresh();

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

После вызова данной функции возникает полное соответствие массива с массивом ребер грани и удаляются все предыдущие изменения в массиве.

Подразделы:

(отсутствуют)
