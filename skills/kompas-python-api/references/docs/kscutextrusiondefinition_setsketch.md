# SetSketch - Изменить указатель на интерфейс эскиза элемента

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Вырезанный элемент выдавливания (Интерфейсы ksCutExtrusionDefinition, ICutExtrusionDefinition) ](kscutextrusiondefinition.html) > [ICutExtrusionDefinition - методы ](kscutextrusiondefinition_methods.html) |  Scroll [ [ [ ](kscutextrusiondefinition_setthinparam.html "К следующему разделу")](kscutextrusiondefinition_methods.html "На уровень выше")](kscutextrusiondefinition_setsideparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutextrusiondefinition.html)

Синтаксис Automation:

BOOL SetSketch (LPDISPATCH sketch);

Синтаксис COM:

BOOL SetSketch (LPENTITY sketch);

Входной параметр:

sketch | \- указатель на интерфейс эскиза [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
