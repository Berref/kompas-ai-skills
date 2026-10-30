# Add - Добавить новый базовый объект спецификации в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationBaseObjects ](ispecificationbaseobjects.html) > [ISpecificationBaseObjects - методы ](ispecificationbaseobjects_methods.html) |  Scroll [ [ [ ](ispecificationbaseobjects_addwithparam.html "К следующему разделу")](ispecificationbaseobjects_methods.html "На уровень выше")](ispecificationbaseobjects_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationbaseobjects.html)

Синтаксис Automation:

LPDISPATCH Add (long Section, double AttrNumb);

Синтаксис COM:

HRESULT Add ([in] long Section,

[in] double AttrNumb,

[out, retval] ISpecificationBaseObject** Result);

Входные параметры:

Section | \- номер раздела,  
---|---  
AttrNumb | \- номер атрибута.  
  
Возвращаемое значение:

| \- Указатель на интерфейс [ISpecificationBaseObject](ispecificationbaseobject.html) базового объекта спецификации.  
---|---  
  
Примечание:

1\. После вызова метода Add объект будет добавлен в коллекцию, но в документе не появится. Для отображения объекта в документе нужно задать его параметры и вызвать метод [ISpecificationObject::Update](ispecificationobject_update.html).

2\. Объект c номером раздела 0.0. добавить нельзя. Нужно добавлять объект спецификации в существующий раздел. Затем с помощью [ISpecificationObject::AdditionalSection](ispecificationobject_additionalsection.html) переносить в дополнительный раздел.

Подразделы:

(отсутствуют)
