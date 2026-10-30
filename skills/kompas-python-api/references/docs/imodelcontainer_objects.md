# Objects - Трехмерные объекты, входящие в состав данного объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Контейнер ](bc2278809.html) > [Интерфейс IModelContainer ](imodelcontainer.html) > [IModelContainer - свойства ](imodelcontainer_props.html) |  Scroll [ [ [ ](imodelcontainer_points3d.html "К следующему разделу")](imodelcontainer_props.html "На уровень выше")](imodelcontainer_moldcavities.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imodelcontainer.html)

Тип данных: VARIANT

Синтаксис Automation:

Objects = iObject.Objects(ObjType) | Получить свойство ([* ](1.html))  
---|---  
Objects = iObject.GetObjects(ObjType) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Objects( &Objects ) | Получить свойство  
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
