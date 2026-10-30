# Thickness - Толщина стенки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IThinParameters ](ithinparameters.html) > [IThinParameters - свойства ](ithinparameters_props.html) |  Scroll [ [ [ ](ithinparameters_methods.html "К следующему разделу")](ithinparameters_props.html "На уровень выше")](ithinparameters_thintype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ithinparameters.html)

Тип данных: double

Синтаксис Automation:

Thickness = iObject.Thickness( normal ); | Получить свойство ([* ](1.html))  
---|---  
iObject.Thickness( normal ) = Thickness; | Установить свойство ([* ](1.html))  
Thickness = iObject.GetThickness( normal ); | Получить свойство ([**](2.html))  
iObject.SetThickness( normal, Thickness ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Thickness( normal, &Thickness ); | Получить свойство  
---|---  
iObject->put_Thickness( normal, Thickness ); | Установить свойство  
  
Входные параметры:

normal | \- TRUE - толщина стенки в направлении наружу, \- FALSE - толщина стенки в направлении внутрь.  
---|---  
  
Примечание.

Позволяет установить и получить толщину стенки.

Подразделы:

(отсутствуют)
