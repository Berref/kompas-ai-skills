# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IBodyRepositions ](ibodyrepositions.html) > [IBodyRepositions - методы ](ibodyrepositions_methods.html) |  Scroll [ [ [ ](ibodyreposition.html "К следующему разделу")](ibodyrepositions_methods.html "На уровень выше")](ibodyrepositions_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibodyrepositions.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( IBodyReposition * * Result );

Возвращаемое значение:

| \- указатель на интерфейс [IBodyReposition](ibodyreposition.html).  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс операции перепозиционирования тела, поверхности.

2\. После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
