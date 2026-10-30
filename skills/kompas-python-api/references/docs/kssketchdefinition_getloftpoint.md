# GetLoftPoint - Получить координаты точки в плоскости эскиза

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Эскиз (Интерфейсы ksSketchDefinition, ISketchDefinition) ](kssketchdefinition.html) > [ISketchDefinition - методы ](kssketchdefinition_methods.html) |  Scroll [ [ [ ](kssketchdefinition_getplane.html "К следующему разделу")](kssketchdefinition_methods.html "На уровень выше")](kssketchdefinition_getlocation.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssketchdefinition.html)

Синтаксис Automation:

BOOL GetLoftPoint (double * x, double * y);

Синтаксис COM:

BOOL GetLoftPoint (double * x, double * y);

Выходные параметры:

x, y | \- координаты точки.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

При формировании элемента по сечениям (операции [ksBaseLoftDefinition](ksbaseloftdefinition.html), [ksBossLoftDefinition](ksbaseloftdefinition.html), [ksCutLoftDefinition](kscutloftdefinition.html)) полученная точка определяет ближайшую к ней вершину как точку, через которую пройдет линия, соединяющая эскизы.

Подразделы:

(отсутствуют)
