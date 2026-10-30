# Part - Компонент, заданный по индексу или по имени

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IParts7 ](iparts7.html) > [IParts7 - свойства ](iparts7_props.html) |  Scroll [ [ [ ](iparts7_methods.html "К следующему разделу")](iparts7_props.html "На уровень выше")](iparts7_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iparts7.html)

Тип данных: указатель на интерфейс [IPart7](ipart7.html)

Синтаксис Automation:

Part = iObject.Part (Index) | Получить свойство ([* ](1.html))  
---|---  
Part = iObject.GetPart (Index) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Part( index, &Part ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | VT_BSTR - имя компонента, VT_I4 - индекс компонента.  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
