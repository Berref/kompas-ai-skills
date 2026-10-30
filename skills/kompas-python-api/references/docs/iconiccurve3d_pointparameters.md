# PointParameters - Получить интерфейс параметров точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IConicCurve3D](iconiccurve3d.html) > [IConicCurve3D - свойства](iconiccurve3d_propers.html) |  Scroll [ [ [ ](iconiccurve3d_pointtype.html "К следующему разделу")](iconiccurve3d_propers.html "На уровень выше")](iconiccurve3d_minimumtension.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconiccurve3d.html)

Тип данных: Указатель на интерфейс [IKompasAPIObject](ikompasapiobject.html)

Синтаксис Automation:

PointParameters = Object.PointParameters( Index ) | Получить свойство ([* ](1.html))  
---|---  
PointParameters = Object.GetPointParameters( Index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_PointParameters( Index, &PointParameters ) | Получить свойство  
---|---  
  
Входные параметры:

Index - индекс вершины из перечисления [ksConicCurve3DParameterEnum](ksconiccurve3dparameterenum.html).

Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
