# AssociationObject - Опорный объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IUserObject3D ](iuserobject3d.html) > [IUserObject3D - свойства ](iuserobject3d_props.html) |  Scroll [ [ [ ](iuserobject3d_associationobjectcount.html "К следующему разделу")](iuserobject3d_props.html "На уровень выше")](iuserobject3d_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserobject3d.html)

Тип данных: Указатель на интерфейс [IModelObject](imodelobject.html)

Синтаксис Automation:

AssociationObject = Object.AssociationObject( Index ); | Получить свойство ([* ](1.html))  
---|---  
Object.AssociationObject( Index ) = AssociationObject; | Установить свойство ([* ](1.html))  
AssociationObject = Object.GetAssociationObject( Index ); | Получить свойство ([**](2.html))  
Object.SetAssociationObject( Index, AssociationObject ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_AssociationObject( Index, &AssociationObject ) | Получить свойство  
---|---  
Object.put_AssociationObject( Index, AssociationObject ) | Установить свойство  
  
Входные параметры:

long Index | \- индекс объекта.  
---|---  
  
Подразделы:

(отсутствуют)
