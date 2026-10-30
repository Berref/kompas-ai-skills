# SetSketch - Установить эскиз секущей поверхности

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Сечение по эскизу (Интерфейсы ksCutBySketchDefinition, ICutBySketchDefinition) ](kscutbysketchdefinition.html) > [ICutBySketchDefinition - методы ](kscutbysketchdefinition_methods.html) |  Scroll [ [ [ ](ksshelldefinition.html "К следующему разделу")](kscutbysketchdefinition_methods.html "На уровень выше")](kscutbysketchdefinition_getsketch.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutbysketchdefinition.html)

Синтаксис Automation:

BOOL SetSketch (LPDISPATCH sketch);

Синтаксис COM:

BOOL SetSketch (LPENTITY sketch);

Входной параметр:

plane | \- указатель на интерфейс эскиза секущей поверхности [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
