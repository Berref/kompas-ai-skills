# DiametralDimension - Диаметральный размер, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Коллекции размеров ](bb2356897.html) > [Интерфейс IDiametralDimensions ](idiametraldimensions.html) > [IDiametralDimensions - свойства ](idiametraldimensions_props.html) |  Scroll [ [ [ ](idiametraldimensions_methods.html "К следующему разделу")](idiametraldimensions_props.html "На уровень выше")](idiametraldimensions_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idiametraldimensions.html)

Тип данных: указатель на интерфейс диаметрального размера [IDiametralDimension](idiametraldimension.html)

Синтаксис Automation:

DiametralDimension = iObject.DiametralDimension( Index ); | Получить свойство([* ](1.html))  
---|---  
DiametralDimension = iObject.GetDiametralDimension( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DiametralDimension( Index, &DiametralDimension ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс размера в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс узла.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
