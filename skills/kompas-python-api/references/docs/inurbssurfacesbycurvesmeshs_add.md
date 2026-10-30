# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс INurbsSurfacesByCurvesMeshs ](inurbssurfacesbycurvesmeshs.html) > [INurbsSurfacesByCurvesMeshs - методы ](inurbssurfacesbycurvesmeshs_methods.html) |  Scroll [ [ [ ](inurbssurfacebycurvesmesh.html "К следующему разделу")](inurbssurfacesbycurvesmeshs_methods.html "На уровень выше")](inurbssurfacesbycurvesmeshs_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inurbssurfacesbycurvesmeshs.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( INurbsSurfaceByCurvesMesh * * Result );

Возвращаемое значение:

| \- указатель на интерфейс [INurbsSurfaceByCurvesMesh](inurbssurfacebycurvesmesh.html)  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс сплайновой поверхности по сетке кривых.

2\. После получения нового интерфейса нужно задать параметры поверхности и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
