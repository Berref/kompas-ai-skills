# Add - Создать новый элемент и добавить его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс IConjunctivePoints ](iconjunctivepoints.html) > [IConjunctivePoints - методы ](iconjunctivepoints_methods.html) |  Scroll [ [ [ ](icontrolpoints.html "К следующему разделу")](iconjunctivepoints_methods.html "На уровень выше")](iconjunctivepoints_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconjunctivepoints.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( IConjunctivePoint ** Result );

Возвращаемое значение:

| \- Указатель на интерфейс присоединительной точки [IConjunctivePoint](iconjunctivepoint.html).  
---|---  
  
Примечание:

1\. Метод позволяет создать новый интерфейс присоединительной точки.

2\. После получения нового интерфейса нужно задать параметры и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
