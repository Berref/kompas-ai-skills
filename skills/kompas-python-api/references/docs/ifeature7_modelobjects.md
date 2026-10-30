# ModelObjects - Объекты, входящие в состав данного объекта (грани, ребра, вершины)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IFeature7 ](ifeature7.html) > [IFeature7 - свойства ](ifeature7_props.html) |  Scroll [ [ [ ](ifeature7_name.html "К следующему разделу")](ifeature7_props.html "На уровень выше")](ifeature7_label.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifeature7.html)

Тип данных: VARIANT

Синтаксис Automation:

ModelObjects = iObject.ModelObjects (ObjType) | Получить свойство ([* ](1.html))  
---|---  
ModelObjects = iObject.GetModelObjects (ObjType) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ModelObjects (ObjType, &ModelObjects) | Получить свойство  
---|---  
  
Входные параметры:

ObjType | \- тип трехмерных объектов из перечисления [ksObj3dTypeEnum](obj3dtype.html) или [KompasAPIObjectTypeEnum](kompasapiobjecttypeenum.html).  
---|---  
  
Примечание:

1.Свойство доступно только для чтения.

2.Коллекция объектов возвращается в виде массива SAFEARRAY объектов LPDISPATCH (VT_ARRAY | VT_DISPATCH). Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

3.В качестве типа объекта может передаваться одно значение (VT_I4) или массив типов объектов (VT_ARRAY| VT_I4).  
Типы объектов могут быть из перечислений [ksObj3dTypeEnum](obj3dtype.html) и [KompasAPIObjectTypeEnum](kompasapiobjecttypeenum.html).   
Если тип передается ksObj3dTypeEnum::o3d_unknown – возвращаются все объекты.

Подразделы:

(отсутствуют)
