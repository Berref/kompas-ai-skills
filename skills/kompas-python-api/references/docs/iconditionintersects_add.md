# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Коллекции обозначений ](bb3219842.html) > [Интерфейс IConditionIntersects ](iconditionintersects.html) > [IConditionIntersects - методы ](iconditionintersects_methods.html) |  Scroll [ [ [ ](ilinearscentries.html "К следующему разделу")](iconditionintersects_methods.html "На уровень выше")](iconditionintersects_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconditionintersects.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( IConditionIntersect * * Result );

Возвращаемое значение:

| \- Указатель на интерфейс [IConditionIntersect](iconditionintersect.html).  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс условного пересечения.

2\. После получения нового интерфейса нужно задать параметры и вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
