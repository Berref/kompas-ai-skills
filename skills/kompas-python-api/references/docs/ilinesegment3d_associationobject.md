# AssociationObject - Установить опорный объект для вершины

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ILineSegment3D ](ilinesegment3d.html) > [ILineSegment3D - свойства ](ilinesegment3d_props.html) |  Scroll [ [ [ ](ilinesegment3d_baseplane.html "К следующему разделу")](ilinesegment3d_props.html "На уровень выше")](ilinesegment3d_angle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilinesegment3d.html)

Тип данных: Указатель на интерфейс [IModelObject](imodelobject.html)

Синтаксис Automation:

AssociationObject = Object.AssociationObject( Begin ) | Получить свойство ([* ](1.html))  
---|---  
Object.AssociationObject( Begin ) = AssociationObject | Установить свойство ([* ](1.html))  
AssociationObject = Object.GetAssociationObject( Begin ) | Получить свойство ([**](2.html))  
Object.SetAssociationObject( Begin, AssociationObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_AssociationObject( Begin, &AssociationObject ) | Получить свойство  
---|---  
Object.put_AssociationObject( Begin, AssociationObject ) | Установить свойство  
  
Входные параметры:

BOOL Begin - начальная точка

Подразделы:

(отсутствуют)
