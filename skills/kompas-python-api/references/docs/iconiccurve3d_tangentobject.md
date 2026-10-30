# TangentObject - Направляющий объект для начальной и конечной точек

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IConicCurve3D](iconiccurve3d.html) > [IConicCurve3D - свойства](iconiccurve3d_propers.html) |  Scroll [ [ [ ](iconiccurve3d_tangentvector.html "К следующему разделу")](iconiccurve3d_propers.html "На уровень выше")](iconiccurve3d_tangentanglereverse.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconiccurve3d.html)

Тип данных: Указатель на интерфейс [IModelObject](imodelobject.html)

Синтаксис Automation:

TangentObject = Object.TangentObject( BeginPoint ) | Получить свойство ([* ](1.html))  
---|---  
Object.TangentObject( BeginPoint ) = TangentObject | Установить свойство ([* ](1.html))  
TangentObject = Object.GetTangentObject( BeginPoint ) | Получить свойство ([**](2.html))  
Object.SetTangentObject( BeginPoint, TangentObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_TangentObject( BeginPoint, &TangentObject ) | Получить свойство  
---|---  
Object.put_TangentObject( BeginPoint, TangentObject ) | Установить свойство  
  
Входные параметры:

BOOL BeginPoint - TRUE - начальная точка, FALSE - конечная точка.

Подразделы:

(отсутствуют)
