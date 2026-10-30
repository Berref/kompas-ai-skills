# AssociationObject - Установить опорный объект для вершины

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IArc3D ](iarc3d.html) > [IArc3D - свойства ](iarc3d_props.html) |  Scroll [ [ [ ](iarc3d_buildingobject.html "К следующему разделу")](iarc3d_props.html "На уровень выше")](iarc3d_angle2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iarc3d.html)

Тип данных: указатель на интерфейс [IModelObject](imodelobject.html)

Синтаксис Automation:

AssociationObject = Object.AssociationObject( Index ) | Получить свойство ([* ](1.html))  
---|---  
Object.AssociationObject( Index ) = AssociationObject | Установить свойство ([* ](1.html))  
AssociationObject = Object.GetAssociationObject( Index ) | Получить свойство ([**](2.html))  
Object.SetAssociationObject( Index, AssociationObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_AssociationObject( Index, &AssociationObject ) | Получить свойство  
---|---  
Object.put_AssociationObject( Index, AssociationObject ) | Установить свойство  
  
Входные параметры

Index - индекс вершины из перечисления [ksArc3DParameterEnum](ksarc3dparameterenum.html)

Свойство позволяет связать вершину дуги с уже имеющимся точечным объектом.

Подразделы:

(отсутствуют)
