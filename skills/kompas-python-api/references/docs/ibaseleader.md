# Интерфейс IBaseLeader

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) |  Scroll [ [ [ ](ibaseleader_props.html "К следующему разделу")](bb3219840.html "На уровень выше")](ibase_y0.html "К предыдущему разделу")  
---|---  
  
Интерфейс обозначения линии-выноски 2D.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IBaseLeader](ibaseleader.html)

[ILeader](ileader.html)

[IPositionLeader](ipositionleader.html)

[IBrandLeader](ibrandleader.html)

[IMarkLeader](imarkleader.html)

[IBranchs](ibranchs.html)

[IChangeLeader](ichangeleader.html)

Примечание:

1\. Получить интерфейс можно, используя свойство интерфейса коллекции линий-выносок [ILeaders::Leader](ileaders_leader.html) или метод [ILeaders::Add](ileaders_add.html).

2\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) интерфейс позволяет получить следующие дополнительные интерфейсы:

Объект | DrawingObjectTypeEnum | Интерфейс  
---|---|---  
Простая линия-выноска | ksDrLeader | [ILeader](ileader.html)  
Линия-выноска для обозначения позиции | ksDrPosLeader | [IPositionLeader](ipositionleader.html)  
Линия-выноска для для обозначения клеймения | ksDrBrandLeader | [IBrandLeader](ibrandleader.html)  
Линия-выноска для обозначения маркирования | ksDrMarkLeader | [IMarkLeader](imarkleader.html)  
Знак изменения | ksDrChangeLeader | [IChangeLeader](ichangeleader.html)  
Ответвления |  | [IBranchs](ibranchs.html)  
  
3\. После задания параметров объекта требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

[IBaseLeader - свойства ](ibaseleader_props.html)

[IBaseLeader - методы](ibaseleader---.html)
