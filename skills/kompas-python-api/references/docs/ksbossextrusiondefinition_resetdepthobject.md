# ResetDepthObject - Отказаться от установленного методом SetDepthObject объекта, задающего глубину выдавливания

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Приклеенный элемент выдавливания (Интерфейсы ksBossExtrusionDefinition, IBossExtrusionDefinition) ](ksbossextrusiondefinition.html) > [ksBossExtrusionDefinition - методы ](ksbossextrusiondefinition_methods.html) |  Scroll [ [ [ ](ksbossextrusiondefinition_setdepthobject.html "К следующему разделу")](ksbossextrusiondefinition_methods.html "На уровень выше")](ksbossextrusiondefinition_getthinparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbossextrusiondefinition.html)

Синтаксис Automation:

BOOL ResetDepthObject (BOOL normal);

Синтаксис COM:

BOOL ResetDepthObject (BOOL normal);

Входные параметры:

normal | \- направление выдавливания: (TRUE - совпадает с направлением нормали к плоскости эскиза, FALSE - противоположно направлению нормали к плоскости эскиза).  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс объекта [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
См. также метод [SetDepthObject](ksbossextrusiondefinition_setdepthobject.html)

Подразделы:

(отсутствуют)
