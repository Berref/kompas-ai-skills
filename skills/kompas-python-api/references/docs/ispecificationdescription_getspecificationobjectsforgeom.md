# GetSpecificationObjectsForGeom - По геометрии получить массив объектов спецификации в виде SAFEARRAY'я DISPATCH - VT_ARRAY | VT_DISPATCH или одиночный VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationDescription ](ispecificationdescription.html) > [ISpecificationDescription - методы ](ispecificationdescription_methods.html) |  Scroll [ [ [ ](ispecificationdescription_update.html "К следующему разделу")](ispecificationdescription_methods.html "На уровень выше")](ispecificationdescription_getperformanceparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationdescription.html)

Синтаксис Automation:

VARIANT GetSpecificationObjectsForGeom( VARIANT PGeom, long SectionNumb, double AttrNumb );

Синтаксис COM:

HRESULT GetSpecificationObjectsForGeom( VARIANT PGeom, long SectionNumb, double AttrNumb, VARIANT * Result );

Входные параметры:

PGeom | \- массив SafeArray типа VT_ARRAY | VT_DISPATCH объектов геометрии,  
---|---  
SectionNumb | \- номер раздела объектов СП,  
AttrNumb | \- номер типа атрибута объектов СП или 0.  
  
Возвращаемое значение:

| \- Массив SafeArray типа VT_ARRAY | VT_DISPATCH объектов спецификации.  
---|---  
  
Версия Компас v23

Подразделы:

(отсутствуют)
