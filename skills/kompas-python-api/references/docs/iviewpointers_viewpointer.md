# ViewPointer - Указатель на стрелку взгляда, заданную по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Коллекции обозначений ](bb3219842.html) > [Интерфейс IViewPointers ](iviewpointers.html) > [IViewPointers - свойства ](iviewpointers_props.html) |  Scroll [ [ [ ](iviewpointers_methods.html "К следующему разделу")](iviewpointers_props.html "На уровень выше")](iviewpointers_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iviewpointers.html)

Тип данных: указатель на интерфейс [IViewPointer](iviewpointer.html)

Синтаксис Automation:

ViewPointer = iObject.ViewPointer( Index ); | Получить свойство([* ](1.html))  
---|---  
ViewPointer = iObject.GetViewPointer( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ViewPointer( Index, &ViewPointer ) | Получить свойство  
---|---  
  
Входные параметры:

Index | \- Индекс узла в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс объекта \- VT_BSTR - имя объекта.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции, reference объекта и имя объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
