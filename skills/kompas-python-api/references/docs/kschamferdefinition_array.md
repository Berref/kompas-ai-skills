# Array - Получить указатель на интерфейс массива ребер и граней, на которых строится фаска

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Фаска (Интерфейсы ksChamferDefinition, IChamferDefinition) ](kschamferdefinition.html) > [ksChamferDefinition - методы ](kschamferdefinition_methods.html) |  Scroll [ [ [ ](kschamferdefinition_getchamferparam.html "К следующему разделу")](kschamferdefinition_methods.html "На уровень выше")](kschamferdefinition_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kschamferdefinition.html)

Синтаксис Automation:

LPDISPATCH Array();

Синтаксис COM:

LPENTITYCOLLECTION Array();

Возвращаемое значение:

| \- указатель на интерфейс [ksEntityCollection](ksentitycollection.html) или [IEntityCollection](ksentitycollection.html).  
---|---  
  
Примечание:

В полученный с помощью данного метода массив нельзя добавлять нулевые указатели.

Подразделы:

(отсутствуют)
