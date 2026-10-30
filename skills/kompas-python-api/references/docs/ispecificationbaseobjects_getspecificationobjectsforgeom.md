# GetSpecificationObjectsForGeom - По геометрии получить массив объектов спецификации в виде SAFEARRAY'я DISPATCH - VT_ARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationBaseObjects ](ispecificationbaseobjects.html) > [ISpecificationBaseObjects - методы ](ispecificationbaseobjects_methods.html) |  Scroll [ [ [ ](ispecificationcolumnitems.html "К следующему разделу")](ispecificationbaseobjects_methods.html "На уровень выше")](ispecificationbaseobjects_copyspecificationobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationbaseobjects.html)

Синтаксис Automation:

VARIANT GetSpecificationObjectsForGeom( VARIANT PGeom,

VARIANT_BOOL Equal,

long SectionNumb,

double AttrNumb );

Синтаксис COM:

HRESULT GetSpecificationObjectsForGeom( [in]VARIANT PGeom,

[in]VARIANT_BOOL Equal,

[in] long SectionNumb,

[in] double AttrNumb,

[out, retval] VARIANT* PVal );

Входные параметры:

PGeom | \- Массив SafeArray типа VT_ARRAY | VT_DISPATCH объектов геометрии,  
---|---  
Equal | \- флаг типа BOOL TRUE - полное совпадение геометрии, FALSE - частичное совпадение геометрии,  
SectionNumb | \- номер раздела объектов СП,  
AttrNumb | \- номер типа атрибута объектов СП или 0.  
  
Возвращаемое значение:

| \- Массив SafeArray типа VT_ARRAY | VT_DISPATCH объектов спецификации.  
---|---  
  
Примечание:

1\. По присланной геометрии получить массив базовых объектов спецификации, содержащих эту геометрию. У базового объекта СП может быть установлена геометрия, которая ассоциируется с данным объектом.

Для 2D документа это массив IDrawingObject.

Для 3D документа это массив объектов:

•IPart7 (может быть один компонент),

•IBody7 (тела верхнего уровня сборки),

•IPositionLeader (обозначения позиций верхнего уровня сборки).

Получить массив объектов можно всегда.

2\. Если геометрия должна совпадать полностью, нужно передать параметр Equal=TRUE.

3\. Поиск можно ограничить объектами определенного раздела, если указать номер раздела объектов.

4\. Поиск можно ограничить объектами определенного типа атрибута.

Подразделы:

(отсутствуют)
