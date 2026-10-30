# Multiline - Мультилиния, заданная по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IMultilines ](imultilines.html) > [IMultilines - свойства ](imultilines_props.html) |  Scroll [ [ [ ](imultilines_methods.html "К следующему разделу")](imultilines_props.html "На уровень выше")](imultilines_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultilines.html)

Тип данных: указатель на интерфейс мультилинии [IMultiline](imultiline.html)

Синтаксис Automation:

Multiline = iObject.Multiline( Index ); | Получить свойство([* ](1.html))  
---|---  
Multiline = iObject.GetMultiline( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Multiline( Index, &Multiline ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс узла в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс линии разреза/сечения.  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

Подразделы:

(отсутствуют)
