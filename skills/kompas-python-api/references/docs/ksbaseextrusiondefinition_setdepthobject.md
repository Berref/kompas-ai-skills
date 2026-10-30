# SetDepthObject - Установить объект, задающий глубину выдавливания

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Основание — элемент выдавливания (Интерфейс ksBaseExtrusionDefinition, IBaseExtrusionDefinition) ](ksbaseextrusiondefinition.html) > [ksBaseExtrusionDefinition - методы ](ksbaseextrusiondefinition_methods.html) |  Scroll [ [ [ ](ksbaseextrusiondefinition_setsideparam.html "К следующему разделу")](ksbaseextrusiondefinition_methods.html "На уровень выше")](ksbaseextrusiondefinition_resetdepthobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbaseextrusiondefinition.html)

Синтаксис Automation:

BOOL SetDepthObject (BOOL normal, LPDISPATCH obj);

Синтаксис COM:

BOOL SetDepthObject (BOOL normal, LPENTITY obj);

Входные параметры:

normal | \- направление выдавливания: (TRUE - совпадает с направлением нормали к плоскости эскиза, FALSE - противоположно направлению нормали к плоскости эскиза),  
---|---  
obj | \- указатель на интерфейс объекта глубины выдавливания [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
