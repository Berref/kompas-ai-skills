# GetChamferParam - Получить параметры фаски

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Фаска (Интерфейсы ksChamferDefinition, IChamferDefinition) ](kschamferdefinition.html) > [ksChamferDefinition - методы ](kschamferdefinition_methods.html) |  Scroll [ [ [ ](kschamferdefinition_setchamferparam.html "К следующему разделу")](kschamferdefinition_methods.html "На уровень выше")](kschamferdefinition_array.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kschamferdefinition.html)

Синтаксис Automation:

BOOL GetChamferParam (BOOL *transfer,

double *distance1,

double *distance2);

Синтаксис COM:

BOOL GetChamferParam (BOOL *transfer,

double *distance1,

double *distance2);

Выходные параметры:

transfer | \- признак направления фаски,  
---|---  
distance1 | \- размер первого катета фаски,  
distance2 | \- размер второго катета фаски.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
