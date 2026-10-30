# Add - Создать новый элемент и добавить его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс ISurfaceSewers ](isurfacesewers.html) > [ISurfaceSewers - методы ](isurfacesewers_methods.html) |  Scroll [ [ [ ](itrimmedsurfaces.html "К следующему разделу")](isurfacesewers_methods.html "На уровень выше")](isurfacesewers_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isurfacesewers.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( ISurfaceSewer ** Result);

Входные параметры:

DimType | \- тип линии-выноски.  
---|---  
  
Типы линий-выносок:

o3d_leader3D | 86 | Линия-выноска 3D  
---|---|---  
o3d_markLeader3D | 87 | Знак маркировки 3D  
o3d_positionLeader3D | 89 | Обозначение позиции 3D  
o3d_brandLeader3D | 90 | Знак клеймения 3D  
  
Возвращаемое значение:

| \- Указатель на интерфейс линии-выноски [IBaseLeader3D](ibaseleader3d.html).  
---|---  
  
Возвращаемое значение:

| \- Указатель на интерфейс присоединительной точки [IConjunctivePointI](iconjunctivepoint.html).  
---|---  
  
Примечание:

1\. Метод позволяет создать новый интерфейс присоединительной точки.

2\. После получения нового интерфейса нужно задать параметры и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
