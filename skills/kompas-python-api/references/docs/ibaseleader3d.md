# Интерфейс IBaseLeader3D

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) |  Scroll [ [ [ ](ibaseleader3d_props.html "К следующему разделу")](bc2275772.html "На уровень выше")](ibase3d_setposition.html "К предыдущему разделу")  
---|---  
  
Интерфейс обозначения линии-выноски 3D.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IModelObject](imodelobject.html)

[IBaseLeader3D](ibaseleader3d.html)

[ILeader](ileader.html)

[IPositionLeader](ipositionleader.html)

[IBrandLeader](ibrandleader.html)

[IMarkLeader](imarkleader.html)

[IBranchs3D](ibranchs3d.html)

[IChangeLeader](ichangeleader.html)

Примечание:

1\. Интерфейс можно получить у коллекции линий выносок 3D, используя свойство [ILeaders3D::Leader3D](ileaders3d_leader3d.html) или метод [ILeaders3D::Add](ileaders3d_add.html).

2\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) интерфейс позволяет получить следующие дополнительные интерфейсы:

Тип линии-выноски | ksObj3dTypeEnum | Интерфейс,  
---|---|---  
Простая линия-выноска | o3d_leader3D | [ILeader,](ileader.html)  
Линия-выноска для обозначения позиции | o3d_positionLeader3D | [IPositionLeader,](ipositionleader.html)  
Линия-выноска для для обозначения клеймения | o3d_brandLeader3D | [IBrandLeader,](ibrandleader.html)  
Линия-выноска для обозначения маркирования | o3d_markLeader3D | [IMarkLeader,](imarkleader.html)  
Знак изменения |  | [IChangeLeader,](ichangeleader.html)  
Ответвления |  | [IBranchs3D.](ibranchs3d.html)  
  
3\. После задания параметров обозначения требуется вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

[IBaseLeader3D - свойства ](ibaseleader3d_props.html)

[IBaseLeader3D - методы ](ibaseleader3d_methods.html)
