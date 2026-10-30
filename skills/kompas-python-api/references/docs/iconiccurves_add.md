# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IConicCurves ](iconiccurves.html) > [IConicCurves - методы ](iconiccurves_methods.html) |  Scroll [ [ [ ](idrawingcontours.html "К следующему разделу")](iconiccurves_methods.html "На уровень выше")](iconiccurves_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconiccurves.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( IConicCurve * * Result );

Возвращаемое значение:

| \- Указатель на интерфейс [IConicCurve](iconiccurve.html).  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс конической кривой.

2\. После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
