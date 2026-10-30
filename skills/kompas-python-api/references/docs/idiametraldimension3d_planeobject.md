# PlaneObject - Фиксирующий объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Размеры ](bc2274179.html) > [Интерфейс IDiametralDimension3D ](idiametraldimension3d.html) > [IDiametralDimension3D - свойства ](idiametraldimension3d_props.html) |  Scroll [ [ [ ](idiametraldimension3d_methods.html "К следующему разделу")](idiametraldimension3d_props.html "На уровень выше")](idiametraldimension3d_object1.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idiametraldimension3d.html)

Тип данных: указатель на интерфейс модельного объекта [IModelObject](imodelobject.html)

Синтаксис Automation:

PlaneObject = Object.PlaneObject | Получить свойство ([* ](1.html))  
---|---  
Object.PlaneObject = PlaneObject | Установить свойство ([* ](1.html))  
PlaneObject = Object.GetPlaneObject() | Получить свойство ([**](2.html))  
Object.SetPlaneObject( PlaneObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_PlaneObject( &PlaneObject ) | Получить свойство ([* ](1.html))  
---|---  
Object.put_PlaneObject( PlaneObject ) | Установить свойство ([* ](1.html))  
  
Примечание:

Положение размера можно зафиксировать. Для фиксации положения размера укажите точечный объект или плоский объект, параллельный плоскости простановки размера. Размер будет проставлен в плоскости, проходящей через объект фиксации. Между размером и объектом фиксации формируется ассоциативная связь. Благодаря этой связи размер следует за объектом фиксации при изменении положения последнего.

Для снятия фиксации установите значение свойства == NULL.

Подразделы:

(отсутствуют)
