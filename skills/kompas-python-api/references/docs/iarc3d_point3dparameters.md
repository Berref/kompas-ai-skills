# Point3DParameters - Получить интерфейс параметров точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IArc3D ](iarc3d.html) > [IArc3D - свойства ](iarc3d_props.html) |  Scroll [ [ [ ](iarc3d_radius.html "К следующему разделу")](iarc3d_props.html "На уровень выше")](iarc3d_point3dparameterstype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iarc3d.html)

Тип данных: указатель на интерфейс [IKompasAPIObject](ikompasapiobject.html)

Синтаксис Automation:

Point3DParameters = Object.Point3DParameters( Index ) | Получить свойство ([* ](1.html))  
---|---  
Point3DParameters = Object.GetPoint3DParameters( Index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Point3DParameters( Index, &Point3DParameters ) | Получить свойство  
---|---  
  
Входные параметры:

Index - индекс вершины из перечисления [ksArc3DParameterEnum](ksarc3dparameterenum.html).

Свойство позволяет задать вершину дуги, используя способы построения точки.

Примечание

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
