# Add - Создать новый элемент и добавить его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс ILeaders3D ](ileaders3d.html) > [ILeaders3D - методы ](ileaders3d_methods.html) |  Scroll [ [ [ ](iroughs3d.html "К следующему разделу")](ileaders3d_methods.html "На уровень выше")](ileaders3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ileaders3d.html)

Синтаксис Automation:

LPDISPATCH Add( ksObj3dTypeEnum DimType );

Синтаксис COM:

HRESULT Add( ksObj3dTypeEnum DimType, IBaseLeader3D ** Result );

Входные параметры:

DimType | \- тип линии-выноски.  
---|---  
  
Типы линий-выносок:

o3d_leader3D | 86 | Линия-выноска 3D,  
---|---|---  
o3d_markLeader3D | 87 | Знак маркировки 3D,  
o3d_positionLeader3D | 89 | Обозначение позиции 3D,  
o3d_brandLeader3D | 90 | Знак клеймения 3D.  
  
Возвращаемое значение:

| \- Указатель на интерфейс линии-выноски [IBaseLeader3D](ibaseleader3d.html).  
---|---  
  
Возвращаемое значение:

| \- Указатель на интерфейс присоединительной точки [IConjunctivePoint](iconjunctivepoint.html).  
---|---  
  
Примечание:

1\. Метод позволяет создать новый интерфейс присоединительной точки.

2\. После получения нового интерфейса нужно задать параметры и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
