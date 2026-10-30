# SetMaterial - Установить материал в объект спецификации и связанный с ним документ

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationBaseObject ](ispecificationbaseobject.html) > [ISpecificationBaseObject - методы ](ispecificationbaseobject_methods.html) |  Scroll [ [ [ ](ispecificationbaseobject_setsection.html "К следующему разделу")](ispecificationbaseobject_methods.html "На уровень выше")](ispecificationbaseobject_includegeometry.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationbaseobject.html)

Синтаксис Automation:

BOOL SetMaterial( BSTR Material, double Density );

Синтаксис COM:

HRESULT SetMaterial( BSTR Material, double Density, BOOL * Result );

Входные параметры:

Material | \- материал,  
---|---  
Density | \- плотность.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
