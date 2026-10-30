# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ILofts ](ilofts.html) > [ILofts - методы ](ilofts_methods.html) |  Scroll [ [ [ ](inurbssurfacesbycurvesmeshs.html "К следующему разделу")](ilofts_methods.html "На уровень выше")](ilofts_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilofts.html)

Синтаксис Automation:

LPDISPATCH Add( ksObj3dTypeEnum LoftType );

Синтаксис COM:

HRESULT Add( ksObj3dTypeEnum LoftType, ILoft ** Result );

Возвращаемое значение:

| \- Указатель на интерфейс [ILoft](iloft.html).  
---|---  
  
Входные параметры:

LoftType | \- тип объекта из перечисления [ksObj3dTypeEnum](obj3dtype.html).  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс операции по сечениям.

2\. Допустимыми значениями LoftType являются:

•o3d_bossLoft, o3d_cutLoft для коллекции операций [IModelContainer::Lofts](imodelcontainer_lofts.html),

•o3d_LoftSurface для коллекции поверхностей [ISurfaceContainer::LoftSurfaces](isurfacecontainer_loftsurfaces.html).

3\. После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
