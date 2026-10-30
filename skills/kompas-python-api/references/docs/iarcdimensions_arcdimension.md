# ArcDimension - Размер дуги окружности, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Коллекции размеров ](bb2356897.html) > [Интерфейс IArcDimensions ](iarcdimensions.html) > [IArcDimensions - свойства ](iarcdimensions_props.html) |  Scroll [ [ [ ](iarcdimensions_methods.html "К следующему разделу")](iarcdimensions_props.html "На уровень выше")](iarcdimensions_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iarcdimensions.html)

Тип данных: указатель на интерфейс размера дуги окружности [IArcDimension](iarcdimension.html)

Синтаксис Automation:

ArcDimension = iObject.ArcDimension( Index ); | Получить свойство([* ](1.html))  
---|---  
ArcDimension = iObject.GetArcDimension( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ArcDimension( Index, &ArcDimension ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс размера в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс размера.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
