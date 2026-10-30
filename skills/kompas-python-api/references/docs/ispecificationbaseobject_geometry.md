# Geometry - Геометрия объекта спецификации

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationBaseObject ](ispecificationbaseobject.html) > [ISpecificationBaseObject - свойства ](ispecificationbaseobject_props.html) |  Scroll [ [ [ ](groupobject.html "К следующему разделу")](ispecificationbaseobject_props.html "На уровень выше")](ispecificationbaseobject_fillnamebymaterial.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationbaseobject.html)

Тип данных: VARIANT

Значения свойства:

Массив SafeArray типа VT_ARRAY | VT_DISPATCH |   
---|---  
  
Синтаксис Automation:

Geometry = iObject.Geometry | Получить свойство ([* ](1.html))  
---|---  
iObject.Geometry = Geometry | Установить свойство ([* ](1.html))  
Geometry = iObject.GetGeometry() | Получить свойство ([**](2.html))  
iObject.SetGeometry(Geometry) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Geometry(&Geometry) | Получить свойство  
---|---  
iObject->put_Geometry(Geometry) | Установить свойство  
  
Примечание:

У базового объекта СП может быть установлена геометрия, которая ассоциируется с данным объектом.

Для 2D документа это массив IDrawingObject.

Для 3D документа это массив объектов:

•IPart7(может быть один компонент),

•IBody7 (тела верхнего уровня сборки),

•IPositionLeader ( обозначения позиций верхнего уровня сборки).

•Получить можно всегда массив объектов. Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

•Установить можно как массив, так и одиночный объект. При установке геометрии старая геометрия очищается.

При установке геометрии используется текущее значение флага [ISpecificationBaseObject::SyncronizeWithProperties.](ispecificationbaseobject_syncronizewithproperties.html)

Версия: Компас v20

Подразделы:

(отсутствуют)
