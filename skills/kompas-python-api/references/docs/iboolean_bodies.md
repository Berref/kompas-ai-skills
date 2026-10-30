# Bodies - Массив тел

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IBoolean ](iboolean.html) > [IBoolean - свойства ](iboolean_propers.html) |  Scroll [ [ [ ](iboolean_baseobject.html "К следующему разделу")](iboolean_propers.html "На уровень выше")](iboolean_propers.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iboolean.html)

Тип данных: VARIANT

Синтаксис Automation:

Bodies = Object.Bodies | Получить свойство ([* ](1.html))  
---|---  
Object.Bodies = Bodies | Установить свойство ([* ](1.html))  
Bodies = Object.GetBodies() | Получить свойство ([**](2.html))  
Object.SetBodies( Bodies ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Bodies( &Bodies ) | Получить свойство  
---|---  
Object.put_Bodies( Bodies ) | Установить свойство  
  
Примечание.

Позволяет получать и устанавливать массив тел, участвующих в операции.

Массив возвращается в виде массива SAFEARRAY тел LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
