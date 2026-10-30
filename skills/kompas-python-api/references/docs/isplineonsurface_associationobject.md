# AssociationObject - Установить опорный объект для вершины

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISplineOnSurface ](isplineonsurface.html) > [ISplineOnSurface - свойства ](isplineonsurface_props.html) |  Scroll [ [ [ ](isplineonsurface_closed.html "К следующему разделу")](isplineonsurface_props.html "На уровень выше")](isplineonsurface_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isplineonsurface.html)

Тип данных: Указатель на интерфейс [IModelObject](imodelobject.html)

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
  
Входные параметры:

long Index - индекс вершины.

Подразделы:

(отсутствуют)
