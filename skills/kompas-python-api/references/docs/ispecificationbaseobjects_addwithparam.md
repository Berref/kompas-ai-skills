# AddWithParam - Добавить новый объект спецификации в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationBaseObjects ](ispecificationbaseobjects.html) > [ISpecificationBaseObjects - методы ](ispecificationbaseobjects_methods.html) |  Scroll [ [ [ ](ispecificationbaseobjects_copyspecificationobject.html "К следующему разделу")](ispecificationbaseobjects_methods.html "На уровень выше")](ispecificationbaseobjects_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationbaseobjects.html)

Синтаксис Automation:

LPDISPATCH AddWithParam( ISpecificationObjectCreateParam * Param, IPropertyKeeper * PropertyObject, BOOL FillText, VARIANT Geometry );

Синтаксис COM:

HRESULT AddWithParam( ISpecificationObjectCreateParam * Param, IPropertyKeeper * PropertyObject, BOOL FillText, VARIANT Geometry, ISpecificationBaseObject * * Result );

Возвращаемое значение:

| \- указатель на интерфейс [ISpecificationBaseObject](ispecificationbaseobject.html).  
---|---  
  
Входные параметры:

Param | \- Указатель на интерфейс расширенных параметров создания объекта спецификации [ISpecificationObjectCreateParam](ispecificationobjectcreateparam.html),  
---|---  
PropertyObject | \- Указатель на интерфейс объекта, связываемого с объектом спецификации [IPropertyKeeper](ipropertykeeper.html),  
Geometry | \- Геометрия, используемая для подсветки в документе.  
  
Выходные параметры:

FillText | \- TRUE - заполнить тексты колонок объекта спецификации по свойствам объекта.  
---|---  
  
Примечание:

1\. При передаче в функцию указателя на объект PropertyObject объект спецификации и объект будут иметь общий ключ информационного объекта. Данные будут сохраняться в общем блоке свойств в метаданных.

2\. При редактировании свойств объекта изменения будут передаваться в объект спецификации. Изменение текста объекта спецификации будет передаваться в свойства объекта.

Если объект не передается, то объект спецификации может иметь произвольную геометрию для подсветки, но тексты не будут связаны со свойствами какого-то из объектов.

Подразделы:

(отсутствуют)
