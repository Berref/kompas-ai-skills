# Objects - Внутренние объекты макро

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Макрообъекты 3D ](bc2753948.html) > [Интерфейс IMacroObject3D ](imacroobject3d.html) > [IMacroObject3D - свойства ](imacroobject3d_propers.html) |  Scroll [ [ [ ](imacroobject3d_propertyobjecteditable.html "К следующему разделу")](imacroobject3d_propers.html "На уровень выше")](imacroobject3d_label.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imacroobject3d.html)

Тип данных: VARIANT

Синтаксис Automation:

Objects = Object.Objects | Получить свойство ([* ](1.html))  
---|---  
Object.Objects = Objects | Установить свойство ([* ](1.html))  
Objects = Object.GetObjects() | Получить свойство ([**](2.html))  
Object.SetObjects( Objects ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Objects( &Objects ) | Получить свойство  
---|---  
Object.put_Objects( Objects ) | Установить свойство  
  
Примечание:

Список объектов возвращается в виде массива SAFEARRAY объектов LPDISPATCH ( VT_ARRAY | VT_DISPATCH).

Если объект один, возвращается VARIANT с типом VT_DISPATCH.

Подразделы:

(отсутствуют)
