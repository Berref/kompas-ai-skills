# GetDepthObject - Получить объект, задающий глубину выдавливания

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Вырезанный элемент выдавливания (Интерфейсы ksCutExtrusionDefinition, ICutExtrusionDefinition) ](kscutextrusiondefinition.html) > [ICutExtrusionDefinition - методы ](kscutextrusiondefinition_methods.html) |  Scroll [ [ [ ](kscutextrusiondefinition_getsideparam.html "К следующему разделу")](kscutextrusiondefinition_methods.html "На уровень выше")](kscutextrusiondefinition_extrusionparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutextrusiondefinition.html)

Синтаксис Automation:

LPDISPATCH GetDepthObject (BOOL normal);

Синтаксис COM:

LPENTITY GetDepthObject (BOOL normal);

Входной параметр:

normal | \- направление выдавливания: (TRUE - совпадает с направлением нормали к плоскости эскиза, FALSE - противоположно направлению нормали к плоскости эскиза).  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс объекта [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Подразделы:

(отсутствуют)
