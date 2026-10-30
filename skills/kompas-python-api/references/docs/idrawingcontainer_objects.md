# Objects - Массив SAFEARRAY объектов, входящих в состав данного объекта вида

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IDrawingContainer ](idrawingcontainer.html) > [IDrawingContainer - свойства ](idrawingcontainer_props.html) |  Scroll [ [ [ ](idrawingcontainer_oledrawingobjects.html "К следующему разделу")](idrawingcontainer_props.html "На уровень выше")](idrawingcontainer_nurbsesbypoints.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingcontainer.html)

Массив SAFEARRAY объектов, входящих в состав данного объекта вида.

Тип данных: VARIANT

Синтаксис Automation:

Objects = iObject.Objects( ObjType ) | Получить свойство([* ](1.html))  
---|---  
Objects = iObject.GetObjects( ObjType ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Objects(&Objects( ObjType ) | Получить свойство  
---|---  
  
Входные параметры:

ObjType | \- тип 2D объектов из перечисления [DrawingObjectTypeEnum](drawingobjecttypeenum.html) или [KompasAPIObjectTypeEnum](kompasapiobjecttypeenum.html).  
---|---  
  
Примечание:

1.Свойство доступно только для чтения.

2.Коллекция объектов возвращается в виде массива SAFEARRAY объектов LPDISPATCH (VT_ARRAY | VT_DISPATCH). Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

3.В качестве типа объекта может передаваться одно значение (VT_I4) или массив типов объектов (VT_ARRAY| VT_I4).  
Типы объектов могут быть из перечислений [DrawingObjectTypeEnum](drawingobjecttypeenum.html) и [KompasAPIObjectTypeEnum](kompasapiobjecttypeenum.html).   
Если тип передается DrawingObjectTypeEnum::ksAllObj – возвращаются все объекты.

Подразделы:

(отсутствуют)
