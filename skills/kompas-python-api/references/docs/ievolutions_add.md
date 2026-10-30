# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IEvolutions ](ievolutions.html) > [IEvolutions - методы ](ievolutions_methods.html) |  Scroll [ [ [ ](iextensioncurves.html "К следующему разделу")](ievolutions_methods.html "На уровень выше")](ievolutions_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ievolutions.html)

Синтаксис Automation:

LPDISPATCH Add( ksObj3dTypeEnum EvolutionType );

Синтаксис COM:

HRESULT Add( ksObj3dTypeEnum EvolutionType, IEvolution ** Result );

Возвращаемое значение:

| \- указатель на интерфейс [IEvolution](ievolution.html).  
---|---  
  
Входные параметры:

EvolutionType | \- тип объекта из перечисления [ksObj3dTypeEnum](obj3dtype.html).  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс кинематической операции.

2\. Допустимыми значениями EvolutionType являются:

•o3d_bossEvolution, o3d_cutEvolution для коллекции операций [IModelContainer::Evolutions](imodelcontainer_evolutions.html)

•o3d_EvolutionSurface для коллекции поверхностей [ISurfaceContainer::EvolutionSurfaces](isurfacecontainer_evolutionsurfaces.html).

3\. После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
