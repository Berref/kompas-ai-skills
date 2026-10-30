# CopySpecificationObject - Копирование объекта спецификации

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationBaseObjects ](ispecificationbaseobjects.html) > [ISpecificationBaseObjects - методы ](ispecificationbaseobjects_methods.html) |  Scroll [ [ [ ](ispecificationbaseobjects_getspecificationobjectsforgeom.html "К следующему разделу")](ispecificationbaseobjects_methods.html "На уровень выше")](ispecificationbaseobjects_addwithparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationbaseobjects.html)

Синтаксис Automation:

LPDISPATCH CopySpecificationObject( ISpecificationBaseObject * SpcObj, VARIANT Geometry );

Синтаксис COM:

HRESULT CopySpecificationObject( ISpecificationBaseObject * SpcObj, VARIANT Geometry, ISpecificationBaseObject ** Result );

Возвращаемое значение:

| \- Указатель на интерфейс скопированного объекта.  
---|---  
  
Входные параметры:

SpcObj | \- копируемый объект,  
---|---  
Geometry | \- геометрия объекта спецификации (Объект VT_DISPATCH или список объектов VT_ARRAY | VT_DISPATCH).  
  
Подразделы:

(отсутствуют)
